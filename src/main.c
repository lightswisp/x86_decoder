#include "headers/decoder.h"
#include "headers/dump.h"
#include <stdio.h>

#define INSTRUCTION_LIMIT 51 

int main(void) {
  // todo: add valid prefix check
  // ex: 66 0f 74 04 00 -> is a valid instruction, while f3 0f 74 04 00 is not
  uint64_t offset, instructions;
  uchar8_t instruction[] = {
      0x55, 0x89, 0xE5, 0x83, 0xEC, 0x18, 0xE8, 0x3B, 0x01, 0x00, 0x00, 0x05,
      0x98, 0x2D, 0x00, 0x00, 0xC7, 0x45, 0xF4, 0x00, 0x00, 0x00, 0x00, 0xEB,
      0x76, 0xC7, 0x45, 0xF0, 0x00, 0x00, 0x00, 0x00, 0xEB, 0x5B, 0x8B, 0x45,
      0xF0, 0x8D, 0x14, 0x85, 0x00, 0x00, 0x00, 0x00, 0x8B, 0x45, 0x08, 0x01,
      0xD0, 0x8B, 0x10, 0x8B, 0x45, 0xF0, 0x83, 0xC0, 0x01, 0x8D, 0x0C, 0x85,
      0x00, 0x00, 0x00, 0x00, 0x8B, 0x45, 0x08, 0x01, 0xC8, 0x8B, 0x00, 0x39,
      0xC2, 0x7E, 0x2E, 0x8B, 0x45, 0xF0, 0x83, 0xC0, 0x01, 0x8D, 0x14, 0x85,
      0x00, 0x00, 0x00, 0x00, 0x8B, 0x45, 0x08, 0x01, 0xC2, 0x8B, 0x45, 0xF0,
      0x8D, 0x0C, 0x85, 0x00, 0x00, 0x00, 0x00, 0x8B, 0x45, 0x08, 0x01, 0xC8,
      0x83, 0xEC, 0x08, 0x52, 0x50, 0xE8, 0x39, 0xFF, 0xFF, 0xFF, 0x83, 0xC4,
      0x10, 0x83, 0x45, 0xF0, 0x01, 0x8B, 0x45, 0x0C, 0x2B, 0x45, 0xF4, 0x83,
      0xE8, 0x01, 0x39, 0x45, 0xF0, 0x7C, 0x97, 0x83, 0x45, 0xF4, 0x01, 0x8B,
      0x45, 0x0C, 0x83, 0xE8, 0x01, 0x39, 0x45, 0xF4, 0x0F, 0x8C, 0x7B, 0xFF,
      0xFF, 0xFF, 0x90, 0x90, 0xC9, 0xC3};
  Dinstruction *decoded = pedix_init_instruction();
  decoded->mode = MODE_32;

  /* curr offset */
  offset = 0;
  /* instruction counter */
  instructions = 0;

  while (instructions < INSTRUCTION_LIMIT) {
   pedix_decode(decoded, instruction + offset);

#ifdef DEBUG
    pedix_dump_instruction(decoded->instruction);
#endif
    /* if everything went well */
    pedix_print_instruction(decoded, offset);
    /* eat bytes */
    offset += decoded->buffer.size;
    /* go to the next instruction */
    instructions++;
    /* zero the struct */
    pedix_zero_instruction(decoded);
  }

  pedix_free_instrucion(decoded);
  return 0;
}

