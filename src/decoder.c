#include "headers/iutils.h"
#include "headers/decoder.h"
#include "tables/itable.h"
#include <string.h>

#define POST_INC(x)(x++)
#define PRE_INC(x)(++x)

/* modrm helpers */
#define MODRM_MOD(field) ((field & 0xC0) >> 6)
#define MODRM_REG(field) ((field & 0x38) >> 3)
#define MODRM_RM(field)  ((field & 0x07))


/*
 * initializes the struct
 */
Dinstruction *init_instruction() {
  Dinstruction *decoded = (Dinstruction *)calloc(1, sizeof(Dinstruction));
  return decoded;
}

/*
 * zeroes the struct, but preserves the mode
 */
void zero_instruction(Dinstruction *decoded) {
  // save the mode in order to restore it after zeroing the struct
  uint8_t mode = decoded->mode;
  memset(decoded, 0, sizeof(Dinstruction));
  decoded->mode = mode;
}

/*
 * frees the struct
 */
void free_instrucion(Dinstruction *decoded) { free(decoded); }

/*
 * decodes instruction that contains modrm
 */
static inline bool decode_modrm(Dinstruction *decoded, uchar8_t *i_ptr) {

  if (HAS_STATUS(decoded->status, STATUS_EXTENDED) &&
      !itable_modrm_reg_extended[decoded->op1])
    /* 
     * if extended instruction is not in the table 
     */
    return false;
  else if (!itable_modrm_reg[decoded->op1])
    /*
     * if regular instruction is not in the table
     */ 
    return false;

  /* decode it otherwise! */
  decoded->instr_type = INSTR_MODRM;
  decoded->modrm.size = BYTE_LEN;
  decoded->modrm.field = *i_ptr;
  decoded->modrm.mod = MODRM_MOD(decoded->modrm.field); 
  decoded->modrm.reg = MODRM_REG(decoded->modrm.field); 
  decoded->modrm.rm  = MODRM_RM(decoded->modrm.field); 
  return true;
}

/*
 * decodes zero-type instruction
 */
static inline bool decode_zero(Dinstruction *decoded){

  if (HAS_STATUS(decoded->status, STATUS_EXTENDED) &&
      !itable_zero_extended[decoded->op1])
    /* if extended instruction is not in the table */
    return false;

  else if (!itable_zero_reg[decoded->op1])
    /* if regular instruction is not in the table */
    return false;

  /* otherwise return true and set operand capacity */
  decoded->instr_type = INSTR_ZERO;
  set_operand_capacity(decoded);
  return true;
}

/*
 * decodes other-type instruction
 */
static inline bool decode_other(Dinstruction *decoded){

  if (HAS_STATUS(decoded->status, STATUS_EXTENDED) &&
      !itable_other_extended[decoded->op1])
    return false;

  else if (!itable_other_reg[decoded->op1])
    return false;

  decoded->instr_type = INSTR_OTHER;
  set_operand_size(decoded);
  if (decoded->operands.size == 0)
    /* if for some reason it is still zero ? */
    return false;

  return true;
}

/*
 * decodes 32-bit instruction
 */
static bool decode32(Dinstruction *decoded, uchar8_t *instruction) {
  // todo: add valid prefix check
  // ex: 66 0f 74 04 00 -> is a valid instruction, while f3 0f 74 04 00 is not

  // https://sparksandflames.com/files/x86InstructionChart.html
  uchar8_t *i_ptr = instruction;
  while (instr_has_prefix(*i_ptr)) {
    decoded->status |= STATUS_PREFIX;
    if (*i_ptr == PREFIX_OPSIZE_OVERRIDE)
      decoded->status |= STATUS_OPSIZE_OVERRIDE;

    decoded->prefixes.prefix[decoded->prefixes.size] = *i_ptr;
    memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, BYTE_LEN);
    decoded->buffer.size += BYTE_LEN;
    decoded->prefixes.size = decoded->buffer.size;
    POST_INC(i_ptr);
  }

  // 00-3f: arith-logical operations: add, adc,sub,sbb,and...
  // 40-7f: inc/push/pop, jcc,...
  // 80-bf: data movement: mov,lods,stos,...
  // c0-ff: misc and escape groups

  if (instr_has_extended_opcode(*i_ptr)) {
    // 0x0f (two byte opcode is gonna be decoded here)
    decoded->status |= STATUS_EXTENDED;
    memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, BYTE_LEN);
    decoded->buffer.size += BYTE_LEN;
    POST_INC(i_ptr);

    if (instr_has_secondary_opcode(*i_ptr)) {
      // if it has secondary opcode
      decoded->op1 = *i_ptr;
      memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, BYTE_LEN);
      decoded->buffer.size += BYTE_LEN;

      POST_INC(i_ptr);
      decoded->op2 = *i_ptr;
      memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, BYTE_LEN);
      decoded->buffer.size += BYTE_LEN;

      POST_INC(i_ptr);

      if (!decode_modrm(decoded, i_ptr))
        return false;

      decoded->buffer.bytes[decoded->buffer.size] = *i_ptr;
      decoded->buffer.size += decoded->modrm.size;
      i_ptr += decoded->modrm.size;

      if(instr_has_sib(decoded)){
        decoded->status |= STATUS_SIB; 
        set_sib(decoded, i_ptr);
        decoded->buffer.bytes[decoded->buffer.size] = *i_ptr;
        decoded->buffer.size += decoded->sib.size;
        /* sib field */
        i_ptr += decoded->sib.size;
      }

      if(instr_has_displacement(decoded)){
        decoded->status |= STATUS_DISP;
        set_displacement(decoded);
        memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, decoded->displacement.size);
        memcpy(&decoded->displacement.field, i_ptr, decoded->displacement.size);
        decoded->buffer.size += decoded->displacement.size;
        /* displacement field */
        i_ptr += decoded->displacement.size;
      }

      if (instr_has_immediate_operand(decoded)){
        set_operand_size(decoded);
        if (decoded->operands.size == 0) return false;

        memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, decoded->operands.size);
        memcpy(&decoded->imm, i_ptr, decoded->operands.size);
        decoded->buffer.size += decoded->operands.size;
      }

      set_operand_capacity(decoded);

      return true;
    } else if (*i_ptr == 0x01) {
      decoded->op1 = *i_ptr;
      POST_INC(i_ptr);
      // actually this block of code is a whole mess, because it is not aware of
      // sgdt, sidt, lgdt, lidt, smsw, lmsw and invlpg instructions. да похуй
      // уже?
      switch (*i_ptr) {
      // vmcall, vmlaunch, vmresume, vmxoff, monitor, mwait, xgetbv, xsetbv and
      // rdtscp
      case 0xC1:
      case 0xC2:
      case 0xC3:
      case 0xC4:
      case 0xC8:
      case 0xC9:
      case 0xD0:
      case 0xD1:
      case 0xF9:
        decoded->op2 = *i_ptr;
        memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, WORD_LEN);
        decoded->buffer.size += WORD_LEN;
        set_operand_capacity(decoded);
        return true;
      default:
        return false;
      }
    } else {
      decoded->op1 = *i_ptr;
      memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, BYTE_LEN);
      decoded->buffer.size += BYTE_LEN;

      if (decode_zero(decoded)) 
        return true; 

      if (decode_other(decoded)) {

        POST_INC(i_ptr);
        if (instr_has_immediate_operand(decoded)) {
          decoded->status |= STATUS_IMMEDIATE_OPERAND;
          memcpy(&decoded->imm, i_ptr, decoded->operands.size);
        } else if (instr_has_rel_offset_operand(decoded)) {
          decoded->status |= STATUS_REL_OFFSET_OPERAND;
          memcpy(&decoded->rel, i_ptr, decoded->operands.size);
        } else if (instr_has_direct_addr_operand(decoded)) {
          decoded->status |= STATUS_DIRECT_ADDR_OPERAND;
          memcpy(&decoded->dir, i_ptr, decoded->operands.size);
        } else
          return false;

        memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, decoded->operands.size);
        decoded->buffer.size += decoded->operands.size;
        
        set_operand_capacity(decoded);

        return true;
      }

      if (decode_modrm(decoded, PRE_INC(i_ptr))) {

        if (instr_has_opcode_extension(decoded) &&
            instr_has_valid_extension(decoded)) {
          decoded->status |= STATUS_OPCODE_EXTENSION;
          size_t op_size = get_opcode_extension_operand_size(decoded);
          memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, op_size);
          decoded->buffer.size += op_size;
        }

        decoded->buffer.bytes[decoded->buffer.size] = *i_ptr;
        decoded->buffer.size += decoded->modrm.size;
        i_ptr += decoded->modrm.size;

        if (instr_has_sib(decoded)) {
          decoded->status |= STATUS_SIB;
          set_sib(decoded, i_ptr);
          decoded->buffer.bytes[decoded->buffer.size] = *i_ptr;
          decoded->buffer.size += decoded->sib.size;
          /* sib field */
          i_ptr += decoded->sib.size;
        }

        if (instr_has_displacement(decoded)) {
          decoded->status |= STATUS_DISP;
          set_displacement(decoded);
          memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr,
                 decoded->displacement.size);
          memcpy(&decoded->displacement.field, i_ptr, decoded->displacement.size);
          decoded->buffer.size += decoded->displacement.size;
          /* displacement field */
          i_ptr += decoded->displacement.size;
        }

        if (instr_has_immediate_operand(decoded)) {
          set_operand_size(decoded);
          if (decoded->operands.size == 0)
            return false;

          memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr,
                 decoded->operands.size);
          memcpy(&decoded->imm, i_ptr, decoded->operands.size);
          decoded->buffer.size += decoded->operands.size;
        }
        set_operand_capacity(decoded);
        return true;
      }

      return false;
    }
  } else { 
    // one byte opcode is gonna be here

    decoded->op1 = *i_ptr;
    memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, BYTE_LEN);
    decoded->buffer.size += BYTE_LEN;

    if (decode_zero(decoded)) 
      return true; 

    if (decode_other(decoded)) {
      POST_INC(i_ptr);

      if (instr_has_immediate_operand(decoded)) {
        decoded->status |= STATUS_IMMEDIATE_OPERAND;
        memcpy(&decoded->imm, i_ptr, decoded->operands.size);
      } else if (instr_has_rel_offset_operand(decoded)) {
        decoded->status |= STATUS_REL_OFFSET_OPERAND;
        memcpy(&decoded->rel, i_ptr, decoded->operands.size);
      } else if (instr_has_direct_addr_operand(decoded)) {
        decoded->status |= STATUS_DIRECT_ADDR_OPERAND;
        memcpy(&decoded->dir, i_ptr, decoded->operands.size);
      } else
        return false;

      memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, decoded->operands.size);
      decoded->buffer.size += decoded->operands.size;
      set_operand_capacity(decoded);

      return true;
    }

    if (decode_modrm(decoded, PRE_INC(i_ptr))) {

      if (instr_has_opcode_extension(decoded) &&
          instr_has_valid_extension(decoded)) {
        decoded->status |= STATUS_OPCODE_EXTENSION;
        size_t op_size = get_opcode_extension_operand_size(decoded);
        memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, op_size);
        decoded->buffer.size += op_size;
      }

      decoded->buffer.bytes[decoded->buffer.size] = *i_ptr;
      decoded->buffer.size += decoded->modrm.size;
      i_ptr += decoded->modrm.size;

      if (instr_has_sib(decoded)) {
        decoded->status |= STATUS_SIB;
        set_sib(decoded, i_ptr);
        decoded->buffer.bytes[decoded->buffer.size] = *i_ptr;
        decoded->buffer.size += decoded->sib.size;
        /* sib field */
        i_ptr += decoded->sib.size;
      }

      if (instr_has_displacement(decoded)) {
        decoded->status |= STATUS_DISP;
        set_displacement(decoded);
        memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr,
               decoded->displacement.size);
        memcpy(&decoded->displacement.field, i_ptr, decoded->displacement.size);
        decoded->buffer.size += decoded->displacement.size;
        /* displacement field */
        i_ptr += decoded->displacement.size;
      }

      if (instr_has_immediate_operand(decoded)) {
        set_operand_size(decoded);
        if (decoded->operands.size == 0)
          return false;

        memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr,
               decoded->operands.size);
        memcpy(&decoded->imm, i_ptr, decoded->operands.size);
        decoded->buffer.size += decoded->operands.size;
      }
      set_operand_capacity(decoded);
      return true;
    }
  }

  return false;
}

/*
 * decodes 64-bit instruction
 */
static bool decode64(Dinstruction *decoded, uchar8_t *instruction) {
  //     in 64-bit mode, instruction formats do not change. bits needed to
  //     define fields in the 64-bit context are provided by the
  // addition of rex prefixes.
  uchar8_t *i_ptr = instruction;

  while (instr_has_prefix(*i_ptr)) {
    decoded->status |= STATUS_PREFIX;
    if (*i_ptr == PREFIX_OPSIZE_OVERRIDE)
      decoded->status |= STATUS_OPSIZE_OVERRIDE;

    decoded->prefixes.prefix[decoded->prefixes.size] = *i_ptr;
    memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, BYTE_LEN);
    decoded->buffer.size += BYTE_LEN;
    decoded->prefixes.size = decoded->buffer.size;
    POST_INC(i_ptr);
  }

  if (instr_has_rex(*i_ptr)) {
    decoded->status |= STATUS_REX;
    memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, BYTE_LEN);
    decoded->buffer.size += BYTE_LEN;
    decoded->rex.field = *i_ptr;
    decoded->rex.w = (decoded->rex.field & 0x08) >> 3;
    decoded->rex.r = (decoded->rex.field & 0x04) >> 2;
    decoded->rex.x = (decoded->rex.field & 0x02) >> 1;
    decoded->rex.b = (decoded->rex.field & 0x01);
    POST_INC(i_ptr);
  }

  if (instr_has_extended_opcode(*i_ptr)) {
    // 0x0f (two byte opcode is gonna be decoded here)
    decoded->status |= STATUS_EXTENDED;
    memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, BYTE_LEN);
    decoded->buffer.size += BYTE_LEN;
    POST_INC(i_ptr);
    if (instr_has_secondary_opcode(*i_ptr)) {
      // if it has secondary opcode
      decoded->op1 = *i_ptr;
      memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, BYTE_LEN);
      decoded->buffer.size += BYTE_LEN;

      POST_INC(i_ptr);
      decoded->op2 = *i_ptr;
      memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, BYTE_LEN);
      decoded->buffer.size += BYTE_LEN;

      POST_INC(i_ptr);

      if (!decode_modrm(decoded, i_ptr))
        return false;

      decoded->buffer.bytes[decoded->buffer.size] = *i_ptr;
      decoded->buffer.size += decoded->modrm.size;
      i_ptr += decoded->modrm.size;

      if (instr_has_sib(decoded)) {
        decoded->status |= STATUS_SIB;
        set_sib(decoded, i_ptr);
        decoded->buffer.bytes[decoded->buffer.size] = *i_ptr;
        decoded->buffer.size += decoded->sib.size;
        /* sib field */
        i_ptr += decoded->sib.size;
      }

      if (instr_has_displacement(decoded)) {
        decoded->status |= STATUS_DISP;
        set_displacement(decoded);
        memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr,
               decoded->displacement.size);
        memcpy(&decoded->displacement.field, i_ptr, decoded->displacement.size);
        decoded->buffer.size += decoded->displacement.size;
        /* displacement field */
        i_ptr += decoded->displacement.size;
      }

      if (instr_has_immediate_operand(decoded)) {
        set_operand_size(decoded);
        if (decoded->operands.size == 0)
          return false;

        memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr,
               decoded->operands.size);
        memcpy(&decoded->imm, i_ptr, decoded->operands.size);
        decoded->buffer.size += decoded->operands.size;
      }
      set_operand_capacity(decoded);

      return true;
    } else if (*i_ptr == 0x01) {
      decoded->op1 = *i_ptr;
      POST_INC(i_ptr);
      switch (*i_ptr) {
      case 0xC1:
      case 0xC2:
      case 0xC3:
      case 0xC4:
      case 0xC8:
      case 0xC9:
      case 0xD0:
      case 0xD1:
      case 0xF9:
        decoded->op2 = *i_ptr;
        memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, WORD_LEN);
        decoded->buffer.size += WORD_LEN;
        set_operand_capacity(decoded);
        return true;
      default:
        return false;
      }
    } else {
      decoded->op1 = *i_ptr;
      memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, BYTE_LEN);
      decoded->buffer.size += BYTE_LEN;

      if (decode_zero(decoded)) 
        return true;

      if (decode_other(decoded)) {
        memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, decoded->operands.size);
        decoded->buffer.size += decoded->operands.size;
        set_operand_capacity(decoded);
        return true;
      }

      if (decode_modrm(decoded, PRE_INC(i_ptr))) {

        if (instr_has_opcode_extension(decoded) &&
            instr_has_valid_extension(decoded)) {
          decoded->status |= STATUS_OPCODE_EXTENSION;
          size_t op_size = get_opcode_extension_operand_size(decoded);
          memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, op_size);
          decoded->buffer.size += op_size;
        }

        decoded->buffer.bytes[decoded->buffer.size] = *i_ptr;
        decoded->buffer.size += decoded->modrm.size;
        i_ptr += decoded->modrm.size;

        if (instr_has_sib(decoded)) {
          decoded->status |= STATUS_SIB;
          set_sib(decoded, i_ptr);
          decoded->buffer.bytes[decoded->buffer.size] = *i_ptr;
          decoded->buffer.size += decoded->sib.size;
          /* sib field */
          i_ptr += decoded->sib.size;
        }

        if (instr_has_displacement(decoded)) {
          decoded->status |= STATUS_DISP;
          set_displacement(decoded);
          memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr,
                 decoded->displacement.size);
          memcpy(&decoded->displacement.field, i_ptr, decoded->displacement.size);
          decoded->buffer.size += decoded->displacement.size;
          /* displacement field */
          i_ptr += decoded->displacement.size;
        }

        if (instr_has_immediate_operand(decoded)) {
          set_operand_size(decoded);
          if (decoded->operands.size == 0)
            return false;

          memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr,
                 decoded->operands.size);
          memcpy(&decoded->imm, i_ptr, decoded->operands.size);
          decoded->buffer.size += decoded->operands.size;
        }
        set_operand_capacity(decoded);
        return true;
      }
    }
    return false;
  }

  if (instr_has_vex(*i_ptr)) {
    decoded->status |= STATUS_VEX;
    size_t vex_size = get_vex_size(*i_ptr);
    memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, vex_size);
    decoded->buffer.size += vex_size;
    POST_INC(i_ptr);
  }

  decoded->op1 = *i_ptr;
  memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, BYTE_LEN);
  decoded->buffer.size += BYTE_LEN;

  if (decode_zero(decoded)) 
    return true;

  if (decode_other(decoded)) {
    memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, decoded->operands.size);
    decoded->buffer.size += decoded->operands.size;
    set_operand_capacity(decoded);
    return true;
  }

  if (decode_modrm(decoded, PRE_INC(i_ptr))) {

    if (instr_has_opcode_extension(decoded) &&
        instr_has_valid_extension(decoded)) {
      decoded->status |= STATUS_OPCODE_EXTENSION;
      size_t op_size = get_opcode_extension_operand_size(decoded);
      memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr, op_size);
      decoded->buffer.size += op_size;
    }

    decoded->buffer.bytes[decoded->buffer.size] = *i_ptr;
    decoded->buffer.size += decoded->modrm.size;
    i_ptr += decoded->modrm.size;

    if (instr_has_sib(decoded)) {
      decoded->status |= STATUS_SIB;
      set_sib(decoded, i_ptr);
      decoded->buffer.bytes[decoded->buffer.size] = *i_ptr;
      decoded->buffer.size += decoded->sib.size;
      /* sib field */
      i_ptr += decoded->sib.size;
    }

    if (instr_has_displacement(decoded)) {
      decoded->status |= STATUS_DISP;
      set_displacement(decoded);
      memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr,
             decoded->displacement.size);
      memcpy(&decoded->displacement.field, i_ptr, decoded->displacement.size);
      decoded->buffer.size += decoded->displacement.size;
      /* displacement field */
      i_ptr += decoded->displacement.size;
    }

    if (instr_has_immediate_operand(decoded)) {
      set_operand_size(decoded);
      if (decoded->operands.size == 0)
        return false;

      memcpy(decoded->buffer.bytes + decoded->buffer.size, i_ptr,
             decoded->operands.size);
      memcpy(&decoded->imm, i_ptr, decoded->operands.size);
      decoded->buffer.size += decoded->operands.size;
    }
    set_operand_capacity(decoded);
    return true;
  }

  return false;
}

bool decode(Dinstruction *decoded, uchar8_t *instruction) {
  switch (decoded->mode) {
  case 32:
    return decode32(decoded, instruction);
  case 64:
    return decode64(decoded, instruction);
  default:
    return false;
  }
}
