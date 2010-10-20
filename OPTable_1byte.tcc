/*
Copyright (C) 2006 - 2009 Evan Teran
                   eteran@alum.rit.edu

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#ifndef OPTABLE_1BYTE_20080314_TCC_
#define OPTABLE_1BYTE_20080314_TCC_

#include "Operand.h"

template <class Model>
const typename Instruction<Model>::OpcodeEntry Instruction<Model>::Opcodes[0x100] = {

	/* 0x00 - 0x0f */
	{ "add", &Instruction::decode_Eb_Gb, OP_ADD },
	{ "add", &Instruction::decode_Ev_Gv, OP_ADD },
	{ "add", &Instruction::decode_Gb_Eb, OP_ADD },
	{ "add", &Instruction::decode_Gv_Ev, OP_ADD },
	{ "add", &Instruction::decode_AL_Ib, OP_ADD },
	{ "add", &Instruction::decode_rAX_Iz, OP_ADD },
	{ "push", &Instruction::decode_SegES, OP_PUSH },	// ia-32 only
	{ "pop", &Instruction::decode_SegES, OP_POP },	// ia-32 only
	{ "or", &Instruction::decode_Eb_Gb, OP_OR },
	{ "or", &Instruction::decode_Ev_Gv, OP_OR },
	{ "or", &Instruction::decode_Gb_Eb, OP_OR },
	{ "or", &Instruction::decode_Gv_Ev, OP_OR },
	{ "or", &Instruction::decode_AL_Ib, OP_OR },
	{ "or", &Instruction::decode_rAX_Iz, OP_OR },
	{ "push", &Instruction::decode_SegCS, OP_PUSH },	// ia-32 only
	{ "2byte", &Instruction::decode_2byte, OP_2BYTE },
	
	/* 0x10 - 0x1f */
	{ "adc", &Instruction::decode_Eb_Gb, OP_ADC },
	{ "adc", &Instruction::decode_Ev_Gv, OP_ADC },
	{ "adc", &Instruction::decode_Gb_Eb, OP_ADC },
	{ "adc", &Instruction::decode_Gv_Ev, OP_ADC },
	{ "adc", &Instruction::decode_AL_Ib, OP_ADC },
	{ "adc", &Instruction::decode_rAX_Iz, OP_ADC },
	{ "push", &Instruction::decode_SegSS, OP_PUSH },	// ia-32 only
	{ "pop", &Instruction::decode_SegSS, OP_POP },		// ia-32 only
	{ "sbb", &Instruction::decode_Eb_Gb, OP_SBB },
	{ "sbb", &Instruction::decode_Ev_Gv, OP_SBB },
	{ "sbb", &Instruction::decode_Gb_Eb, OP_SBB },
	{ "sbb", &Instruction::decode_Gv_Ev, OP_SBB },
	{ "sbb", &Instruction::decode_AL_Ib, OP_SBB },
	{ "sbb", &Instruction::decode_rAX_Iz, OP_SBB },
	{ "push", &Instruction::decode_SegDS, OP_PUSH },	// ia-32 only
	{ "pop", &Instruction::decode_SegDS, OP_POP },	// ia-32 only
	
	/* 0x20 - 0x2f */
	{ "and", &Instruction::decode_Eb_Gb, OP_AND }, 
	{ "and", &Instruction::decode_Ev_Gv, OP_AND }, 
	{ "and", &Instruction::decode_Gb_Eb, OP_AND }, 
	{ "and", &Instruction::decode_Gv_Ev, OP_AND }, 
	{ "and", &Instruction::decode_AL_Ib, OP_AND }, 
	{ "and", &Instruction::decode_rAX_Iz, OP_AND }, 
	{ "prefix es", &Instruction::decode_invalid, OP_PREFIX },
	{ "daa", &Instruction::decode0, OP_DAA }, 						// ia-32 only
	{ "sub", &Instruction::decode_Eb_Gb, OP_SUB }, 
	{ "sub", &Instruction::decode_Ev_Gv, OP_SUB }, 
	{ "sub", &Instruction::decode_Gb_Eb, OP_SUB }, 
	{ "sub", &Instruction::decode_Gv_Ev, OP_SUB }, 
	{ "sub", &Instruction::decode_AL_Ib, OP_SUB }, 
	{ "sub", &Instruction::decode_rAX_Iz, OP_SUB }, 
	{ "prefix cs", &Instruction::decode_invalid, OP_PREFIX },
	{ "das", &Instruction::decode0, OP_DAS },						// ia-32 only
	
	/* 0x30 - 0x3f */
	{ "xor", &Instruction::decode_Eb_Gb, OP_XOR },
	{ "xor", &Instruction::decode_Ev_Gv, OP_XOR },
	{ "xor", &Instruction::decode_Gb_Eb, OP_XOR },
	{ "xor", &Instruction::decode_Gv_Ev, OP_XOR },
	{ "xor", &Instruction::decode_AL_Ib, OP_XOR },
	{ "xor", &Instruction::decode_rAX_Iz, OP_XOR },
	{ "prefix ss", &Instruction::decode_invalid, OP_PREFIX },
	{ "aaa", &Instruction::decode0, OP_AAA },						// ia-32 only
	{ "cmp", &Instruction::decode_Eb_Gb, OP_CMP },
	{ "cmp", &Instruction::decode_Ev_Gv, OP_CMP },
	{ "cmp", &Instruction::decode_Gb_Eb, OP_CMP },
	{ "cmp", &Instruction::decode_Gv_Ev, OP_CMP },
	{ "cmp", &Instruction::decode_AL_Ib, OP_CMP },
	{ "cmp", &Instruction::decode_rAX_Iz, OP_CMP },
	{ "prefix ds", &Instruction::decode_invalid, OP_PREFIX },
	{ "aas", &Instruction::decode0, OP_AAS },						// ia-32 only
	
	/* 0x40 - 0x4f */
	{ "inc", &Instruction::decode_rAX, OP_INC },	// ia-32 only (REX byte)
	{ "inc", &Instruction::decode_rCX, OP_INC },	// ia-32 only (REX byte)
	{ "inc", &Instruction::decode_rDX, OP_INC },	// ia-32 only (REX byte)
	{ "inc", &Instruction::decode_rBX, OP_INC },	// ia-32 only (REX byte)
	{ "inc", &Instruction::decode_rSP, OP_INC },	// ia-32 only (REX byte)
	{ "inc", &Instruction::decode_rBP, OP_INC },	// ia-32 only (REX byte)
	{ "inc", &Instruction::decode_rSI, OP_INC },	// ia-32 only (REX byte)
	{ "inc", &Instruction::decode_rDI, OP_INC },	// ia-32 only (REX byte)
	{ "dec", &Instruction::decode_rAX, OP_DEC },	// ia-32 only (REX byte)
	{ "dec", &Instruction::decode_rCX, OP_DEC },	// ia-32 only (REX byte)
	{ "dec", &Instruction::decode_rDX, OP_DEC },	// ia-32 only (REX byte)
	{ "dec", &Instruction::decode_rBX, OP_DEC },	// ia-32 only (REX byte)
	{ "dec", &Instruction::decode_rSP, OP_DEC },	// ia-32 only (REX byte)
	{ "dec", &Instruction::decode_rBP, OP_DEC },	// ia-32 only (REX byte)
	{ "dec", &Instruction::decode_rSI, OP_DEC },	// ia-32 only (REX byte)
	{ "dec", &Instruction::decode_rDI, OP_DEC },	// ia-32 only (REX byte)

	/* 0x50 - 0x5f */
	{ "push", &Instruction::decode_rAX, OP_PUSH },
	{ "push", &Instruction::decode_rCX, OP_PUSH },
	{ "push", &Instruction::decode_rDX, OP_PUSH },
	{ "push", &Instruction::decode_rBX, OP_PUSH },
	{ "push", &Instruction::decode_rSP, OP_PUSH },
	{ "push", &Instruction::decode_rBP, OP_PUSH },
	{ "push", &Instruction::decode_rSI, OP_PUSH },
	{ "push", &Instruction::decode_rDI, OP_PUSH },
	{ "pop", &Instruction::decode_rAX, OP_POP },
	{ "pop", &Instruction::decode_rCX, OP_POP },
	{ "pop", &Instruction::decode_rDX, OP_POP },
	{ "pop", &Instruction::decode_rBX, OP_POP },
	{ "pop", &Instruction::decode_rSP, OP_POP },
	{ "pop", &Instruction::decode_rBP, OP_POP },
	{ "pop", &Instruction::decode_rSI, OP_POP },
	{ "pop", &Instruction::decode_rDI, OP_POP },
	
	/* 0x60 - 0x6f */
	{ "pushaw/pushad", &Instruction::decode_pushaw_pushad_invalid, OP_PUSHA },	// ia-32 only
	{ "popaw/popad", &Instruction::decode_popaw_popad_invalid, OP_POPA },		// ia-32 only
	{ "bound", &Instruction::decode_Gv_Ma, OP_BOUND },					// ia-32 only
	{ "arpl", &Instruction::decode_Ew_Gw, OP_ARPL },					// x86-64: movsxd Gv,Ev
	{ "prefix fs", &Instruction::decode_invalid, OP_PREFIX },
	{ "prefix gs", &Instruction::decode_invalid, OP_PREFIX },
	{ "prefix data16", &Instruction::decode_invalid, OP_PREFIX },
	{ "prefix addr16", &Instruction::decode_invalid, OP_PREFIX },
	{ "push", &Instruction::decode_Iz, OP_PUSH },
	{ "imul", &Instruction::decode_Gv_Ev_Iz, OP_IMUL },
	{ "push", &Instruction::decode_Ib, OP_PUSH },
	{ "imul", &Instruction::decode_Gv_Ev_Ib, OP_IMUL },
	{ "insb", &Instruction::decode0, OP_INS },
	{ "insw/insd", &Instruction::decode_insw_insd_invalid, OP_INS },
	{ "outsb", &Instruction::decode0, OP_OUTS },
	{ "outsw/outsd", &Instruction::decode_outsw_outsd_invalid, OP_OUTS },
		
	/* 0x70 - 0x7f */
	{ "jo", &Instruction::decode_Jb, OP_JCC },
	{ "jno", &Instruction::decode_Jb, OP_JCC },
	{ "jb", &Instruction::decode_Jb, OP_JCC },
	{ "jnb", &Instruction::decode_Jb, OP_JCC },
	{ "jz", &Instruction::decode_Jb, OP_JCC },
	{ "jnz", &Instruction::decode_Jb, OP_JCC },
	{ "jbe", &Instruction::decode_Jb, OP_JCC },
	{ "jnbe", &Instruction::decode_Jb, OP_JCC },
	{ "js", &Instruction::decode_Jb, OP_JCC },
	{ "jns", &Instruction::decode_Jb, OP_JCC },
	{ "jp", &Instruction::decode_Jb, OP_JCC },
	{ "jnp", &Instruction::decode_Jb, OP_JCC },
	{ "jl", &Instruction::decode_Jb, OP_JCC },
	{ "jnl", &Instruction::decode_Jb, OP_JCC },
	{ "jle", &Instruction::decode_Jb, OP_JCC },
	{ "jnle", &Instruction::decode_Jb, OP_JCC },
	
	/* 0x80 - 0x8f */
	{ "group1", &Instruction::decode_group1, OP_GROUP1 },
	{ "group1", &Instruction::decode_group1, OP_GROUP1 },
	{ "group1", &Instruction::decode_group1, OP_GROUP1 },				// ia-32 only
	{ "group1", &Instruction::decode_group1, OP_GROUP1 },
	{ "test", &Instruction::decode_Eb_Gb, OP_TEST },
	{ "test", &Instruction::decode_Ev_Gv, OP_TEST },
	{ "xchg", &Instruction::decode_Gb_Eb, OP_XCHG },
	{ "xchg", &Instruction::decode_Gv_Ev, OP_XCHG },
	{ "mov", &Instruction::decode_Eb_Gb, OP_MOV },
	{ "mov", &Instruction::decode_Ev_Gv, OP_MOV },
	{ "mov", &Instruction::decode_Gb_Eb, OP_MOV },
	{ "mov", &Instruction::decode_Gv_Ev, OP_MOV },
	{ "mov", &Instruction::decode_Ev_Sw, OP_MOV },
	{ "lea", &Instruction::decode_Gv_M, OP_LEA },
	{ "mov", &Instruction::decode_Sw_Ew, OP_MOV },
	{ "group10", &Instruction::decode_group10, OP_GROUP10 },
	
	/* 0x90 - 0x9f */
	{ "xchg", &Instruction::decode_rAX_rAX_NOREX, OP_XCHG },
	{ "xchg", &Instruction::decode_rCX_rAX_NOREX, OP_XCHG },
	{ "xchg", &Instruction::decode_rDX_rAX_NOREX, OP_XCHG },
	{ "xchg", &Instruction::decode_rBX_rAX_NOREX, OP_XCHG },
	{ "xchg", &Instruction::decode_rSP_rAX_NOREX, OP_XCHG },
	{ "xchg", &Instruction::decode_rBP_rAX_NOREX, OP_XCHG },
	{ "xchg", &Instruction::decode_rSI_rAX_NOREX, OP_XCHG },
	{ "xchg", &Instruction::decode_rDI_rAX_NOREX, OP_XCHG },
	{ "cbw/cwde/cdqe", &Instruction::decode_cbw_cwde_cdqe, OP_CWDE },
	{ "cwd/cdq/cqo", &Instruction::decode_cwd_cdq_cqo, OP_CDQ },
	{ "callf", &Instruction::decode_Ap, OP_CALL },					// ia-32 only
	{ "wait", &Instruction::decode0, OP_WAIT },
	{ "pushfw/pushfd/pushfq", &Instruction::decode_pushfw_pushfd_pushfq, OP_PUSHF },
	{ "popfw/popfd/popfq", &Instruction::decode_popfw_popfd_popfq, OP_POPF },
	{ "sahf", &Instruction::decode0, OP_SAHF },
	{ "lahf", &Instruction::decode0, OP_LAHF },
	
	/* 0xa0 - 0xaf */
	{ "mov", &Instruction::decode_AL_Ob, OP_MOV },
	{ "mov", &Instruction::decode_rAX_Ov, OP_MOV },
	{ "mov", &Instruction::decode_Ob_AL, OP_MOV },
	{ "mov", &Instruction::decode_Ov_rAX, OP_MOV },
	{ "movsb", &Instruction::decode0, OP_MOVS },
	{ "movsw/movsd/movsq", &Instruction::decode_movsw_movsd_movsq, OP_MOVS },
	{ "cmpsb", &Instruction::decode0, OP_CMPS },
	{ "cmpsw/cmpsd", &Instruction::decode_cmpsw_cmpsd_invalid, OP_CMPS },
	{ "test", &Instruction::decode_AL_Ib, OP_TEST },
	{ "test", &Instruction::decode_rAX_Iz, OP_TEST },
	{ "stosb", &Instruction::decode0, OP_STOS },
	{ "stosw/stosd/stosq", &Instruction::decode_stosw_stosd_stosq, OP_STOS },
	{ "lodsb", &Instruction::decode0, OP_LODS },
	{ "lodsw/lodsd/lodsq", &Instruction::decode_lodsw_lodsd_lodsq, OP_LODS },
	{ "scasb", &Instruction::decode0, OP_SCAS },
	{ "scasw/scasd/scasq", &Instruction::decode_scasw_scasd_scasq, OP_SCAS },
	
	/* 0xb0 - 0xbf */
	{ "mov", &Instruction::decode_AL_Ib, OP_MOV },
	{ "mov", &Instruction::decode_CL_Ib, OP_MOV },
	{ "mov", &Instruction::decode_DL_Ib, OP_MOV },
	{ "mov", &Instruction::decode_BL_Ib, OP_MOV },
	{ "mov", &Instruction::decode_AH_Ib, OP_MOV },
	{ "mov", &Instruction::decode_CH_Ib, OP_MOV },
	{ "mov", &Instruction::decode_DH_Ib, OP_MOV },
	{ "mov", &Instruction::decode_BH_Ib, OP_MOV },
	{ "mov", &Instruction::decode_rAX_Iv, OP_MOV },	
	{ "mov", &Instruction::decode_rCX_Iv, OP_MOV },
	{ "mov", &Instruction::decode_rDX_Iv, OP_MOV },
	{ "mov", &Instruction::decode_rBX_Iv, OP_MOV },
	{ "mov", &Instruction::decode_rSP_Iv, OP_MOV },
	{ "mov", &Instruction::decode_rBP_Iv, OP_MOV },
	{ "mov", &Instruction::decode_rSI_Iv, OP_MOV },
	{ "mov", &Instruction::decode_rDI_Iv, OP_MOV },
	
	/* 0xc0 - 0xcf */
	{ "group2", &Instruction::decode_group2, OP_GROUP2 },
	{ "group2", &Instruction::decode_group2, OP_GROUP2 },
	{ "ret", &Instruction::decode_Iw, OP_RET },
	{ "ret", &Instruction::decode0, OP_RET },
	{ "les", &Instruction::decode_Gz_Mp, OP_LES },				// ia-32 only
	{ "lds", &Instruction::decode_Gz_Mp, OP_LDS },				// ia-32 only
	{ "group12", &Instruction::decode_group12, OP_GROUP12 },
	{ "group12", &Instruction::decode_group12, OP_GROUP12 },
	{ "enter", &Instruction::decode_Iw_Ib, OP_ENTER },
	{ "leave", &Instruction::decode0, OP_LEAVE },
	{ "retf", &Instruction::decode_Iw, OP_RETF },
	{ "retf", &Instruction::decode0, OP_RETF },
	{ "int3", &Instruction::decode0, OP_INT3 },
	{ "int", &Instruction::decode_Ib, OP_INT },
	{ "into", &Instruction::decode0, OP_INTO },					// ia-32 only
	{ "iretw/iret/iretq", &Instruction::decode_iretw_iret_iretq, OP_IRET },
	
	/* 0xd0 - 0xdf */
	{ "group2", &Instruction::decode_group2D, OP_GROUP2 },
	{ "group2", &Instruction::decode_group2D, OP_GROUP2 },
	{ "group2", &Instruction::decode_group2D, OP_GROUP2 },
	{ "group2", &Instruction::decode_group2D, OP_GROUP2 },
	{ "aam", &Instruction::decode_Ib, OP_AAM },					// ia-32 only
	{ "aad", &Instruction::decode_Ib, OP_AAD },					// ia-32 only
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "xlat", &Instruction::decode0, OP_XLAT },
	{ "esc0", &Instruction::decode_x87, OP_FPU },
	{ "esc1", &Instruction::decode_x87, OP_FPU },
	{ "esc2", &Instruction::decode_x87, OP_FPU },
	{ "esc3", &Instruction::decode_x87, OP_FPU },
	{ "esc4", &Instruction::decode_x87, OP_FPU },
	{ "esc5", &Instruction::decode_x87, OP_FPU },
	{ "esc6", &Instruction::decode_x87, OP_FPU },
	{ "esc7", &Instruction::decode_x87, OP_FPU },
	
	/* 0xe0 - 0xef */
	{ "loopne", &Instruction::decode_Jb, OP_LOOPNE },
	{ "loope", &Instruction::decode_Jb, OP_LOOPE },
	{ "loop", &Instruction::decode_Jb, OP_LOOP },
	{ "jcez", &Instruction::decode_Jb, OP_JCC },
	{ "in", &Instruction::decode_AL_Ib, OP_IN },		
	{ "in", &Instruction::decode_eAX_Ib, OP_IN },
	{ "out", &Instruction::decode_Ib_AL, OP_OUT },
	{ "out", &Instruction::decode_Ib_eAX, OP_OUT },
	{ "call", &Instruction::decode_Jz, OP_CALL },
	{ "jmp", &Instruction::decode_Jz, OP_JMP },
	{ "jmp", &Instruction::decode_Ap, OP_JMP },					// ia-32 only
	{ "jmp", &Instruction::decode_Jb, OP_JMP },
	{ "in", &Instruction::decode_AL_DX, OP_IN },
	{ "in", &Instruction::decode_eAX_DX, OP_IN },
	{ "out", &Instruction::decode_DX_AL, OP_OUT },
	{ "out", &Instruction::decode_DX_eAX, OP_OUT },
	
	/* 0xf0 - 0xff */
	{ "prefix lock", &Instruction::decode_invalid, OP_PREFIX },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "prefix repne", &Instruction::decode_invalid, OP_PREFIX },
	{ "prefix rep", &Instruction::decode_invalid, OP_PREFIX },
	{ "hlt", &Instruction::decode0, OP_HLT },
	{ "cmc", &Instruction::decode0, OP_CMC },
	{ "group3", &Instruction::decode_group3, OP_GROUP3 },
	{ "group3", &Instruction::decode_group3, OP_GROUP3 },
	{ "clc", &Instruction::decode0, OP_CLC },
	{ "stc", &Instruction::decode0, OP_STC },
	{ "cli", &Instruction::decode0, OP_CLI },
	{ "sti", &Instruction::decode0, OP_STI },
	{ "cld", &Instruction::decode0, OP_CLD },
	{ "std", &Instruction::decode0, OP_STD },
	{ "group4", &Instruction::decode_group4, OP_GROUP4 },
	{ "group5", &Instruction::decode_group5, OP_GROUP5 }
};

#endif
