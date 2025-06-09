/*
 * Copyright (c) 2024 lightswisp
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/

#include <pedix/decoder.h>
#include <pedix/dump.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

/* some colors for the output */
#define GREEN "\033[0;32m"
#define NC "\033[0m"
#define TEXT_IDENTICAL(d, s)((strcmp(d,s) == 0))

/* test template */
#define PREPARE_TEST(n, itext)                                                 \
  pedix_decode(decoded, instruction##n);                                       \
  printf("[*] testing for: %s\n", itext);                                      \
  printf("[*] decoded->text = %s\n", decoded->text);                           \
  assert(                                                                      \
      ("instruction text test " #n && TEXT_IDENTICAL(decoded->text, itext)));  \
  printf(GREEN "test ok\n" NC);                                                \
  pedix_zero_instruction(decoded);

#define PREPARE_INSTRUCTION(n, ibytes) \
  uint8_t instruction##n[] = ibytes 

/*add WORD PTR[ecx+esi*1],cx */
PREPARE_INSTRUCTION(1, "\x66\x01\x0C\x31");

/* add DWORD PTR[edx], eax */
PREPARE_INSTRUCTION(2, "\x01\x02");

/* mov DWORD PTR [eax+0x50],0x11111111 */
PREPARE_INSTRUCTION(3, "\xC7\x40\x50\x11\x11\x11\x11");

/* mov DWORD PTR [ecx+edx*2+0x50],0x11111111 */
PREPARE_INSTRUCTION(4, "\xC7\x44\x51\x50\x11\x11\x11\x11");

/* mov WORD PTR ss:[ecx-0xAFBC01], ax  */
PREPARE_INSTRUCTION(5, "\x36\x66\x89\x84\x61\xFF\x43\x50\xFF");

PREPARE_INSTRUCTION(6, "\x8d\x4c\x24\x04"); //lea ecx,DWORD PTR [esp+0x04]
PREPARE_INSTRUCTION(7, "\x83\xe4\xf0"); //and esp,0xf0
PREPARE_INSTRUCTION(8, "\xff\x71\xfc"); //push DWORD PTR [ecx-0x04]
PREPARE_INSTRUCTION(9, "\x55"); //push ebp
PREPARE_INSTRUCTION(10, "\x89\xe5"); //mov ebp,esp
PREPARE_INSTRUCTION(11, "\x53"); //push ebx
PREPARE_INSTRUCTION(12, "\x51"); //push ecx
PREPARE_INSTRUCTION(13, "\x83\xec\x10"); //sub esp,0x10
PREPARE_INSTRUCTION(14, "\xe8\xec\xfe\xff\xff"); //call 0xfffffef1
PREPARE_INSTRUCTION(15, "\x81\xc3\x50\x2e\x00\x00"); //add ebx,0x00002e50
PREPARE_INSTRUCTION(16, "\xc7\x45\xf4\xbf\x7f\xff\xff"); //mov DWORD PTR [ebp-0x0c],0xffff7fbf
PREPARE_INSTRUCTION(17, "\x8b\x45\xf4"); //mov eax,DWORD PTR [ebp-0x0c]
PREPARE_INSTRUCTION(18, "\xc1\xe8\x1f"); //shr eax,0x1f
PREPARE_INSTRUCTION(19, "\x83\xf8\x01"); //cmp eax,0x01
PREPARE_INSTRUCTION(20, "\x75\x07"); //jnz 0x09
PREPARE_INSTRUCTION(21, "\xb8\x2d\x00\x00\x00"); //mov eax,0x0000002d
PREPARE_INSTRUCTION(22, "\xeb\x05"); //jmp 0x07
PREPARE_INSTRUCTION(23, "\xb8\x2b\x00\x00\x00"); //mov eax,0x0000002b
PREPARE_INSTRUCTION(24, "\x88\x45\xf3"); //mov BYTE PTR [ebp-0x0d],al
PREPARE_INSTRUCTION(25, "\x0f\xbe\x45\xf3"); //movsx eax,BYTE PTR [ebp-0x0d]
PREPARE_INSTRUCTION(26, "\x83\xec\x08"); //sub esp,0x08
PREPARE_INSTRUCTION(27, "\x50"); //push eax
PREPARE_INSTRUCTION(28, "\x8d\x83\x14\xe0\xff\xff"); //lea eax,DWORD PTR [ebx-0x00001fec]
PREPARE_INSTRUCTION(29, "\x50"); //push eax
PREPARE_INSTRUCTION(30, "\xe8\x61\xfe\xff\xff"); //call 0xfffffe66
PREPARE_INSTRUCTION(31, "\x83\xc4\x10"); //add esp,0x10
PREPARE_INSTRUCTION(32, "\xb8\x00\x00\x00\x80"); //mov eax,0x80000000
PREPARE_INSTRUCTION(33, "\x2b\x45\xf4"); //sub eax,DWORD PTR [ebp-0x0c]
PREPARE_INSTRUCTION(34, "\x89\x45\xec"); //mov DWORD PTR [ebp-0x14],eax
PREPARE_INSTRUCTION(35, "\x83\xec\x08"); //sub esp,0x08
PREPARE_INSTRUCTION(36, "\xff\x75\xec"); //push DWORD PTR [ebp-0x14]
PREPARE_INSTRUCTION(37, "\x8d\x83\x18\xe0\xff\xff"); //lea eax,DWORD PTR [ebx-0x00001fe8]
PREPARE_INSTRUCTION(38, "\x50"); //push eax
PREPARE_INSTRUCTION(39, "\xe8\x41\xfe\xff\xff"); //call 0xfffffe46
PREPARE_INSTRUCTION(40, "\x83\xc4\x10"); //add esp,0x10
PREPARE_INSTRUCTION(41, "\x8b\x45\xf4"); //mov eax,DWORD PTR [ebp-0x0c]
PREPARE_INSTRUCTION(42, "\xf7\xd8"); //neg eax
PREPARE_INSTRUCTION(43, "\x83\xec\x08"); //sub esp,0x08
PREPARE_INSTRUCTION(44, "\x50"); //push eax
PREPARE_INSTRUCTION(45, "\x8d\x83\x1c\xe0\xff\xff"); //lea eax,DWORD PTR [ebx-0x00001fe4]
PREPARE_INSTRUCTION(46, "\x50"); //push eax
PREPARE_INSTRUCTION(47, "\xe8\x29\xfe\xff\xff"); //call 0xfffffe2e
PREPARE_INSTRUCTION(48, "\x83\xc4\x10"); //add esp,0x10
PREPARE_INSTRUCTION(49, "\x83\xec\x08"); //sub esp,0x08
PREPARE_INSTRUCTION(50, "\x6a\x04"); //push 0x04
PREPARE_INSTRUCTION(51, "\x8d\x83\x18\xe0\xff\xff"); //lea eax,DWORD PTR [ebx-0x00001fe8]
PREPARE_INSTRUCTION(52, "\x50"); //push eax
PREPARE_INSTRUCTION(53, "\xe8\x15\xfe\xff\xff"); //call 0xfffffe1a
PREPARE_INSTRUCTION(54, "\x83\xc4\x10"); //add esp,0x10
PREPARE_INSTRUCTION(55, "\xb8\x00\x00\x00\x00"); //mov eax,0x00000000
PREPARE_INSTRUCTION(56, "\x8d\x65\xf8"); //lea esp,DWORD PTR [ebp-0x08]
PREPARE_INSTRUCTION(57, "\x59"); //pop ecx
PREPARE_INSTRUCTION(58, "\x5b"); //pop ebx
PREPARE_INSTRUCTION(59, "\x5d"); //pop ebp
PREPARE_INSTRUCTION(60, "\x8d\x61\xfc"); //lea esp,DWORD PTR [ecx-0x04]
PREPARE_INSTRUCTION(61, "\xc3"); //retn
PREPARE_INSTRUCTION(62, "\x2E\xA0\x11\x22\x33\x44"); //mov al, cs:[0x44332211]
PREPARE_INSTRUCTION(63, "\x65\xA1\x11\x22\x33\x44"); //mov eax, gs:[0x44332211]
PREPARE_INSTRUCTION(64, "\x64\xA2\x11\x22\x33\x44"); //mov fs:[0x44332211], al
PREPARE_INSTRUCTION(65, "\x26\xA3\x11\x22\x33\x44"); //mov es:[0x44332211], eax
PREPARE_INSTRUCTION(66, "\x64\x67\x23\x89\xFE\xFF"); //and ecx,DWORD PTR fs:[bx+di-0x0002] 
PREPARE_INSTRUCTION(67, "\x67\x00\x0E\xAA\xBB"); //add BYTE PTR [0xbbaa],cl
PREPARE_INSTRUCTION(68, "\x67\x39\x11"); // cmp DWORD PTR [bx+di],edx
PREPARE_INSTRUCTION(69,"\x66\x67\x19\x55\xEE");
PREPARE_INSTRUCTION(70,"\x67\xF2\x0F\x38\xF0\xB8\x11\x22");
PREPARE_INSTRUCTION(71, "\x66\x67\x0F\xA4\xF2\x11");
PREPARE_INSTRUCTION(72, "\xd8\xc1");
PREPARE_INSTRUCTION(73, "\xd8\xd1");
PREPARE_INSTRUCTION(74, "\xd8\xdf");
PREPARE_INSTRUCTION(75, "\xd8\xe5");
PREPARE_INSTRUCTION(76, "\xd8\xec");
PREPARE_INSTRUCTION(77, "\xd8\xfe");
PREPARE_INSTRUCTION(78, "\xd9\xc2");
PREPARE_INSTRUCTION(79, "\xd9\xce");
PREPARE_INSTRUCTION(80, "\xD9\x94\x10\x20\x30\x40\x50");
PREPARE_INSTRUCTION(81, "\xD9\xD0");
PREPARE_INSTRUCTION(82, "\xD9\xDF");
PREPARE_INSTRUCTION(83, "\xD9\xA2\x11\x22\x33\x44");
PREPARE_INSTRUCTION(84, "\xD9\xE0");
PREPARE_INSTRUCTION(85, "\xD9\xE1");
PREPARE_INSTRUCTION(86, "\xD9\xE4");
PREPARE_INSTRUCTION(87, "\xD9\xE5");
PREPARE_INSTRUCTION(88, "\xD9\x28");
PREPARE_INSTRUCTION(89, "\xD9\xE8");
PREPARE_INSTRUCTION(90, "\xD9\xE9");
PREPARE_INSTRUCTION(91, "\xD9\xEA");
PREPARE_INSTRUCTION(92, "\xD9\xEB");
PREPARE_INSTRUCTION(93, "\xD9\xEC");
PREPARE_INSTRUCTION(94, "\xD9\xED");
PREPARE_INSTRUCTION(95, "\xD9\xEE");
PREPARE_INSTRUCTION(96, "\xD9\x30");
PREPARE_INSTRUCTION(97, "\xD9\x30");
PREPARE_INSTRUCTION(98, "\xD9\xF0");
PREPARE_INSTRUCTION(99, "\xD9\xF1");
PREPARE_INSTRUCTION(100, "\xD9\xF2");
PREPARE_INSTRUCTION(101, "\xD9\xF3");
PREPARE_INSTRUCTION(102, "\xD9\xF4");
PREPARE_INSTRUCTION(103, "\xD9\xF5");
PREPARE_INSTRUCTION(104, "\xD9\xF6");
PREPARE_INSTRUCTION(105, "\xD9\xF7");
PREPARE_INSTRUCTION(106, "\xD9\x38");
PREPARE_INSTRUCTION(107, "\x9B");
PREPARE_INSTRUCTION(108, "\xD9\x38");
PREPARE_INSTRUCTION(109, "\xD9\xF8");
PREPARE_INSTRUCTION(110, "\xD9\xF9");
PREPARE_INSTRUCTION(111, "\xD9\xFA");
PREPARE_INSTRUCTION(112, "\xD9\xFB");
PREPARE_INSTRUCTION(113, "\xD9\xFC");
PREPARE_INSTRUCTION(114, "\xD9\xFD");
PREPARE_INSTRUCTION(115, "\xD9\xFE");
PREPARE_INSTRUCTION(116, "\xD9\xFF");
PREPARE_INSTRUCTION(117, "\xDA\xC5");
PREPARE_INSTRUCTION(118, "\xDA\x08");
PREPARE_INSTRUCTION(119, "\xDA\xCF");
PREPARE_INSTRUCTION(120, "\xDA\x12");
PREPARE_INSTRUCTION(121, "\xDA\xD4");
PREPARE_INSTRUCTION(122, "\xDA\x1A");
PREPARE_INSTRUCTION(123, "\xDA\xD8");
PREPARE_INSTRUCTION(124, "\xDA\x20");
PREPARE_INSTRUCTION(125, "\xDA\x28");
PREPARE_INSTRUCTION(126, "\xDA\xE9");
PREPARE_INSTRUCTION(127, "\xDA\x30");
PREPARE_INSTRUCTION(128, "\xDA\x38");
PREPARE_INSTRUCTION(129, "\xDB\x00");
PREPARE_INSTRUCTION(130, "\xDB\xC2");
PREPARE_INSTRUCTION(131, "\xDB\x08");
PREPARE_INSTRUCTION(132, "\xDB\xC8");
PREPARE_INSTRUCTION(133, "\xDB\x10");
PREPARE_INSTRUCTION(134, "\xDB\xD0");
PREPARE_INSTRUCTION(135, "\xDB\x18");
PREPARE_INSTRUCTION(136, "\xDB\xD8");
PREPARE_INSTRUCTION(137, "\xDB\xE0");
PREPARE_INSTRUCTION(138, "\xDB\xE1");
PREPARE_INSTRUCTION(139, "\xDB\xE2");
PREPARE_INSTRUCTION(140, "\xDB\xE3");
PREPARE_INSTRUCTION(141, "\xDB\xE4");
PREPARE_INSTRUCTION(142, "\xDB\x28");
PREPARE_INSTRUCTION(143, "\xDB\xE8");
PREPARE_INSTRUCTION(144, "\xDB\xF0");
PREPARE_INSTRUCTION(145, "\xDB\x38");
PREPARE_INSTRUCTION(146, "\xDC\x00");
PREPARE_INSTRUCTION(147, "\xDC\xC0");
PREPARE_INSTRUCTION(148, "\xDC\x08");
PREPARE_INSTRUCTION(149, "\xDC\xC8");
PREPARE_INSTRUCTION(150, "\xDC\x10");
PREPARE_INSTRUCTION(151, "\xDC\x18");
PREPARE_INSTRUCTION(152, "\xDC\x20");
PREPARE_INSTRUCTION(153, "\xDC\x28");
PREPARE_INSTRUCTION(154, "\xDC\xE1");
PREPARE_INSTRUCTION(155, "\xDC\xEA");
PREPARE_INSTRUCTION(156, "\xDC\x30");
PREPARE_INSTRUCTION(157, "\xDC\xF1");
PREPARE_INSTRUCTION(158, "\xDC\x38");
PREPARE_INSTRUCTION(159, "\xDC\xF8");
PREPARE_INSTRUCTION(160, "\xDD\x00");
PREPARE_INSTRUCTION(161, "\xDD\xC5");
PREPARE_INSTRUCTION(162, "\xDD\x08");
PREPARE_INSTRUCTION(163, "\xDD\x10");
PREPARE_INSTRUCTION(164, "\xDD\xD3");
PREPARE_INSTRUCTION(165, "\xDD\x18");
PREPARE_INSTRUCTION(166, "\xDD\xD8");
PREPARE_INSTRUCTION(167, "\xDD\xE0");
PREPARE_INSTRUCTION(168, "\xDD\xE8");
PREPARE_INSTRUCTION(169, "\xDD\x30");
PREPARE_INSTRUCTION(170, "\xDD\x38");
PREPARE_INSTRUCTION(171, "\xDE\x00");
PREPARE_INSTRUCTION(172, "\xDE\xC0");
PREPARE_INSTRUCTION(173, "\xDE\x08");
PREPARE_INSTRUCTION(174, "\xDE\xC8");
PREPARE_INSTRUCTION(175, "\xDE\x10");
PREPARE_INSTRUCTION(176, "\xDE\x18");
PREPARE_INSTRUCTION(177, "\xDE\xD9");
PREPARE_INSTRUCTION(178, "\xDE\x20");
PREPARE_INSTRUCTION(179, "\xDE\xE0");
PREPARE_INSTRUCTION(180, "\xDE\x28");
PREPARE_INSTRUCTION(181, "\xDE\xE8");
PREPARE_INSTRUCTION(182, "\xDE\x30");
PREPARE_INSTRUCTION(183, "\xDE\xF0");
PREPARE_INSTRUCTION(184, "\xDE\x38");
PREPARE_INSTRUCTION(185, "\xDE\xF8");
PREPARE_INSTRUCTION(186, "\xDF\x00");
PREPARE_INSTRUCTION(187, "\xDF\xC0");
PREPARE_INSTRUCTION(188, "\xDF\x08");
PREPARE_INSTRUCTION(189, "\xDF\x10");
PREPARE_INSTRUCTION(190, "\xDF\x18");
PREPARE_INSTRUCTION(191, "\xDF\x20");
PREPARE_INSTRUCTION(192, "\xDF\xE0");
PREPARE_INSTRUCTION(193, "\xDF\x28");
PREPARE_INSTRUCTION(194, "\xDF\xE8");
PREPARE_INSTRUCTION(195, "\xDF\x30");
PREPARE_INSTRUCTION(196, "\xDF\xF0");
PREPARE_INSTRUCTION(197, "\xDF\x38");
PREPARE_INSTRUCTION(198, "\xE0\xFF");
PREPARE_INSTRUCTION(199, "\xE1\xFF");
PREPARE_INSTRUCTION(200, "\xE2\xFF");
PREPARE_INSTRUCTION(201, "\xE3\x10");
PREPARE_INSTRUCTION(202, "\xE4\x10");
PREPARE_INSTRUCTION(203, "\xE5\x10");
PREPARE_INSTRUCTION(204, "\xE6\x10");
PREPARE_INSTRUCTION(205, "\xE7\x10");
PREPARE_INSTRUCTION(206, "\xE8\x10\x20\x30\x40");
PREPARE_INSTRUCTION(207, "\xE9\x10\x20\x30\x40");
PREPARE_INSTRUCTION(208, "\xEA\x10\x20\x30\x40\x50\x60");
PREPARE_INSTRUCTION(209, "\xEB\xFE");
PREPARE_INSTRUCTION(210, "\xEC");
PREPARE_INSTRUCTION(211, "\xED");
PREPARE_INSTRUCTION(212, "\xEE");
PREPARE_INSTRUCTION(213, "\xEF");
PREPARE_INSTRUCTION(214, "\xF1");
PREPARE_INSTRUCTION(215, "\xF4");
PREPARE_INSTRUCTION(216, "\xF5");
PREPARE_INSTRUCTION(217, "\xF6\x00\x00");
PREPARE_INSTRUCTION(218, "\xF6\x08\x00");
PREPARE_INSTRUCTION(219, "\xF6\x10");
PREPARE_INSTRUCTION(220, "\xF6\x18");
PREPARE_INSTRUCTION(221, "\xF6\x20");
PREPARE_INSTRUCTION(222, "\xF6\x28");
PREPARE_INSTRUCTION(223, "\xF6\x30");
PREPARE_INSTRUCTION(224, "\xF6\x38");
PREPARE_INSTRUCTION(225, "\xF7\x00\x11\x22\x33\x44");
PREPARE_INSTRUCTION(226, "\xF7\x08\x11\x22\x33\x44");
PREPARE_INSTRUCTION(227, "\xF7\x10");
PREPARE_INSTRUCTION(228, "\xF7\x18");
PREPARE_INSTRUCTION(229, "\xF7\x20");
PREPARE_INSTRUCTION(230, "\xF7\x28");
PREPARE_INSTRUCTION(231, "\xF7\x30");
PREPARE_INSTRUCTION(232, "\xF7\x38");
PREPARE_INSTRUCTION(233, "\xF8");
PREPARE_INSTRUCTION(234, "\xF9");
PREPARE_INSTRUCTION(235, "\xFA");
PREPARE_INSTRUCTION(236, "\xFB");
PREPARE_INSTRUCTION(237, "\xFC");
PREPARE_INSTRUCTION(238, "\xFD");
PREPARE_INSTRUCTION(239, "\xFE\00");
PREPARE_INSTRUCTION(240, "\xFE\x08");
PREPARE_INSTRUCTION(241, "\xFF\xC0");
PREPARE_INSTRUCTION(242, "\xFF\xC8");
PREPARE_INSTRUCTION(243, "\xFF\xD1");
PREPARE_INSTRUCTION(244, "\xFF\x59\x11");
PREPARE_INSTRUCTION(245, "\xFF\xE1");
PREPARE_INSTRUCTION(246, "\xFF\x28");
PREPARE_INSTRUCTION(247, "\xFF\xF2");
PREPARE_INSTRUCTION(248, "\x0F\x00\x01");
PREPARE_INSTRUCTION(249, "\x0F\x00\x08");
PREPARE_INSTRUCTION(250, "\x0F\x00\x10");

int main(void){
  decoded_instruction_t *decoded = pedix_init_instruction();
  decoded->mode = MODE_32;

  /* tests */
  PREPARE_TEST(1, "add WORD PTR [ecx+esi*1],cx");
  PREPARE_TEST(2, "add DWORD PTR [edx],eax");
  PREPARE_TEST(3, "mov DWORD PTR [eax+0x50],0x11111111");
  PREPARE_TEST(4, "mov DWORD PTR [ecx+edx*2+0x50],0x11111111");
  PREPARE_TEST(5, "mov WORD PTR ss:[ecx-0x00afbc01],ax");
  PREPARE_TEST(6, "lea ecx,DWORD PTR [esp+0x04]");
  PREPARE_TEST(7, "and esp,0xf0");
  PREPARE_TEST(8, "push DWORD PTR [ecx-0x04]");
  PREPARE_TEST(9, "push ebp");
  PREPARE_TEST(10, "mov ebp,esp");
  PREPARE_TEST(11, "push ebx");
  PREPARE_TEST(12, "push ecx");
  PREPARE_TEST(13, "sub esp,0x10");
  PREPARE_TEST(14, "call 0xfffffef1");
  PREPARE_TEST(15, "add ebx,0x00002e50");
  PREPARE_TEST(16, "mov DWORD PTR [ebp-0x0c],0xffff7fbf");
  PREPARE_TEST(17, "mov eax,DWORD PTR [ebp-0x0c]");
  PREPARE_TEST(18, "shr eax,0x1f");
  PREPARE_TEST(19, "cmp eax,0x01");
  PREPARE_TEST(20, "jnz 0x09");
  PREPARE_TEST(21, "mov eax,0x0000002d");
  PREPARE_TEST(22, "jmp 0x07");
  PREPARE_TEST(23, "mov eax,0x0000002b");
  PREPARE_TEST(24, "mov BYTE PTR [ebp-0x0d],al");
  PREPARE_TEST(25, "movsx eax,BYTE PTR [ebp-0x0d]");
  PREPARE_TEST(26, "sub esp,0x08");
  PREPARE_TEST(27, "push eax");
  PREPARE_TEST(28, "lea eax,DWORD PTR [ebx-0x00001fec]");
  PREPARE_TEST(29, "push eax");
  PREPARE_TEST(30, "call 0xfffffe66");
  PREPARE_TEST(31, "add esp,0x10");
  PREPARE_TEST(32, "mov eax,0x80000000");
  PREPARE_TEST(33, "sub eax,DWORD PTR [ebp-0x0c]");
  PREPARE_TEST(34, "mov DWORD PTR [ebp-0x14],eax");
  PREPARE_TEST(35, "sub esp,0x08");
  PREPARE_TEST(36, "push DWORD PTR [ebp-0x14]");
  PREPARE_TEST(37, "lea eax,DWORD PTR [ebx-0x00001fe8]");
  PREPARE_TEST(38, "push eax");
  PREPARE_TEST(39, "call 0xfffffe46");
  PREPARE_TEST(40, "add esp,0x10");
  PREPARE_TEST(41, "mov eax,DWORD PTR [ebp-0x0c]");
  PREPARE_TEST(42, "neg eax");
  PREPARE_TEST(43, "sub esp,0x08");
  PREPARE_TEST(44, "push eax");
  PREPARE_TEST(45, "lea eax,DWORD PTR [ebx-0x00001fe4]");
  PREPARE_TEST(46, "push eax");
  PREPARE_TEST(47, "call 0xfffffe2e");
  PREPARE_TEST(48, "add esp,0x10");
  PREPARE_TEST(49, "sub esp,0x08");
  PREPARE_TEST(50, "push 0x04");
  PREPARE_TEST(51, "lea eax,DWORD PTR [ebx-0x00001fe8]");
  PREPARE_TEST(52, "push eax");
  PREPARE_TEST(53, "call 0xfffffe1a");
  PREPARE_TEST(54, "add esp,0x10");
  PREPARE_TEST(55, "mov eax,0x00000000");
  PREPARE_TEST(56, "lea esp,DWORD PTR [ebp-0x08]");
  PREPARE_TEST(57, "pop ecx");
  PREPARE_TEST(58, "pop ebx");
  PREPARE_TEST(59, "pop ebp");
  PREPARE_TEST(60, "lea esp,DWORD PTR [ecx-0x04]");
  PREPARE_TEST(61, "retn");
  PREPARE_TEST(62, "mov al,cs:[0x44332211]");
  PREPARE_TEST(63, "mov eax,gs:[0x44332211]");
  PREPARE_TEST(64, "mov fs:[0x44332211],al");
  PREPARE_TEST(65, "mov es:[0x44332211],eax");
  PREPARE_TEST(66, "and ecx,DWORD PTR fs:[bx+di-0x0002]"); 
  PREPARE_TEST(67, "add BYTE PTR [0xbbaa],cl");
  PREPARE_TEST(68, "cmp DWORD PTR [bx+di],edx");
  PREPARE_TEST(69, "sbb WORD PTR [di-0x12],dx");
  PREPARE_TEST(70, "crc32 edi,BYTE PTR [bx+si+0x2211]");
  PREPARE_TEST(71, "shld dx,si,0x11");
  PREPARE_TEST(72, "fadd st,st1");
  PREPARE_TEST(73, "fcom st1");
  PREPARE_TEST(74, "fcomp st7");
  PREPARE_TEST(75, "fsub st,st5");
  PREPARE_TEST(76, "fsubr st,st4");
  PREPARE_TEST(77, "fdivr st,st6");
  PREPARE_TEST(78, "fld st2");
  PREPARE_TEST(79, "fxch st6");
  PREPARE_TEST(80, "fst DWORD PTR [eax+edx*1+0x50403020]");
  PREPARE_TEST(81, "fnop");
  PREPARE_TEST(82, "fstp1 st7");
  PREPARE_TEST(83, "fldenv DWORD PTR [edx+0x44332211]");
  PREPARE_TEST(84, "fchs");
  PREPARE_TEST(85, "fabs");
  PREPARE_TEST(86, "ftst");
  PREPARE_TEST(87, "fxam");
  PREPARE_TEST(88, "fldcw WORD PTR [eax]");
  PREPARE_TEST(89, "fld1");
  PREPARE_TEST(90, "fldl2t");
  PREPARE_TEST(91, "fldl2e");
  PREPARE_TEST(92, "fldpi");
  PREPARE_TEST(93, "fldlg2");
  PREPARE_TEST(94, "fldln2");
  PREPARE_TEST(95, "fldz");
  PREPARE_TEST(96, "fnstenv DWORD PTR [eax]");
  PREPARE_TEST(97, "fnstenv DWORD PTR [eax]");
  PREPARE_TEST(98, "f2xm1");
  PREPARE_TEST(99, "fyl2x");
  PREPARE_TEST(100, "fptan");
  PREPARE_TEST(101, "fpatan");
  PREPARE_TEST(102, "fxtract");
  PREPARE_TEST(103, "fprem1");
  PREPARE_TEST(104, "fdecstp");
  PREPARE_TEST(105, "fincstp");
  PREPARE_TEST(106, "fnstcw WORD PTR [eax]");  
  PREPARE_TEST(107, "fwait");  
  PREPARE_TEST(108, "fnstcw WORD PTR [eax]");  
  PREPARE_TEST(109, "fprem");  
  PREPARE_TEST(110, "fyl2xp1");  
  PREPARE_TEST(111, "fsqrt");  
  PREPARE_TEST(112, "fsincos");  
  PREPARE_TEST(113, "frndint");  
  PREPARE_TEST(114, "fscale");  
  PREPARE_TEST(115, "fsin");  
  PREPARE_TEST(116, "fcos");  
  PREPARE_TEST(117, "fcmovb st,st5");  
  PREPARE_TEST(118, "fimul DWORD PTR [eax]");  
  PREPARE_TEST(119, "fcmove st,st7");  
  PREPARE_TEST(120, "ficom DWORD PTR [edx]");  
  PREPARE_TEST(121, "fcmovbe st,st4");  
  PREPARE_TEST(122, "ficomp DWORD PTR [edx]");  
  PREPARE_TEST(123, "fcmovu st,st0");  
  PREPARE_TEST(124, "fisub DWORD PTR [eax]");  
  PREPARE_TEST(125, "fisubr DWORD PTR [eax]");  
  PREPARE_TEST(126, "fucompp");  
  PREPARE_TEST(127, "fidiv DWORD PTR [eax]");  
  PREPARE_TEST(128, "fidivr DWORD PTR [eax]");  
  PREPARE_TEST(129, "fild DWORD PTR [eax]");  
  PREPARE_TEST(130, "fcmovnb st,st2");  
  PREPARE_TEST(131, "fisttp DWORD PTR [eax]");  
  PREPARE_TEST(132, "fcmovne st,st0");  
  PREPARE_TEST(133, "fist DWORD PTR [eax]");  
  PREPARE_TEST(134, "fcmovnbe st,st0");  
  PREPARE_TEST(135, "fistp DWORD PTR [eax]");  
  PREPARE_TEST(136, "fcmovnu st,st0");  
  PREPARE_TEST(137, "fneni nop");  
  PREPARE_TEST(138, "fndisi nop");  
  PREPARE_TEST(139, "fnclex");  
  PREPARE_TEST(140, "fninit");  
  PREPARE_TEST(141, "fnsetpm nop");  
  PREPARE_TEST(142, "fld DWORD PTR [eax]");  
  PREPARE_TEST(143, "fucomi st,st0");  
  PREPARE_TEST(144, "fcomi st,st0");  
  PREPARE_TEST(145, "fstp DWORD PTR [eax]");  
  PREPARE_TEST(146, "fadd QWORD PTR [eax]");  
  PREPARE_TEST(147, "fadd st0,st");  
  PREPARE_TEST(148, "fmul QWORD PTR [eax]");  
  PREPARE_TEST(149, "fmul st0,st");  
  PREPARE_TEST(150, "fcom QWORD PTR [eax]");  
  PREPARE_TEST(151, "fcomp QWORD PTR [eax]");  
  PREPARE_TEST(152, "fsub QWORD PTR [eax]");  
  PREPARE_TEST(153, "fsubr QWORD PTR [eax]");  
  PREPARE_TEST(154, "fsubr st1,st");  
  PREPARE_TEST(155, "fsub st2,st");  
  PREPARE_TEST(156, "fdiv QWORD PTR [eax]");  
  PREPARE_TEST(157, "fdivr st1,st");  
  PREPARE_TEST(158, "fdivr QWORD PTR [eax]");  
  PREPARE_TEST(159, "fdiv st0,st");  
  PREPARE_TEST(160, "fld QWORD PTR [eax]");  
  PREPARE_TEST(161, "ffree st5");  
  PREPARE_TEST(162, "fisttp QWORD PTR [eax]");  
  PREPARE_TEST(163, "fst QWORD PTR [eax]");  
  PREPARE_TEST(164, "fst st3");  
  PREPARE_TEST(165, "fstp QWORD PTR [eax]");  
  PREPARE_TEST(166, "fstp st0");  
  PREPARE_TEST(167, "fucom st0");  
  PREPARE_TEST(168, "fucomp st0");  
  PREPARE_TEST(169, "fnsave DWORD PTR [eax]");  
  PREPARE_TEST(170, "fnstsw WORD PTR [eax]");  
  PREPARE_TEST(171, "fiadd WORD PTR [eax]");  
  PREPARE_TEST(172, "faddp st0,st");  
  PREPARE_TEST(173, "fimul WORD PTR [eax]");  
  PREPARE_TEST(174, "fmulp st0,st");  
  PREPARE_TEST(175, "ficom WORD PTR [eax]");  
  PREPARE_TEST(176, "ficomp WORD PTR [eax]");  
  PREPARE_TEST(177, "fcompp");  
  PREPARE_TEST(178, "fisub WORD PTR [eax]");  
  PREPARE_TEST(179, "fsubrp st0,st");  
  PREPARE_TEST(180, "fisubr WORD PTR [eax]");  
  PREPARE_TEST(181, "fsubp st0,st");  
  PREPARE_TEST(182, "fidiv WORD PTR [eax]");  
  PREPARE_TEST(183, "fdivrp st0,st");  
  PREPARE_TEST(184, "fidivr WORD PTR [eax]");  
  PREPARE_TEST(185, "fdivp st0,st");  
  PREPARE_TEST(186, "fild WORD PTR [eax]");  
  PREPARE_TEST(187, "ffreep st0");  
  PREPARE_TEST(188, "fisttp WORD PTR [eax]");  
  PREPARE_TEST(189, "fist WORD PTR [eax]");  
  PREPARE_TEST(190, "fistp WORD PTR [eax]");  
  PREPARE_TEST(191, "fbld TBYTE PTR [eax]");  
  PREPARE_TEST(192, "fnstsw ax");  
  PREPARE_TEST(193, "fild QWORD PTR [eax]");  
  PREPARE_TEST(194, "fucomip st,st0");  
  PREPARE_TEST(195, "fbstp TBYTE PTR [eax]");  
  PREPARE_TEST(196, "fcomip st,st0");  
  PREPARE_TEST(197, "fistp QWORD PTR [eax]");  
  PREPARE_TEST(198, "loopnz 0x01");  
  PREPARE_TEST(199, "loopz 0x01");  
  PREPARE_TEST(200, "loop 0x01");  
  PREPARE_TEST(201, "jecxz 0x12");  
  PREPARE_TEST(202, "in al,0x10");  
  PREPARE_TEST(203, "in eax,0x10");  
  PREPARE_TEST(204, "out 0x10,al");  
  PREPARE_TEST(205, "out 0x10,eax");  
  PREPARE_TEST(206, "call 0x40302015");  
  PREPARE_TEST(207, "jmp 0x40302015");  
  PREPARE_TEST(208, "jmpf 0x40302015");  
  PREPARE_TEST(209, "jmp 0x00");  
  PREPARE_TEST(210, "in al,dx");  
  PREPARE_TEST(211, "in eax,dx");  
  PREPARE_TEST(212, "out dx,al");  
  PREPARE_TEST(213, "out dx,eax");  
  PREPARE_TEST(214, "int1");  
  PREPARE_TEST(215, "hlt");  
  PREPARE_TEST(216, "cmc");  
  PREPARE_TEST(217, "test BYTE PTR [eax],0x00");  
  PREPARE_TEST(218, "test BYTE PTR [eax],0x00");  
  PREPARE_TEST(219, "not BYTE PTR [eax]");  
  PREPARE_TEST(220, "neg BYTE PTR [eax]");  
  PREPARE_TEST(221, "mul BYTE PTR [eax]");  
  PREPARE_TEST(222, "imul BYTE PTR [eax]");  
  PREPARE_TEST(223, "div BYTE PTR [eax]");  
  PREPARE_TEST(224, "idiv BYTE PTR [eax]");  
  PREPARE_TEST(225, "test DWORD PTR [eax],0x44332211");  
  PREPARE_TEST(226, "test DWORD PTR [eax],0x44332211");  
  PREPARE_TEST(227, "not DWORD PTR [eax]");  
  PREPARE_TEST(228, "neg DWORD PTR [eax]");  
  PREPARE_TEST(229, "mul DWORD PTR [eax]");  
  PREPARE_TEST(230, "imul DWORD PTR [eax]");  
  PREPARE_TEST(231, "div DWORD PTR [eax]");  
  PREPARE_TEST(232, "idiv DWORD PTR [eax]");  
  PREPARE_TEST(233, "clc");  
  PREPARE_TEST(234, "stc");  
  PREPARE_TEST(235, "cli");  
  PREPARE_TEST(236, "sti");  
  PREPARE_TEST(237, "cld");  
  PREPARE_TEST(238, "std");  
  PREPARE_TEST(239, "inc BYTE PTR [eax]");  
  PREPARE_TEST(240, "dec BYTE PTR [eax]");  
  PREPARE_TEST(241, "inc eax");  
  PREPARE_TEST(242, "dec eax");  
  PREPARE_TEST(243, "call ecx");  
  PREPARE_TEST(244, "call FWORD PTR [ecx+0x11]");  
  PREPARE_TEST(245, "jmp ecx");  
  PREPARE_TEST(246, "jmp FWORD PTR [eax]");  
  PREPARE_TEST(247, "push edx");  
  PREPARE_TEST(248, "sldt WORD PTR [ecx]");
  PREPARE_TEST(249, "str WORD PTR [eax]");
  PREPARE_TEST(250, "lldt WORD PTR [eax]");

  puts(GREEN"All tests are passed!"NC);
  pedix_free_instrucion(decoded);
  return 0;
}

