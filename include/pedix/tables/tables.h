/* (tables.h) auto generated using gen.rb 
 * time: 2024-10-05 04:16:52 -0400
 */

#pragma once
#include <stdbool.h>
#include <stdint.h>
#include "instructions.h"

instruction_container_t regular_table_32[0x100] = {
  [0x0] = { .size = 1, .instructions = (instruction_t*)&REGULAR_ADD_0 },
  [0x1] = { .size = 1, .instructions = (instruction_t*)&REGULAR_ADD_1 },
  [0x2] = { .size = 1, .instructions = (instruction_t*)&REGULAR_ADD_2 },
  [0x3] = { .size = 1, .instructions = (instruction_t*)&REGULAR_ADD_3 },
  [0x4] = { .size = 1, .instructions = (instruction_t*)&REGULAR_ADD_4 },
  [0x5] = { .size = 1, .instructions = (instruction_t*)&REGULAR_ADD_5 },
  [0x6] = { .size = 1, .instructions = (instruction_t*)&REGULAR_PUSH_6 },
  [0x7] = { .size = 1, .instructions = (instruction_t*)&REGULAR_POP_7 },
  [0x8] = { .size = 1, .instructions = (instruction_t*)&REGULAR_OR_8 },
  [0x9] = { .size = 1, .instructions = (instruction_t*)&REGULAR_OR_9 },
  [0xa] = { .size = 1, .instructions = (instruction_t*)&REGULAR_OR_10 },
  [0xb] = { .size = 1, .instructions = (instruction_t*)&REGULAR_OR_11 },
  [0xc] = { .size = 1, .instructions = (instruction_t*)&REGULAR_OR_12 },
  [0xd] = { .size = 1, .instructions = (instruction_t*)&REGULAR_OR_13 },
  [0xe] = { .size = 1, .instructions = (instruction_t*)&REGULAR_PUSH_14 },
  [0x10] = { .size = 1, .instructions = (instruction_t*)&REGULAR_ADC_16 },
  [0x11] = { .size = 1, .instructions = (instruction_t*)&REGULAR_ADC_17 },
  [0x12] = { .size = 1, .instructions = (instruction_t*)&REGULAR_ADC_18 },
  [0x13] = { .size = 1, .instructions = (instruction_t*)&REGULAR_ADC_19 },
  [0x14] = { .size = 1, .instructions = (instruction_t*)&REGULAR_ADC_20 },
  [0x15] = { .size = 1, .instructions = (instruction_t*)&REGULAR_ADC_21 },
  [0x16] = { .size = 1, .instructions = (instruction_t*)&REGULAR_PUSH_22 },
  [0x17] = { .size = 1, .instructions = (instruction_t*)&REGULAR_POP_23 },
  [0x18] = { .size = 1, .instructions = (instruction_t*)&REGULAR_SBB_24 },
  [0x19] = { .size = 1, .instructions = (instruction_t*)&REGULAR_SBB_25 },
  [0x1a] = { .size = 1, .instructions = (instruction_t*)&REGULAR_SBB_26 },
  [0x1b] = { .size = 1, .instructions = (instruction_t*)&REGULAR_SBB_27 },
  [0x1c] = { .size = 1, .instructions = (instruction_t*)&REGULAR_SBB_28 },
  [0x1d] = { .size = 1, .instructions = (instruction_t*)&REGULAR_SBB_29 },
  [0x1e] = { .size = 1, .instructions = (instruction_t*)&REGULAR_PUSH_30 },
  [0x1f] = { .size = 1, .instructions = (instruction_t*)&REGULAR_POP_31 },
  [0x20] = { .size = 1, .instructions = (instruction_t*)&REGULAR_AND_32 },
  [0x21] = { .size = 1, .instructions = (instruction_t*)&REGULAR_AND_33 },
  [0x22] = { .size = 1, .instructions = (instruction_t*)&REGULAR_AND_34 },
  [0x23] = { .size = 1, .instructions = (instruction_t*)&REGULAR_AND_35 },
  [0x24] = { .size = 1, .instructions = (instruction_t*)&REGULAR_AND_36 },
  [0x25] = { .size = 1, .instructions = (instruction_t*)&REGULAR_AND_37 },
  [0x27] = { .size = 1, .instructions = (instruction_t*)&REGULAR_DAA_39 },
  [0x28] = { .size = 1, .instructions = (instruction_t*)&REGULAR_SUB_40 },
  [0x29] = { .size = 1, .instructions = (instruction_t*)&REGULAR_SUB_41 },
  [0x2a] = { .size = 1, .instructions = (instruction_t*)&REGULAR_SUB_42 },
  [0x2b] = { .size = 1, .instructions = (instruction_t*)&REGULAR_SUB_43 },
  [0x2c] = { .size = 1, .instructions = (instruction_t*)&REGULAR_SUB_44 },
  [0x2d] = { .size = 1, .instructions = (instruction_t*)&REGULAR_SUB_45 },
  [0x2f] = { .size = 1, .instructions = (instruction_t*)&REGULAR_DAS_47 },
  [0x30] = { .size = 1, .instructions = (instruction_t*)&REGULAR_XOR_48 },
  [0x31] = { .size = 1, .instructions = (instruction_t*)&REGULAR_XOR_49 },
  [0x32] = { .size = 1, .instructions = (instruction_t*)&REGULAR_XOR_50 },
  [0x33] = { .size = 1, .instructions = (instruction_t*)&REGULAR_XOR_51 },
  [0x34] = { .size = 1, .instructions = (instruction_t*)&REGULAR_XOR_52 },
  [0x35] = { .size = 1, .instructions = (instruction_t*)&REGULAR_XOR_53 },
  [0x37] = { .size = 1, .instructions = (instruction_t*)&REGULAR_AAA_55 },
  [0x38] = { .size = 1, .instructions = (instruction_t*)&REGULAR_CMP_56 },
  [0x39] = { .size = 1, .instructions = (instruction_t*)&REGULAR_CMP_57 },
  [0x3a] = { .size = 1, .instructions = (instruction_t*)&REGULAR_CMP_58 },
  [0x3b] = { .size = 1, .instructions = (instruction_t*)&REGULAR_CMP_59 },
  [0x3c] = { .size = 1, .instructions = (instruction_t*)&REGULAR_CMP_60 },
  [0x3d] = { .size = 1, .instructions = (instruction_t*)&REGULAR_CMP_61 },
  [0x3f] = { .size = 1, .instructions = (instruction_t*)&REGULAR_AAS_63 },
  [0x40] = { .size = 1, .instructions = (instruction_t*)&REGULAR_INC_64 },
  [0x41] = { .size = 1, .instructions = (instruction_t*)&REGULAR_INC_65 },
  [0x42] = { .size = 1, .instructions = (instruction_t*)&REGULAR_INC_66 },
  [0x43] = { .size = 1, .instructions = (instruction_t*)&REGULAR_INC_67 },
  [0x44] = { .size = 1, .instructions = (instruction_t*)&REGULAR_INC_68 },
  [0x45] = { .size = 1, .instructions = (instruction_t*)&REGULAR_INC_69 },
  [0x46] = { .size = 1, .instructions = (instruction_t*)&REGULAR_INC_70 },
  [0x47] = { .size = 1, .instructions = (instruction_t*)&REGULAR_INC_71 },
  [0x48] = { .size = 1, .instructions = (instruction_t*)&REGULAR_DEC_72 },
  [0x49] = { .size = 1, .instructions = (instruction_t*)&REGULAR_DEC_73 },
  [0x50] = { .size = 1, .instructions = (instruction_t*)&REGULAR_PUSH_80 },
  [0x51] = { .size = 1, .instructions = (instruction_t*)&REGULAR_PUSH_81 },
  [0x52] = { .size = 1, .instructions = (instruction_t*)&REGULAR_PUSH_82 },
  [0x53] = { .size = 1, .instructions = (instruction_t*)&REGULAR_PUSH_83 },
  [0x54] = { .size = 1, .instructions = (instruction_t*)&REGULAR_PUSH_84 },
  [0x55] = { .size = 1, .instructions = (instruction_t*)&REGULAR_PUSH_85 },
  [0x56] = { .size = 1, .instructions = (instruction_t*)&REGULAR_PUSH_86 },
  [0x57] = { .size = 1, .instructions = (instruction_t*)&REGULAR_PUSH_87 },
  [0x58] = { .size = 1, .instructions = (instruction_t*)&REGULAR_POP_88 },
  [0x59] = { .size = 1, .instructions = (instruction_t*)&REGULAR_POP_89 },
  [0x5a] = { .size = 1, .instructions = (instruction_t*)&REGULAR_POP_90 },
  [0x5b] = { .size = 1, .instructions = (instruction_t*)&REGULAR_POP_91 },
  [0x5c] = { .size = 1, .instructions = (instruction_t*)&REGULAR_POP_92 },
  [0x5d] = { .size = 1, .instructions = (instruction_t*)&REGULAR_POP_93 },
  [0x5e] = { .size = 1, .instructions = (instruction_t*)&REGULAR_POP_94 },
  [0x5f] = { .size = 1, .instructions = (instruction_t*)&REGULAR_POP_95 },
  [0x60] = { .size = 1, .instructions = (instruction_t*)&REGULAR_PUSHAD_96 },
  [0x61] = { .size = 1, .instructions = (instruction_t*)&REGULAR_POPAD_97 },
  [0x62] = { .size = 1, .instructions = (instruction_t*)&REGULAR_BOUND_98 },
  [0x63] = { .size = 1, .instructions = (instruction_t*)&REGULAR_ARPL_99 },
  [0x68] = { .size = 1, .instructions = (instruction_t*)&REGULAR_PUSH_104 },
  [0x69] = { .size = 1, .instructions = (instruction_t*)&REGULAR_IMUL_105 },
  [0x6a] = { .size = 1, .instructions = (instruction_t*)&REGULAR_PUSH_106 },
  [0x6b] = { .size = 1, .instructions = (instruction_t*)&REGULAR_IMUL_107 },
  [0x6c] = { .size = 1, .instructions = (instruction_t*)&REGULAR_INS_108 },
  [0x6d] = { .size = 2, .instructions = (instruction_t*)&REGULAR_INS_109 },
  [0x6e] = { .size = 1, .instructions = (instruction_t*)&REGULAR_OUTS_110 },
  [0x6f] = { .size = 2, .instructions = (instruction_t*)&REGULAR_OUTS_111 },
  [0x70] = { .size = 1, .instructions = (instruction_t*)&REGULAR_JO_112 },
  [0x71] = { .size = 1, .instructions = (instruction_t*)&REGULAR_JNO_113 },
  [0x72] = { .size = 1, .instructions = (instruction_t*)&REGULAR_JB_114 },
  [0x73] = { .size = 1, .instructions = (instruction_t*)&REGULAR_JNB_115 },
  [0x74] = { .size = 1, .instructions = (instruction_t*)&REGULAR_JZ_116 },
  [0x75] = { .size = 1, .instructions = (instruction_t*)&REGULAR_JNZ_117 },
  [0x76] = { .size = 1, .instructions = (instruction_t*)&REGULAR_JBE_118 },
  [0x77] = { .size = 1, .instructions = (instruction_t*)&REGULAR_JNBE_119 },
  [0x78] = { .size = 1, .instructions = (instruction_t*)&REGULAR_JS_120 },
  [0x79] = { .size = 1, .instructions = (instruction_t*)&REGULAR_JNS_121 },
  [0x7a] = { .size = 1, .instructions = (instruction_t*)&REGULAR_JP_122 },
  [0x7b] = { .size = 1, .instructions = (instruction_t*)&REGULAR_JNP_123 },
  [0x7c] = { .size = 1, .instructions = (instruction_t*)&REGULAR_JL_124 },
  [0x7d] = { .size = 1, .instructions = (instruction_t*)&REGULAR_JNL_125 },
  [0x7e] = { .size = 1, .instructions = (instruction_t*)&REGULAR_JLE_126 },
  [0x7f] = { .size = 1, .instructions = (instruction_t*)&REGULAR_JNLE_127 },
  [0x80] = { .size = 8, .instructions = (instruction_t*)&REGULAR_ADD_128 },
  [0x81] = { .size = 8, .instructions = (instruction_t*)&REGULAR_ADD_129 },
  [0x82] = { .size = 8, .instructions = (instruction_t*)&REGULAR_ADD_130 },
  [0x83] = { .size = 8, .instructions = (instruction_t*)&REGULAR_ADD_131 },
  [0x84] = { .size = 1, .instructions = (instruction_t*)&REGULAR_TEST_132 },
  [0x85] = { .size = 1, .instructions = (instruction_t*)&REGULAR_TEST_133 },
  [0x86] = { .size = 1, .instructions = (instruction_t*)&REGULAR_XCHG_134 },
  [0x87] = { .size = 1, .instructions = (instruction_t*)&REGULAR_XCHG_135 },
  [0x88] = { .size = 1, .instructions = (instruction_t*)&REGULAR_MOV_136 },
  [0x89] = { .size = 1, .instructions = (instruction_t*)&REGULAR_MOV_137 },
  [0x8a] = { .size = 1, .instructions = (instruction_t*)&REGULAR_MOV_138 },
  [0x8b] = { .size = 1, .instructions = (instruction_t*)&REGULAR_MOV_139 },
  [0x8c] = { .size = 1, .instructions = (instruction_t*)&REGULAR_MOV_140 },
  [0x8d] = { .size = 1, .instructions = (instruction_t*)&REGULAR_LEA_141 },
  [0x8e] = { .size = 1, .instructions = (instruction_t*)&REGULAR_MOV_142 },
  [0x8f] = { .size = 1, .instructions = (instruction_t*)&REGULAR_POP_143 },
  [0x90] = { .size = 2, .instructions = (instruction_t*)&REGULAR_NOP_144 },
  [0x91] = { .size = 1, .instructions = (instruction_t*)&REGULAR_XCHG_145 },
  [0x92] = { .size = 1, .instructions = (instruction_t*)&REGULAR_XCHG_146 },
  [0x93] = { .size = 1, .instructions = (instruction_t*)&REGULAR_XCHG_147 },
  [0x94] = { .size = 1, .instructions = (instruction_t*)&REGULAR_XCHG_148 },
  [0x95] = { .size = 1, .instructions = (instruction_t*)&REGULAR_XCHG_149 },
  [0x96] = { .size = 1, .instructions = (instruction_t*)&REGULAR_XCHG_150 },
  [0x97] = { .size = 1, .instructions = (instruction_t*)&REGULAR_XCHG_151 },
  [0x98] = { .size = 2, .instructions = (instruction_t*)&REGULAR_CBW_152 },
  [0x99] = { .size = 1, .instructions = (instruction_t*)&REGULAR_CDQ_153 },
  [0x9a] = { .size = 1, .instructions = (instruction_t*)&REGULAR_CALLF_154 },
  [0x9b] = { .size = 2, .instructions = (instruction_t*)&REGULAR_FWAIT_155 },
  [0x9c] = { .size = 1, .instructions = (instruction_t*)&REGULAR_PUSHFD_156 },
  [0x9d] = { .size = 1, .instructions = (instruction_t*)&REGULAR_POPFD_157 },
  [0x9e] = { .size = 1, .instructions = (instruction_t*)&REGULAR_SAHF_158 },
  [0x9f] = { .size = 1, .instructions = (instruction_t*)&REGULAR_LAHF_159 },
  [0xa0] = { .size = 1, .instructions = (instruction_t*)&REGULAR_MOV_160 },
  [0xa1] = { .size = 1, .instructions = (instruction_t*)&REGULAR_MOV_161 },
  [0xa2] = { .size = 1, .instructions = (instruction_t*)&REGULAR_MOV_162 },
  [0xa3] = { .size = 1, .instructions = (instruction_t*)&REGULAR_MOV_163 },
  [0xa4] = { .size = 1, .instructions = (instruction_t*)&REGULAR_MOVS_164 },
  [0xa5] = { .size = 2, .instructions = (instruction_t*)&REGULAR_MOVS_165 },
  [0xa6] = { .size = 1, .instructions = (instruction_t*)&REGULAR_CMPS_166 },
  [0xa7] = { .size = 2, .instructions = (instruction_t*)&REGULAR_CMPS_167 },
  [0xa8] = { .size = 1, .instructions = (instruction_t*)&REGULAR_TEST_168 },
  [0xa9] = { .size = 1, .instructions = (instruction_t*)&REGULAR_TEST_169 },
  [0xaa] = { .size = 1, .instructions = (instruction_t*)&REGULAR_STOS_170 },
  [0xab] = { .size = 2, .instructions = (instruction_t*)&REGULAR_STOS_171 },
  [0xac] = { .size = 1, .instructions = (instruction_t*)&REGULAR_LODS_172 },
  [0xad] = { .size = 2, .instructions = (instruction_t*)&REGULAR_LODS_173 },
  [0xae] = { .size = 1, .instructions = (instruction_t*)&REGULAR_SCAS_174 },
  [0xaf] = { .size = 2, .instructions = (instruction_t*)&REGULAR_SCAS_175 },
  [0xb0] = { .size = 1, .instructions = (instruction_t*)&REGULAR_MOV_176 },
  [0xb1] = { .size = 1, .instructions = (instruction_t*)&REGULAR_MOV_177 },
  [0xb2] = { .size = 1, .instructions = (instruction_t*)&REGULAR_MOV_178 },
  [0xb3] = { .size = 1, .instructions = (instruction_t*)&REGULAR_MOV_179 },
  [0xb4] = { .size = 1, .instructions = (instruction_t*)&REGULAR_MOV_180 },
  [0xb5] = { .size = 1, .instructions = (instruction_t*)&REGULAR_MOV_181 },
  [0xb6] = { .size = 1, .instructions = (instruction_t*)&REGULAR_MOV_182 },
  [0xb7] = { .size = 1, .instructions = (instruction_t*)&REGULAR_MOV_183 },
  [0xb8] = { .size = 1, .instructions = (instruction_t*)&REGULAR_MOV_184 },
  [0xb9] = { .size = 1, .instructions = (instruction_t*)&REGULAR_MOV_185 },
  [0xba] = { .size = 1, .instructions = (instruction_t*)&REGULAR_MOV_186 },
  [0xbb] = { .size = 1, .instructions = (instruction_t*)&REGULAR_MOV_187 },
  [0xbc] = { .size = 1, .instructions = (instruction_t*)&REGULAR_MOV_188 },
  [0xbd] = { .size = 1, .instructions = (instruction_t*)&REGULAR_MOV_189 },
  [0xbe] = { .size = 1, .instructions = (instruction_t*)&REGULAR_MOV_190 },
  [0xbf] = { .size = 1, .instructions = (instruction_t*)&REGULAR_MOV_191 },
  [0xc0] = { .size = 8, .instructions = (instruction_t*)&REGULAR_ROL_192 },
  [0xc1] = { .size = 8, .instructions = (instruction_t*)&REGULAR_ROL_193 },
  [0xc2] = { .size = 1, .instructions = (instruction_t*)&REGULAR_RETN_194 },
  [0xc3] = { .size = 1, .instructions = (instruction_t*)&REGULAR_RETN_195 },
  [0xc4] = { .size = 1, .instructions = (instruction_t*)&REGULAR_LES_196 },
  [0xc5] = { .size = 1, .instructions = (instruction_t*)&REGULAR_LDS_197 },
  [0xc6] = { .size = 1, .instructions = (instruction_t*)&REGULAR_MOV_198 },
  [0xc7] = { .size = 1, .instructions = (instruction_t*)&REGULAR_MOV_199 },
  [0xc8] = { .size = 1, .instructions = (instruction_t*)&REGULAR_ENTER_200 },
  [0xc9] = { .size = 1, .instructions = (instruction_t*)&REGULAR_LEAVE_201 },
  [0xca] = { .size = 1, .instructions = (instruction_t*)&REGULAR_RETF_202 },
  [0xcb] = { .size = 1, .instructions = (instruction_t*)&REGULAR_RETF_203 },
  [0xcc] = { .size = 1, .instructions = (instruction_t*)&REGULAR_INT3_204 },
  [0xcd] = { .size = 1, .instructions = (instruction_t*)&REGULAR_INT_205 },
  [0xce] = { .size = 1, .instructions = (instruction_t*)&REGULAR_INTO_206 },
  [0xcf] = { .size = 1, .instructions = (instruction_t*)&REGULAR_IRETD_207 },
  [0xd0] = { .size = 8, .instructions = (instruction_t*)&REGULAR_ROL_208 },
  [0xd1] = { .size = 8, .instructions = (instruction_t*)&REGULAR_ROL_209 },
  [0xd2] = { .size = 8, .instructions = (instruction_t*)&REGULAR_ROL_210 },
  [0xd3] = { .size = 8, .instructions = (instruction_t*)&REGULAR_ROL_211 },
  [0xd4] = { .size = 1, .instructions = (instruction_t*)&REGULAR_AMX_212 },
  [0xd5] = { .size = 1, .instructions = (instruction_t*)&REGULAR_ADX_213 },
  [0xd6] = { .size = 1, .instructions = (instruction_t*)&REGULAR_SALC_214 },
  [0xd7] = { .size = 1, .instructions = (instruction_t*)&REGULAR_XLAT_215 },
  [0xd8] = { .size = 72, .instructions = (instruction_t*)&REGULAR_FADD_216 },
  [0xd9] = { .size = 60, .instructions = (instruction_t*)&REGULAR_FLD_217 },
  [0xda] = { .size = 13, .instructions = (instruction_t*)&REGULAR_FIADD_218 },
  [0xdb] = { .size = 19, .instructions = (instruction_t*)&REGULAR_FILD_219 },
  [0xdc] = { .size = 16, .instructions = (instruction_t*)&REGULAR_FADD_220 },
  [0xdd] = { .size = 15, .instructions = (instruction_t*)&REGULAR_FLD_221 },
  [0xde] = { .size = 16, .instructions = (instruction_t*)&REGULAR_FIADD_222 },
  [0xdf] = { .size = 16, .instructions = (instruction_t*)&REGULAR_FILD_223 },
  [0xe0] = { .size = 1, .instructions = (instruction_t*)&REGULAR_LOOPNZ_224 },
  [0xe1] = { .size = 1, .instructions = (instruction_t*)&REGULAR_LOOPZ_225 },
  [0xe2] = { .size = 1, .instructions = (instruction_t*)&REGULAR_LOOP_226 },
  [0xe3] = { .size = 1, .instructions = (instruction_t*)&REGULAR_JCXZ_227 },
  [0xe4] = { .size = 1, .instructions = (instruction_t*)&REGULAR_IN_228 },
  [0xe5] = { .size = 1, .instructions = (instruction_t*)&REGULAR_IN_229 },
  [0xe6] = { .size = 1, .instructions = (instruction_t*)&REGULAR_OUT_230 },
  [0xe7] = { .size = 1, .instructions = (instruction_t*)&REGULAR_OUT_231 },
  [0xe8] = { .size = 1, .instructions = (instruction_t*)&REGULAR_CALL_232 },
  [0xe9] = { .size = 1, .instructions = (instruction_t*)&REGULAR_JMP_233 },
  [0xea] = { .size = 1, .instructions = (instruction_t*)&REGULAR_JMPF_234 },
  [0xeb] = { .size = 1, .instructions = (instruction_t*)&REGULAR_JMP_235 },
  [0xec] = { .size = 1, .instructions = (instruction_t*)&REGULAR_IN_236 },
  [0xed] = { .size = 1, .instructions = (instruction_t*)&REGULAR_IN_237 },
  [0xee] = { .size = 1, .instructions = (instruction_t*)&REGULAR_OUT_238 },
  [0xef] = { .size = 1, .instructions = (instruction_t*)&REGULAR_OUT_239 },
  [0xf1] = { .size = 1, .instructions = (instruction_t*)&REGULAR_INT1_241 },
  [0xf4] = { .size = 1, .instructions = (instruction_t*)&REGULAR_HLT_244 },
  [0xf5] = { .size = 1, .instructions = (instruction_t*)&REGULAR_CMC_245 },
  [0xf6] = { .size = 8, .instructions = (instruction_t*)&REGULAR_TEST_246 },
  [0xf7] = { .size = 8, .instructions = (instruction_t*)&REGULAR_TEST_247 },
  [0xf8] = { .size = 1, .instructions = (instruction_t*)&REGULAR_CLC_248 },
  [0xf9] = { .size = 1, .instructions = (instruction_t*)&REGULAR_STC_249 },
  [0xfa] = { .size = 1, .instructions = (instruction_t*)&REGULAR_CLI_250 },
  [0xfb] = { .size = 1, .instructions = (instruction_t*)&REGULAR_STI_251 },
  [0xfc] = { .size = 1, .instructions = (instruction_t*)&REGULAR_CLD_252 },
  [0xfd] = { .size = 1, .instructions = (instruction_t*)&REGULAR_STD_253 },
  [0xfe] = { .size = 2, .instructions = (instruction_t*)&REGULAR_INC_254 },
  [0xff] = { .size = 7, .instructions = (instruction_t*)&REGULAR_INC_255 },
};
 // regular end
instruction_container_t extended_table_32[0x100] = {
  [0x0] = { .size = 6, .instructions = (instruction_t*)&EXTENDED_SLDT_0 },
  [0x1] = { .size = 16, .instructions = (instruction_t*)&EXTENDED_SGDT_1 },
  [0x2] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_LAR_2 },
  [0x3] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_LSL_3 },
  [0x5] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_SYSCALL_5 },
  [0x6] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_CLTS_6 },
  [0x8] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_INVD_8 },
  [0x9] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_WBINVD_9 },
  [0xb] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_UD2_11 },
  [0xd] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_NOP_13 },
  [0x10] = { .size = 4, .instructions = (instruction_t*)&EXTENDED_MOVUPS_16 },
  [0x11] = { .size = 4, .instructions = (instruction_t*)&EXTENDED_MOVUPS_17 },
  [0x12] = { .size = 5, .instructions = (instruction_t*)&EXTENDED_MOVHLPS_18 },
  [0x13] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_MOVLPS_19 },
  [0x14] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_UNPCKLPS_20 },
  [0x15] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_UNPCKHPS_21 },
  [0x16] = { .size = 4, .instructions = (instruction_t*)&EXTENDED_MOVLHPS_22 },
  [0x17] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_MOVHPS_23 },
  [0x18] = { .size = 8, .instructions = (instruction_t*)&EXTENDED_PREFETCHNTA_24 },
  [0x1e] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_ENDBR32_30 },
  [0x19] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_HINT_NOP_25 },
  [0x1a] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_HINT_NOP_26 },
  [0x1b] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_HINT_NOP_27 },
  [0x1c] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_HINT_NOP_28 },
  [0x1d] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_HINT_NOP_29 },
  [0x1f] = { .size = 8, .instructions = (instruction_t*)&EXTENDED_NOP_31 },
  [0x20] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_MOV_32 },
  [0x21] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_MOV_33 },
  [0x22] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_MOV_34 },
  [0x23] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_MOV_35 },
  [0x28] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_MOVAPS_40 },
  [0x29] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_MOVAPS_41 },
  [0x2a] = { .size = 4, .instructions = (instruction_t*)&EXTENDED_CVTPI2PS_42 },
  [0x2b] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_MOVNTPS_43 },
  [0x2c] = { .size = 4, .instructions = (instruction_t*)&EXTENDED_CVTTPS2PI_44 },
  [0x2d] = { .size = 4, .instructions = (instruction_t*)&EXTENDED_CVTPS2PI_45 },
  [0x2e] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_UCOMISS_46 },
  [0x2f] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_COMISS_47 },
  [0x30] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_WRMSR_48 },
  [0x31] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_RDTSC_49 },
  [0x32] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_RDMSR_50 },
  [0x33] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_RDPMC_51 },
  [0x34] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_SYSENTER_52 },
  [0x35] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_SYSEXIT_53 },
  [0x37] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_GETSEC_55 },
  [0x38] = { .size = 67, .instructions = (instruction_t*)&EXTENDED_PSHUFB_56 },
  [0x3a] = { .size = 23, .instructions = (instruction_t*)&EXTENDED_ROUNDPS_58 },
  [0x40] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_CMOVO_64 },
  [0x41] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_CMOVNO_65 },
  [0x42] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_CMOVB_66 },
  [0x43] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_CMOVNB_67 },
  [0x44] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_CMOVZ_68 },
  [0x45] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_CMOVNZ_69 },
  [0x46] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_CMOVBE_70 },
  [0x47] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_CMOVNBE_71 },
  [0x48] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_CMOVS_72 },
  [0x49] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_CMOVNS_73 },
  [0x4a] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_CMOVP_74 },
  [0x4b] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_CMOVNP_75 },
  [0x4c] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_CMOVL_76 },
  [0x4d] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_CMOVNL_77 },
  [0x4e] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_CMOVLE_78 },
  [0x4f] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_CMOVNLE_79 },
  [0x50] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_MOVMSKPS_80 },
  [0x51] = { .size = 4, .instructions = (instruction_t*)&EXTENDED_SQRTPS_81 },
  [0x52] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_RSQRTPS_82 },
  [0x53] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_RCPPS_83 },
  [0x54] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_ANDPS_84 },
  [0x55] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_ANDNPS_85 },
  [0x56] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_ORPS_86 },
  [0x57] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_XORPS_87 },
  [0x58] = { .size = 4, .instructions = (instruction_t*)&EXTENDED_ADDPS_88 },
  [0x59] = { .size = 4, .instructions = (instruction_t*)&EXTENDED_MULPS_89 },
  [0x5a] = { .size = 4, .instructions = (instruction_t*)&EXTENDED_CVTPS2PD_90 },
  [0x5b] = { .size = 3, .instructions = (instruction_t*)&EXTENDED_CVTDQ2PS_91 },
  [0x5c] = { .size = 4, .instructions = (instruction_t*)&EXTENDED_SUBPS_92 },
  [0x5d] = { .size = 4, .instructions = (instruction_t*)&EXTENDED_MINPS_93 },
  [0x5e] = { .size = 4, .instructions = (instruction_t*)&EXTENDED_DIVPS_94 },
  [0x5f] = { .size = 4, .instructions = (instruction_t*)&EXTENDED_MAXPS_95 },
  [0x60] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PUNPCKLBW_96 },
  [0x61] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PUNPCKLWD_97 },
  [0x62] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PUNPCKLDQ_98 },
  [0x63] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PACKSSWB_99 },
  [0x64] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PCMPGTB_100 },
  [0x65] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PCMPGTW_101 },
  [0x66] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PCMPGTD_102 },
  [0x67] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PACKUSWB_103 },
  [0x68] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PUNPCKHBW_104 },
  [0x69] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PUNPCKHWD_105 },
  [0x6a] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PUNPCKHDQ_106 },
  [0x6b] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PACKSSDW_107 },
  [0x6c] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_PUNPCKLQDQ_108 },
  [0x6d] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_PUNPCKHQDQ_109 },
  [0x6e] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_MOVD_110 },
  [0x6f] = { .size = 3, .instructions = (instruction_t*)&EXTENDED_MOVQ_111 },
  [0x70] = { .size = 4, .instructions = (instruction_t*)&EXTENDED_PSHUFW_112 },
  [0x71] = { .size = 6, .instructions = (instruction_t*)&EXTENDED_PSRLW_113 },
  [0x72] = { .size = 6, .instructions = (instruction_t*)&EXTENDED_PSRLD_114 },
  [0x73] = { .size = 6, .instructions = (instruction_t*)&EXTENDED_PSRLQ_115 },
  [0x74] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PCMPEQB_116 },
  [0x75] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PCMPEQW_117 },
  [0x76] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PCMPEQD_118 },
  [0x77] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_EMMS_119 },
  [0x78] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_VMREAD_120 },
  [0x79] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_VMWRITE_121 },
  [0x7c] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_HADDPD_124 },
  [0x7d] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_HSUBPD_125 },
  [0x7e] = { .size = 3, .instructions = (instruction_t*)&EXTENDED_MOVD_126 },
  [0x7f] = { .size = 3, .instructions = (instruction_t*)&EXTENDED_MOVQ_127 },
  [0x80] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_JO_128 },
  [0x81] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_JNO_129 },
  [0x82] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_JB_130 },
  [0x83] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_JNB_131 },
  [0x84] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_JZ_132 },
  [0x85] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_JNZ_133 },
  [0x86] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_JBE_134 },
  [0x87] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_JNBE_135 },
  [0x88] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_JS_136 },
  [0x89] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_JNS_137 },
  [0x8a] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_JP_138 },
  [0x8b] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_JNP_139 },
  [0x8c] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_JL_140 },
  [0x8d] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_JNL_141 },
  [0x8e] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_JLE_142 },
  [0x8f] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_JNLE_143 },
  [0x90] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_SETO_144 },
  [0x91] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_SETNO_145 },
  [0x92] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_SETB_146 },
  [0x93] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_SETNB_147 },
  [0x94] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_SETZ_148 },
  [0x95] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_SETNZ_149 },
  [0x96] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_SETBE_150 },
  [0x97] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_SETNBE_151 },
  [0x98] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_SETS_152 },
  [0x99] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_SETNS_153 },
  [0x9a] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_SETP_154 },
  [0x9b] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_SETNP_155 },
  [0x9c] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_SETL_156 },
  [0x9d] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_SETNL_157 },
  [0x9e] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_SETLE_158 },
  [0x9f] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_SETNLE_159 },
  [0xa0] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_PUSH_160 },
  [0xa1] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_POP_161 },
  [0xa2] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_CPUID_162 },
  [0xa3] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_BT_163 },
  [0xa4] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_SHLD_164 },
  [0xa5] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_SHLD_165 },
  [0xa8] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_PUSH_168 },
  [0xa9] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_POP_169 },
  [0xaa] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_RSM_170 },
  [0xab] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_BTS_171 },
  [0xac] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_SHRD_172 },
  [0xad] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_SHRD_173 },
  [0xae] = { .size = 10, .instructions = (instruction_t*)&EXTENDED_FXSAVE_174 },
  [0xaf] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_IMUL_175 },
  [0xb0] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_CMPXCHG_176 },
  [0xb1] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_CMPXCHG_177 },
  [0xb2] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_LSS_178 },
  [0xb3] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_BTR_179 },
  [0xb4] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_LFS_180 },
  [0xb5] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_LGS_181 },
  [0xb6] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_MOVZX_182 },
  [0xb7] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_MOVZX_183 },
  [0xb8] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_POPCNT_184 },
  [0xb9] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_UD_185 },
  [0xba] = { .size = 4, .instructions = (instruction_t*)&EXTENDED_BT_186 },
  [0xbb] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_BTC_187 },
  [0xbc] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_BSF_188 },
  [0xbd] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_BSR_189 },
  [0xbe] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_MOVSX_190 },
  [0xbf] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_MOVSX_191 },
  [0xc0] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_XADD_192 },
  [0xc1] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_XADD_193 },
  [0xc2] = { .size = 4, .instructions = (instruction_t*)&EXTENDED_CMPPS_194 },
  [0xc3] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_MOVNTI_195 },
  [0xc4] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PINSRW_196 },
  [0xc5] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PEXTRW_197 },
  [0xc6] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_SHUFPS_198 },
  [0xc7] = { .size = 5, .instructions = (instruction_t*)&EXTENDED_CMPXCHG8B_199 },
  [0xc8] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_BSWAP_200 },
  [0xc9] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_BSWAP_201 },
  [0xca] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_BSWAP_202 },
  [0xcb] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_BSWAP_203 },
  [0xcc] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_BSWAP_204 },
  [0xcd] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_BSWAP_205 },
  [0xce] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_BSWAP_206 },
  [0xcf] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_BSWAP_207 },
  [0xd0] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_ADDSUBPD_208 },
  [0xd1] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PSRLW_209 },
  [0xd2] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PSRLD_210 },
  [0xd3] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PSRLQ_211 },
  [0xd4] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PADDQ_212 },
  [0xd5] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PMULLW_213 },
  [0xd6] = { .size = 3, .instructions = (instruction_t*)&EXTENDED_MOVQ_214 },
  [0xd7] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PMOVMSKB_215 },
  [0xd8] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PSUBUSB_216 },
  [0xd9] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PSUBUSW_217 },
  [0xda] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PMINUB_218 },
  [0xdb] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PAND_219 },
  [0xdc] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PADDUSB_220 },
  [0xdd] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PADDUSW_221 },
  [0xde] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PMAXUB_222 },
  [0xdf] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PANDN_223 },
  [0xe0] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PAVGB_224 },
  [0xe1] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PSRAW_225 },
  [0xe2] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PSRAD_226 },
  [0xe3] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PAVGW_227 },
  [0xe4] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PMULHUW_228 },
  [0xe5] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PMULHW_229 },
  [0xe6] = { .size = 3, .instructions = (instruction_t*)&EXTENDED_CVTPD2DQ_230 },
  [0xe7] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_MOVNTQ_231 },
  [0xe8] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PSUBSB_232 },
  [0xe9] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PSUBSW_233 },
  [0xea] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PMINSW_234 },
  [0xeb] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_POR_235 },
  [0xec] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PADDSB_236 },
  [0xed] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PADDSW_237 },
  [0xee] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PMAXSW_238 },
  [0xef] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PXOR_239 },
  [0xf0] = { .size = 1, .instructions = (instruction_t*)&EXTENDED_LDDQU_240 },
  [0xf1] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PSLLW_241 },
  [0xf2] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PSLLD_242 },
  [0xf3] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PSLLQ_243 },
  [0xf4] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PMULUDQ_244 },
  [0xf5] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PMADDWD_245 },
  [0xf6] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PSADBW_246 },
  [0xf7] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_MASKMOVQ_247 },
  [0xf8] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PSUBB_248 },
  [0xf9] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PSUBW_249 },
  [0xfa] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PSUBD_250 },
  [0xfb] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PSUBQ_251 },
  [0xfc] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PADDB_252 },
  [0xfd] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PADDW_253 },
  [0xfe] = { .size = 2, .instructions = (instruction_t*)&EXTENDED_PADDD_254 },
};
 // extended end
