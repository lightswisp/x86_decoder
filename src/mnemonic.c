#include "headers/mnemonic.h"
#include <stdio.h>
#include <string.h>

/*
 * Sets decoded->mnemonic.str field
 */
bool set_mnemonic32(Dinstruction *decoded, uchar8_t instruction) {
  if (HAS_STATUS(decoded->status, STATUS_EXTENDED)) {
    if (HAS_STATUS(decoded->status, STATUS_OPCODE_EXTENSION)) {
      // extended and has extension
      // (extended_opcode_with_extensions_table)
      if (decoded->modrm.mod == 0x03) { // register addressing
        switch (decoded->prefixes.prefix[0]) {
        case 0x66:
          // handle extended with
          // extension + mod 11B and 0x66
          // prefix
          char *m_66 = extd_ext_11b_66[instruction][decoded->modrm.reg];
          size_t m_len = strlen(m_66);
          memcpy(decoded->mnemonic.str, m_66, m_len);
          return true;
        case 0xF3:
          // handle extended with
          // extension + mod 11B and 0xF3
          // prefix
          char *m_f3 = extd_ext_11b_f3[instruction][decoded->modrm.reg];
          memcpy(decoded->mnemonic.str, m_f3, strlen(m_f3));
          return true;
        }
        // no prefix here (but with modrm.mod == 11B)
        if (instruction == 0x01) {
          // vmcall, vmlaunch ...
          char *m = extd_ext_11b_rm[decoded->modrm.reg][decoded->modrm.rm];
          memcpy(decoded->mnemonic.str, m, strlen(m));
          return true;
        } else {
          char *m = extd_ext_11b[instruction][decoded->modrm.reg];
          memcpy(decoded->mnemonic.str, m, strlen(m));

          return true;
        }
      } else {
        // memory addressing
        switch (decoded->prefixes.prefix[0]) {
        case 0x66:
          // handle extended with
          // extension + mod mem and 0x66
          // prefix
          char *m_66 = extd_ext_mem_66[instruction][decoded->modrm.reg];
          memcpy(decoded->mnemonic.str, m_66, strlen(m_66));
          return true;
        case 0xF3:
          // handle extended with
          // extension + mod mem and 0xF3
          // prefix
          char *m_f3 = extd_ext_mem_f3[instruction][decoded->modrm.reg];
          memcpy(decoded->mnemonic.str, m_f3, strlen(m_f3));
          return true;
        }

        // no prefix here (but with modrm.mod == mem)
        char *m = extd_ext_mem[instruction][decoded->modrm.reg];
        memcpy(decoded->mnemonic.str, m, strlen(m));
        return true;
      }

    } else {
      // just extended (extended_opcode_table)
      char *extd_m = extd[instruction];
      memcpy(decoded->mnemonic.str, extd_m, strlen(extd_m));
      return true;
    }
  } else {
    if (HAS_STATUS(decoded->status, STATUS_OPCODE_EXTENSION)) {
      printf("regular! but with extension\n");
      // has extension (regular_opcode_with_extensions_table)
      if (decoded->modrm.mod == 0x03) { // register addressing
        char *m = reg_ext_11b[instruction][decoded->modrm.reg];
        memcpy(decoded->mnemonic.str, m, strlen(m));
        return true;
      } else { // memory addressing
        char *m = reg_ext_mem[instruction][decoded->modrm.reg];
        memcpy(decoded->mnemonic.str, m, strlen(m));
        return true;
      }

    } else {
      // regular opcode (regular_opcode_table)
      printf("regular!\n");
      char *m = reg[instruction];
      size_t m_len = strlen(m);
      memcpy(decoded->mnemonic.str, m, m_len);
      return true;
    }
  }
  return false;
}

bool set_mnemonic64(Dinstruction *decoded, uchar8_t instruction) {
  return false;
}
bool set_mnemonic(Dinstruction *decoded, uchar8_t instruction) {
  switch (decoded->mode) {
  case 32:
    return set_mnemonic32(decoded, instruction);
  case 64:
    return set_mnemonic64(decoded, instruction);
  }
}

