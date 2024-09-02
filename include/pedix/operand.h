#pragma once
#include "decoder.h"

void pedix_set_operands(decoded_instruction_t *decoded);
void pedix_merge_operands(decoded_instruction_t *decoded);

extern const char *modrm_reg8[]; 
extern const char *modrm_reg16[];
extern const char *modrm_reg32[];

/* ib or imm8 */
#define OPERAND_BYTE "0x%02x"
/* iw ic iv or imm16 */
#define OPERAND_WORD "0x%04x"
/* iv id or imm32 */
#define OPERAND_DWORD "0x%08x"
/* ap 32/48 bit pointer */
#define OPERAND_48 "0x%012x"
/* when register addressing (mod field = 3) */
#define REG_TO_REG "%.24s,%.24s"
#define MEM_TO_REG "%.24s,%.24s"
#define REG_TO_MEM "%.24s,%.24s" 
#define SIGN "%c"
#define SINGLE_OPERAND "%s"
#define REGISTER "%s"
#define SCALE "%d"
#define SEGMENT "%s"
#define ADDR_PTR "%s"

#define FMT_MOFFS SEGMENT"["OPERAND_DWORD"]" 

// put the BYTE PTR, WORD PTR or DWORD PTR inside the decoded->ptr_text before set_operand_by_??_size 
// it will be just easier to put everything together
// also, inside set_operand_by??_size, we should add the second argument (address_size)
// like this -> set_operand_by??_size(uint8_t operand_size, uint8_t address_size)
// then choose the right FMT according to this info

#define FMT_DISPLACEMENT_ONLY_MODE "DWORD PTR " SEGMENT "[" OPERAND_DWORD "]"

#define FMT_INDIRECT_ADDRESSING_OP ADDR_PTR " " SEGMENT "[" REGISTER "]"
#define FMT_SIB_FOUR_BYTE_NO_DISP_ADDRESSING_OP                               \
  ADDR_PTR " " SEGMENT "[" REGISTER "+" REGISTER "*" SCALE "]"
#define FMT_SIB_FOUR_BYTE_DISP_NO_REG_ADDRESSING_OP                           \
  ADDR_PTR " " SEGMENT "[" REGISTER "*" SCALE SIGN OPERAND_DWORD "]"
#define FMT_ONE_BYTE_DISP_ADDRESSING_OP                                       \
  ADDR_PTR " " SEGMENT "[" REGISTER SIGN OPERAND_BYTE "]"
#define FMT_SIB_ONE_BYTE_DISP_ADDRESSING_OP                                   \
  ADDR_PTR " " SEGMENT "[" REGISTER "+" REGISTER "*" SCALE SIGN OPERAND_BYTE "]"
#define FMT_SIB_ONE_BYTE_DISP_NO_SCALE_ADDRESSING_OP                          \
  ADDR_PTR " " SEGMENT "[" REGISTER SIGN OPERAND_BYTE "]"
#define FMT_SIB_FOUR_BYTE_DISP_NO_SCALE_ADDRESSING_OP                         \
  ADDR_PTR " " SEGMENT "[" REGISTER SIGN OPERAND_DWORD "]"
#define FMT_SIB_FOUR_BYTE_NO_DISP_NO_SCALE_ADDRESSING_OP                      \
  ADDR_PTR " " SEGMENT "[" REGISTER "]"
#define FMT_FOUR_BYTE_DISP_ADDRESSING_OP                                      \
  ADDR_PTR " " SEGMENT "[" REGISTER SIGN OPERAND_DWORD "]"
#define FMT_SIB_FOUR_BYTE_DISP_ADDRESSING_OP                                  \
  ADDR_PTR " " SEGMENT "[" REGISTER "+" REGISTER "*" SCALE SIGN OPERAND_DWORD "]"
