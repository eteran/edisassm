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

#include "Instruction.h"

#ifndef INSTRUCTION64_20070427_TCC_
#define INSTRUCTION64_20070427_TCC_

template <>
const Instruction<edisassm::x86_64>::OpcodeEntry Instruction<edisassm::x86_64>::Opcodes_Group7A[64] = {
	{ "vmcall", &Instruction::decode0, OP_VMCALL },
	{ "vmlaunch", &Instruction::decode0, OP_VMLAUNCH },
	{ "vmresume", &Instruction::decode0, OP_VMRESUME },
	{ "vmxoff", &Instruction::decode0, OP_VMXOFF },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	
	{ "monitor", &Instruction::decode0, OP_MONITOR },
	{ "mwait", &Instruction::decode0, OP_MWAIT },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	
	{ "xgetbv", &Instruction::decode0, OP_XGETBV },
	{ "xsetbv", &Instruction::decode0, OP_XSETBV },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },	
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },	
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	
	{ "smsw", &Instruction::decode_Rv_Mw, OP_SMSW },
	{ "smsw", &Instruction::decode_Rv_Mw, OP_SMSW },
	{ "smsw", &Instruction::decode_Rv_Mw, OP_SMSW },
	{ "smsw", &Instruction::decode_Rv_Mw, OP_SMSW },
	{ "smsw", &Instruction::decode_Rv_Mw, OP_SMSW },
	{ "smsw", &Instruction::decode_Rv_Mw, OP_SMSW },
	{ "smsw", &Instruction::decode_Rv_Mw, OP_SMSW },
	{ "smsw", &Instruction::decode_Rv_Mw, OP_SMSW },
	
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },	
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	
	{ "lmsw", &Instruction::decode_Ew, OP_LMSW },
	{ "lmsw", &Instruction::decode_Ew, OP_LMSW },
	{ "lmsw", &Instruction::decode_Ew, OP_LMSW },
	{ "lmsw", &Instruction::decode_Ew, OP_LMSW },
	{ "lmsw", &Instruction::decode_Ew, OP_LMSW },
	{ "lmsw", &Instruction::decode_Ew, OP_LMSW },
	{ "lmsw", &Instruction::decode_Ew, OP_LMSW },
	{ "lmsw", &Instruction::decode_Ew, OP_LMSW },
	
	{ "swapgs", &Instruction::decode0, OP_SWAPGS },	// x86: invalid
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },	
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID }
};

template <>
const Instruction<edisassm::x86_64>::OpcodeEntry Instruction<edisassm::x86_64>::Opcodes[0x100] = {

	/* 0x00 - 0x0f */
	{ "add", &Instruction::decode_Eb_Gb, OP_ADD },
	{ "add", &Instruction::decode_Ev_Gv, OP_ADD },
	{ "add", &Instruction::decode_Gb_Eb, OP_ADD },
	{ "add", &Instruction::decode_Gv_Ev, OP_ADD },
	{ "add", &Instruction::decode_AL_Ib, OP_ADD },
	{ "add", &Instruction::decode_rAX_Iz, OP_ADD },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },	// ia-32 only
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },	// ia-32 only
	{ "or", &Instruction::decode_Eb_Gb, OP_OR },
	{ "or", &Instruction::decode_Ev_Gv, OP_OR },
	{ "or", &Instruction::decode_Gb_Eb, OP_OR },
	{ "or", &Instruction::decode_Gv_Ev, OP_OR },
	{ "or", &Instruction::decode_AL_Ib, OP_OR },
	{ "or", &Instruction::decode_rAX_Iz, OP_OR },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },	// ia-32 only
	{ "2byte", &Instruction::decode_2byte, OP_2BYTE },
	
	/* 0x10 - 0x1f */
	{ "adc", &Instruction::decode_Eb_Gb, OP_ADC },
	{ "adc", &Instruction::decode_Ev_Gv, OP_ADC },
	{ "adc", &Instruction::decode_Gb_Eb, OP_ADC },
	{ "adc", &Instruction::decode_Gv_Ev, OP_ADC },
	{ "adc", &Instruction::decode_AL_Ib, OP_ADC },
	{ "adc", &Instruction::decode_rAX_Iz, OP_ADC },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },	// ia-32 only
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },	// ia-32 only
	{ "sbb", &Instruction::decode_Eb_Gb, OP_SBB },
	{ "sbb", &Instruction::decode_Ev_Gv, OP_SBB },
	{ "sbb", &Instruction::decode_Gb_Eb, OP_SBB },
	{ "sbb", &Instruction::decode_Gv_Ev, OP_SBB },
	{ "sbb", &Instruction::decode_AL_Ib, OP_SBB },
	{ "sbb", &Instruction::decode_rAX_Iz, OP_SBB },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },	// ia-32 only
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },	// ia-32 only
	
	/* 0x20 - 0x2f */
	{ "and", &Instruction::decode_Eb_Gb, OP_AND }, 
	{ "and", &Instruction::decode_Ev_Gv, OP_AND }, 
	{ "and", &Instruction::decode_Gb_Eb, OP_AND }, 
	{ "and", &Instruction::decode_Gv_Ev, OP_AND }, 
	{ "and", &Instruction::decode_AL_Ib, OP_AND }, 
	{ "and", &Instruction::decode_rAX_Iz, OP_AND }, 
	{ "prefix es", &Instruction::decode_invalid, OP_PREFIX },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },	// ia-32 only
	{ "sub", &Instruction::decode_Eb_Gb, OP_SUB }, 
	{ "sub", &Instruction::decode_Ev_Gv, OP_SUB }, 
	{ "sub", &Instruction::decode_Gb_Eb, OP_SUB }, 
	{ "sub", &Instruction::decode_Gv_Ev, OP_SUB }, 
	{ "sub", &Instruction::decode_AL_Ib, OP_SUB }, 
	{ "sub", &Instruction::decode_rAX_Iz, OP_SUB }, 
	{ "prefix cs", &Instruction::decode_invalid, OP_PREFIX },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },	// ia-32 only
	
	/* 0x30 - 0x3f */
	{ "xor", &Instruction::decode_Eb_Gb, OP_XOR },
	{ "xor", &Instruction::decode_Ev_Gv, OP_XOR },
	{ "xor", &Instruction::decode_Gb_Eb, OP_XOR },
	{ "xor", &Instruction::decode_Gv_Ev, OP_XOR },
	{ "xor", &Instruction::decode_AL_Ib, OP_XOR },
	{ "xor", &Instruction::decode_rAX_Iz, OP_XOR },
	{ "prefix ss", &Instruction::decode_invalid, OP_PREFIX },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },	// ia-32 only
	{ "cmp", &Instruction::decode_Eb_Gb, OP_CMP },
	{ "cmp", &Instruction::decode_Ev_Gv, OP_CMP },
	{ "cmp", &Instruction::decode_Gb_Eb, OP_CMP },
	{ "cmp", &Instruction::decode_Gv_Ev, OP_CMP },
	{ "cmp", &Instruction::decode_AL_Ib, OP_CMP },
	{ "cmp", &Instruction::decode_rAX_Iz, OP_CMP },
	{ "prefix ds", &Instruction::decode_invalid, OP_PREFIX },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },	// ia-32 only
	
	/* 0x40 - 0x4f */
	{ "prefix rex", &Instruction::decode_invalid, OP_PREFIX },	// ia-32 only (REX byte)
	{ "prefix rex", &Instruction::decode_invalid, OP_PREFIX },	// ia-32 only (REX byte)
	{ "prefix rex", &Instruction::decode_invalid, OP_PREFIX },	// ia-32 only (REX byte)
	{ "prefix rex", &Instruction::decode_invalid, OP_PREFIX },	// ia-32 only (REX byte)
	{ "prefix rex", &Instruction::decode_invalid, OP_PREFIX },	// ia-32 only (REX byte)
	{ "prefix rex", &Instruction::decode_invalid, OP_PREFIX },	// ia-32 only (REX byte)
	{ "prefix rex", &Instruction::decode_invalid, OP_PREFIX },	// ia-32 only (REX byte)
	{ "prefix rex", &Instruction::decode_invalid, OP_PREFIX },	// ia-32 only (REX byte)
	{ "prefix rex", &Instruction::decode_invalid, OP_PREFIX },	// ia-32 only (REX byte)
	{ "prefix rex", &Instruction::decode_invalid, OP_PREFIX },	// ia-32 only (REX byte)
	{ "prefix rex", &Instruction::decode_invalid, OP_PREFIX },	// ia-32 only (REX byte)
	{ "prefix rex", &Instruction::decode_invalid, OP_PREFIX },	// ia-32 only (REX byte)
	{ "prefix rex", &Instruction::decode_invalid, OP_PREFIX },	// ia-32 only (REX byte)
	{ "prefix rex", &Instruction::decode_invalid, OP_PREFIX },	// ia-32 only (REX byte)
	{ "prefix rex", &Instruction::decode_invalid, OP_PREFIX },	// ia-32 only (REX byte)
	{ "prefix rex", &Instruction::decode_invalid, OP_PREFIX },	// ia-32 only (REX byte)

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
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },	// ia-32 only
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },	// ia-32 only
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },	// ia-32 only
	{ "movsxd", &Instruction::decode_Gv_Ev, OP_MOVSXD },			// x86: arpl Ew,Gw
	{ "prefix fs", &Instruction::decode_invalid, OP_PREFIX },
	{ "prefix gs", &Instruction::decode_invalid, OP_PREFIX },
	{ "prefix data16", &Instruction::decode_invalid, OP_PREFIX },
	{ "prefix addr16", &Instruction::decode_invalid, OP_PREFIX },
	{ "push", &Instruction::decode_Iz, OP_PUSH },
	{ "imul", &Instruction::decode_Gv_Ev_Iz, OP_IMUL },
	{ "push", &Instruction::decode_Ib, OP_PUSH },
	{ "imul", &Instruction::decode_Gv_Ev_Ib, OP_IMUL },
	{ "insb",  &Instruction::decode0, OP_INS },
	{ "insw/insd",  &Instruction::decode_insw_insd_invalid, OP_INS },
	{ "outsb",  &Instruction::decode0, OP_OUTS },
	{ "outsw/outsd",  &Instruction::decode_outsw_outsd_invalid, OP_OUTS },
		
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
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },	// ia-32 only
	{ "group1", &Instruction::decode_group1, OP_GROUP1 },
	{ "test",  &Instruction::decode_Eb_Gb, OP_TEST },
	{ "test",  &Instruction::decode_Ev_Gv, OP_TEST },
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
	{ "xchg",  &Instruction::decode_rAX_rAX_NOREX, OP_XCHG },
	{ "xchg",  &Instruction::decode_rCX_rAX_NOREX, OP_XCHG },
	{ "xchg",  &Instruction::decode_rDX_rAX_NOREX, OP_XCHG },
	{ "xchg",  &Instruction::decode_rBX_rAX_NOREX, OP_XCHG },
	{ "xchg",  &Instruction::decode_rSP_rAX_NOREX, OP_XCHG },
	{ "xchg",  &Instruction::decode_rBP_rAX_NOREX, OP_XCHG },
	{ "xchg",  &Instruction::decode_rSI_rAX_NOREX, OP_XCHG },
	{ "xchg",  &Instruction::decode_rDI_rAX_NOREX, OP_XCHG },
	{ "cbw/cwde/cdqe",  &Instruction::decode_cbw_cwde_cdqe, OP_CWDE },
	{ "cwd/cdq/cqo",  &Instruction::decode_cwd_cdq_cqo, OP_CDQ },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },	// ia-32 only
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
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },	// ia-32 only
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },	// ia-32 only
	{ "group12", &Instruction::decode_group12, OP_GROUP12 },
	{ "group12", &Instruction::decode_group12, OP_GROUP12 },
	{ "enter", &Instruction::decode_Iw_Ib, OP_ENTER },
	{ "leave", &Instruction::decode0, OP_LEAVE },
	{ "retf", &Instruction::decode_Iw, OP_RETF },
	{ "retf", &Instruction::decode0, OP_RETF },
	{ "int3", &Instruction::decode0, OP_INT3 },
	{ "int", &Instruction::decode_Ib, OP_INT },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },	// ia-32 only
	{ "iretw/iret/iretq", &Instruction::decode_iretw_iret_iretq, OP_IRET },
	
	/* 0xd0 - 0xdf */
	{ "group2", &Instruction::decode_group2D, OP_GROUP2 },
	{ "group2", &Instruction::decode_group2D, OP_GROUP2 },
	{ "group2", &Instruction::decode_group2D, OP_GROUP2 },
	{ "group2", &Instruction::decode_group2D, OP_GROUP2 },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },	// ia-32 only
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },	// ia-32 only
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
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },	// ia-32 only
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


template <>
const Instruction<edisassm::x86_64>::OpcodeEntry Instruction<edisassm::x86_64>::Opcodes_2Byte_NA[0x100] = {

	/* 0x0f 0x00 - 0x0f 0x0f */
	{ "group6", &Instruction::decode_group6, OP_GROUP6 },
	{ "group7", &Instruction::decode_group7, OP_GROUP7 },
	{ "lar", &Instruction::decode_Gv_Ew, OP_LAR },
	{ "lsl", &Instruction::decode_Gv_Ew, OP_LSL },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "syscall", &Instruction::decode0, OP_SYSCALL },
	{ "clts", &Instruction::decode0, OP_CLTS },
	{ "sysret", &Instruction::decode0, OP_SYSRET },
	{ "invd", &Instruction::decode0, OP_INVD },
	{ "wbinvd", &Instruction::decode0, OP_WBINVD },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "ud2", &Instruction::decode0, OP_UD2 },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "nop", &Instruction::decode_Ev, OP_NOP },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	
	/* 0x0f 0x10 - 0x0f 0x1f */
	{ "movups", &Instruction::decode_Vo_Wo, OP_MOVUPS },
	{ "movups", &Instruction::decode_Wo_Vo, OP_MOVUPS },
	{ "movlps", &Instruction::decode_Vq_Mq, OP_MOVLPS },
	{ "movlps", &Instruction::decode_Mq_Vq, OP_MOVLPS },
	{ "unpcklps", &Instruction::decode_Vo_Wq, OP_UNPCKLPS },
	{ "unpckhps", &Instruction::decode_Vo_Wq, OP_UNPCKHPS },
	{ "movhps", &Instruction::decode_Vq_Mq, OP_MOVHPS },
	{ "movhps", &Instruction::decode_Mq_Vq, OP_MOVHPS },
	{ "group17", &Instruction::decode_group17, OP_GROUP17 },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "nop", &Instruction::decode_Ev, OP_NOP },
	
	/* 0x0f 0x20 - 0x0f 0x2f */
	{ "mov", &Instruction::decode_Rd_Cd, OP_MOV },
	{ "mov", &Instruction::decode_Rd_Dd, OP_MOV },
	{ "mov", &Instruction::decode_Cd_Rd, OP_MOV },
	{ "mov", &Instruction::decode_Dd_Rd, OP_MOV },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "movaps", &Instruction::decode_Vo_Wo, OP_MOVAPS },
	{ "movaps", &Instruction::decode_Wo_Vo, OP_MOVAPS },
	{ "cvtpi2ps", &Instruction::decode_Vo_Qq, OP_CVTPI2PS },
	{ "movntps",  &Instruction::decode_Mo_Vo, OP_MOVNTPS },	
	{ "cvttps2pi",  &Instruction::decode_Pq_Wo, OP_CVTTPS2PI },
	{ "cvtps2pi",  &Instruction::decode_Pq_Wo, OP_CVTPS2PI },
	{ "ucomiss",  &Instruction::decode_Vo_Wo, OP_UCOMISS },
	{ "comiss",  &Instruction::decode_Vo_Wo, OP_COMISS },
	
	/* 0x0f 0x30 - 0x0f 0x3f */
	{ "wrmsr", &Instruction::decode0, OP_WRMSR },
	{ "rdtsc", &Instruction::decode0, OP_RDTSC },
	{ "rdmsr", &Instruction::decode0, OP_RDMSR },
	{ "rdpmc", &Instruction::decode0, OP_RDPMC },
	{ "sysenter", &Instruction::decode0, OP_SYSENTER },
	{ "sysexit", &Instruction::decode0, OP_SYSEXIT },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "getsec", &Instruction::decode0, OP_GETSEC },
	{ "3byte", &Instruction::decode_3byte_38, OP_3BYTE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "3byte", &Instruction::decode_3byte_3A, OP_3BYTE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	
	/* 0x0f 0x40 - 0x0f 0x4f */
	{ "cmovo", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovno", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovb", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovnb", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovz", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovnz", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovb", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovnbe", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovs", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovns", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovp", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovnp", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovl", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovnl", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovle", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovnle", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	
	/* 0x0f 0x50 - 0x0f 0x5f */
	{ "movmskps", &Instruction::decode_Gq_Uo, OP_MOVMSKPS },	// x86: movmskps Gd, Uo
	{ "sqrtps", &Instruction::decode_Vo_Wo, OP_SQRTPS },
	{ "rsqrtps", &Instruction::decode_Vo_Wo, OP_RSQRTPS },
	{ "rcpps", &Instruction::decode_Vo_Wo, OP_RCPPS },
	{ "andps", &Instruction::decode_Vo_Wo, OP_ANDPS },
	{ "andnps", &Instruction::decode_Vo_Wo, OP_ANDNPS },
	{ "orps", &Instruction::decode_Vo_Wo, OP_ORPS },
	{ "xorps", &Instruction::decode_Vo_Wo, OP_XORPS },
	{ "addps", &Instruction::decode_Vo_Wo, OP_ADDPS },
	{ "mulps", &Instruction::decode_Vo_Wo, OP_MULPS },
	{ "cvtps2pd", &Instruction::decode_Vo_Wo, OP_CVTPS2PD },
	{ "cvtdq2ps", &Instruction::decode_Vo_Wo, OP_CVTDQ2PS },
	{ "subps", &Instruction::decode_Vo_Wo, OP_SUBPS },
	{ "minps", &Instruction::decode_Vo_Wo, OP_MINPS },
	{ "divps", &Instruction::decode_Vo_Wo, OP_DIVPS },
	{ "maxps", &Instruction::decode_Vo_Wo, OP_MAXPS },
	
	/* 0x0f 0x60 - 0x0f 0x6f */
	{ "punpcklbw", &Instruction::decode_Pq_Qd, OP_PUNPCKLBW },
	{ "punpcklwd", &Instruction::decode_Pq_Qd, OP_PUNPCKLWD },
	{ "punpckldq", &Instruction::decode_Pq_Qd, OP_PUNPCKLDQ },
	{ "packsswb", &Instruction::decode_Pq_Qq, OP_PACKSSWB },
	{ "pcmpgtb", &Instruction::decode_Pq_Qq, OP_PCMPGTB },
	{ "pcmpgtw", &Instruction::decode_Pq_Qq, OP_PCMPGTW },
	{ "pcmpgtd", &Instruction::decode_Pq_Qq, OP_PCMPGTD },
	{ "packuswb", &Instruction::decode_Pq_Qq, OP_PACKUSWB },
	{ "punpckhbw", &Instruction::decode_Pq_Qd, OP_PUNPCKHBW },
	{ "punpckhwd", &Instruction::decode_Pq_Qd, OP_PUNPCKHWD },
	{ "punpckhdq", &Instruction::decode_Pq_Qd, OP_PUNPCKHDQ },
	{ "packssdw", &Instruction::decode_Pq_Qq, OP_PACKSSDW },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "movq", &Instruction::decode_Pd_Eq, OP_MOVQ },		// x86: movd Pd, Ed
	{ "movq", &Instruction::decode_Pq_Qq, OP_MOVQ },
	
	/* 0x0f 0x70 - 0x0f 0x7f */
	{ "pshufw", &Instruction::decode_Pq_Qq_Ib, OP_PSHUFW },
	{ "group13", &Instruction::decode_group13, OP_GROUP13 },
	{ "group14", &Instruction::decode_group14, OP_GROUP14 },
	{ "group15", &Instruction::decode_group15, OP_GROUP15 },
	{ "pcmpeqb", &Instruction::decode_Pq_Qq, OP_PCMPEQB },
	{ "pcmpeqw", &Instruction::decode_Pq_Qq, OP_PCMPEQW },
	{ "pcmpeqd", &Instruction::decode_Pq_Qq, OP_PCMPEQD },
	{ "emms", &Instruction::decode0, OP_EMMS },
	{ "vmread", &Instruction::decode_Eq_Gq, OP_VMREAD },	// x86: vmread Ed, Gq
	{ "vmwrite", &Instruction::decode_Gq_Eq, OP_VMWRITE },	// x86: vmwrite Gd, Ed
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "movq", &Instruction::decode_Eq_Pd, OP_MOVQ },		// x86: movq Ed,Pd
	{ "movq", &Instruction::decode_Qq_Pq, OP_MOVQ },
	
	/* 0x0f 0x80 - 0x0f 0x8f */
	{ "jo", &Instruction::decode_Jz, OP_JCC },
	{ "jno", &Instruction::decode_Jz, OP_JCC },
	{ "jb", &Instruction::decode_Jz, OP_JCC },
	{ "jnb", &Instruction::decode_Jz, OP_JCC },
	{ "jz", &Instruction::decode_Jz, OP_JCC },
	{ "jnz", &Instruction::decode_Jz, OP_JCC },
	{ "jbe", &Instruction::decode_Jz, OP_JCC },
	{ "jnbe", &Instruction::decode_Jz, OP_JCC },
	{ "js", &Instruction::decode_Jz, OP_JCC },
	{ "jns", &Instruction::decode_Jz, OP_JCC },
	{ "jp", &Instruction::decode_Jz, OP_JCC },
	{ "jnp", &Instruction::decode_Jz, OP_JCC },
	{ "jl", &Instruction::decode_Jz, OP_JCC },
	{ "jnl", &Instruction::decode_Jz, OP_JCC },
	{ "jle", &Instruction::decode_Jz, OP_JCC },
	{ "jnle", &Instruction::decode_Jz, OP_JCC },
	
	/* 0x0f 0x90 - 0x0f 0x9f */
	{ "seto", &Instruction::decode_Eb, OP_SETCC },
	{ "setno", &Instruction::decode_Eb, OP_SETCC },
	{ "setb", &Instruction::decode_Eb, OP_SETCC },
	{ "setnb", &Instruction::decode_Eb, OP_SETCC },
	{ "setz", &Instruction::decode_Eb, OP_SETCC },
	{ "setnz", &Instruction::decode_Eb, OP_SETCC },
	{ "setbe", &Instruction::decode_Eb, OP_SETCC },
	{ "setnbe", &Instruction::decode_Eb, OP_SETCC },
	{ "sets", &Instruction::decode_Eb, OP_SETCC },
	{ "setns", &Instruction::decode_Eb, OP_SETCC },
	{ "setp", &Instruction::decode_Eb, OP_SETCC },
	{ "setnp", &Instruction::decode_Eb, OP_SETCC },
	{ "setl", &Instruction::decode_Eb, OP_SETCC },
	{ "setnl", &Instruction::decode_Eb, OP_SETCC },
	{ "setle", &Instruction::decode_Eb, OP_SETCC },
	{ "setnle", &Instruction::decode_Eb, OP_SETCC },
	
	/* 0x0f 0xa0 - 0x0f 0xaf */
	{ "push", &Instruction::decode_Reg<operand_t::REG_FS>, OP_PUSH },
	{ "pop", &Instruction::decode_Reg<operand_t::REG_FS>, OP_POP },
	{ "cpuid", &Instruction::decode0, OP_CPUID },
	{ "bt", &Instruction::decode_Ev_Gv, OP_BT },
	{ "shld", &Instruction::decode_Ev_Gv_Ib, OP_SHLD },
	{ "shld", &Instruction::decode_Ev_Gv_Reg<operand_t::REG_CL>, OP_SHLD },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "push", &Instruction::decode_Reg<operand_t::REG_GS>, OP_PUSH },
	{ "pop", &Instruction::decode_Reg<operand_t::REG_GS>, OP_POP },
	{ "rsm", &Instruction::decode0, OP_RSM },
	{ "bts", &Instruction::decode_Ev_Gv, OP_BTS },
	{ "shrd", &Instruction::decode_Ev_Gv_Ib, OP_SHRD },
	{ "shrd", &Instruction::decode_Ev_Gv_Reg<operand_t::REG_CL>, OP_SHRD },
	{ "group16", &Instruction::decode_group16, OP_GROUP16 },
	{ "imul",  &Instruction::decode_Gv_Ev, OP_IMUL },
	
	/* 0x0f 0xb0 - 0x0f 0xbf */
	{ "cmpxchg", &Instruction::decode_Eb_Gb, OP_CMPXCHG },
	{ "cmpxchg", &Instruction::decode_Ev_Gv, OP_CMPXCHG },
	{ "lss", &Instruction::decode_Gv_Mp, OP_LSS },
	{ "btr", &Instruction::decode_Ev_Gv, OP_BTR },
	{ "lfs", &Instruction::decode_Gv_Mp, OP_LFS },
	{ "lgs", &Instruction::decode_Gv_Mp, OP_LGS },
	{ "movzx", &Instruction::decode_Gv_Eb, OP_MOVZX },
	{ "movzx", &Instruction::decode_Gv_Ew, OP_MOVZX },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "group11", &Instruction::decode_group11, OP_GROUP11 },
	{ "group8", &Instruction::decode_group8, OP_GROUP8 },
	{ "btc", &Instruction::decode_Ev_Gv, OP_BTC },
	{ "bsf", &Instruction::decode_Gv_Ev, OP_BSF },
	{ "bsr", &Instruction::decode_Gv_Ev, OP_BSR },
	{ "movsx", &Instruction::decode_Gv_Eb, OP_MOVSX },
	{ "movsx", &Instruction::decode_Gv_Ew, OP_MOVSX },
	
	/* 0x0f 0xc0 - 0x0f 0xcf */
	{ "xadd", &Instruction::decode_Eb_Gb, OP_XADD },
	{ "xadd", &Instruction::decode_Ev_Gv, OP_XADD },
	{ "cmpps", &Instruction::decode_Vo_Wo_Ib, OP_CMPPS },
	{ "movnti", &Instruction::decode_Nq_Gq, OP_MOVNTI },	// x86: movnti Md, Gd
	{ "pinsrw", &Instruction::decode_Pq_Rq_Mw_Ib, OP_PINSRW },	// x86: pinsrw Pq, Rd/Mw,Ib
	{ "pextrw", &Instruction::decode_Gd_Nq_Ib, OP_PEXTRW },
	{ "shufps", &Instruction::decode_Vo_Wo_Ib, OP_SHUFPS },
	{ "group9", &Instruction::decode_group9, OP_GROUP9 },
	{ "bswap", &Instruction::decode_rAX, OP_BSWAP },
	{ "bswap", &Instruction::decode_rCX, OP_BSWAP },
	{ "bswap", &Instruction::decode_rDX, OP_BSWAP },
	{ "bswap", &Instruction::decode_rBX, OP_BSWAP },
	{ "bswap", &Instruction::decode_rSP, OP_BSWAP },
	{ "bswap", &Instruction::decode_rBP, OP_BSWAP },
	{ "bswap", &Instruction::decode_rSI, OP_BSWAP },
	{ "bswap", &Instruction::decode_rDI, OP_BSWAP },
	
	/* 0x0f 0xd0 - 0x0f 0xdf */
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "psrlw", &Instruction::decode_Pq_Qq, OP_PSRLW },
	{ "psrld", &Instruction::decode_Pq_Qq, OP_PSRLD },
	{ "psrlq", &Instruction::decode_Pq_Qq, OP_PSRLQ },
	{ "paddq", &Instruction::decode_Pq_Qq, OP_PADDQ },
	{ "pmullw", &Instruction::decode_Pq_Qq, OP_PMULLW },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "pmovmskb", &Instruction::decode_Gd_Nq, OP_PMOVMSKB },
    { "psubusb", &Instruction::decode_Pq_Qq, OP_PSUBUSB },
    { "psubusw", &Instruction::decode_Pq_Qq, OP_PSUBUSW },
    { "pminub", &Instruction::decode_Pq_Qq, OP_PMINUB },
    { "pand", &Instruction::decode_Pq_Qq, OP_PAND },
    { "paddusb", &Instruction::decode_Pq_Qq, OP_PADDUSB },
    { "paddusw", &Instruction::decode_Pq_Qq, OP_PADDUSW },
    { "pmaxub", &Instruction::decode_Pq_Qq, OP_PMAXUB },
    { "pandn", &Instruction::decode_Pq_Qq, OP_PANDN },
	
	/* 0x0f 0xe0 - 0x0f 0xef */
	{ "pavgb", &Instruction::decode_Pq_Qq, OP_PAVGB },
	{ "psraw", &Instruction::decode_Pq_Qq, OP_PSRAW },
	{ "psrad", &Instruction::decode_Pq_Qq, OP_PSRAD },
	{ "pavgw", &Instruction::decode_Pq_Qq, OP_PAVGW },
	{ "pmulhuw", &Instruction::decode_Pq_Qq, OP_PMULHUW },
	{ "pmulhw", &Instruction::decode_Pq_Qq, OP_PMULHW },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "movntq", &Instruction::decode_Mq_Pq, OP_MOVNTQ },
	{ "psubsb", &Instruction::decode_Pq_Qq, OP_PSUBSB },
	{ "psubsw", &Instruction::decode_Pq_Qq, OP_PSUBSW },
	{ "pminsw", &Instruction::decode_Pq_Qq, OP_PMINSW },
	{ "por", &Instruction::decode_Pq_Qq, OP_POR },  
	{ "paddsb", &Instruction::decode_Pq_Qq, OP_PADDSB },
	{ "paddsw", &Instruction::decode_Pq_Qq, OP_PADDSW },
	{ "pmaxsw", &Instruction::decode_Pq_Qq, OP_PMAXSW },
	{ "pxor", &Instruction::decode_Pq_Qq, OP_PXOR },
	
	/* 0x0f 0xf0 - 0x0f 0xff */
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "psllw", &Instruction::decode_Pq_Qq, OP_PSLLW },
	{ "pslld", &Instruction::decode_Pq_Qq, OP_PSLLD },
	{ "psllq", &Instruction::decode_Pq_Qq, OP_PSLLQ },
	{ "pmuludq", &Instruction::decode_Pq_Qq, OP_PMULUDQ },
	{ "pmaddwd", &Instruction::decode_Pq_Qq, OP_PMADDWD },
	{ "psadbw", &Instruction::decode_Pq_Qq, OP_PSADBW },
	{ "maskmovq", &Instruction::decode_Pq_Nq, OP_MASKMOVQ },
	{ "psubb", &Instruction::decode_Pq_Qq, OP_PSUBB },
	{ "psubw", &Instruction::decode_Pq_Qq, OP_PSUBW },
	{ "psubd", &Instruction::decode_Pq_Qq, OP_PSUBD },
	{ "psubq", &Instruction::decode_Pq_Qq, OP_PSUBQ },	
	{ "paddb", &Instruction::decode_Pq_Qq, OP_PADDB },
	{ "paddw", &Instruction::decode_Pq_Qq, OP_PADDW },
	{ "paddd", &Instruction::decode_Pq_Qq, OP_PADDD },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID }
};


// 2 byte opcodes with a 66 prefix
template <>
const Instruction<edisassm::x86_64>::OpcodeEntry Instruction<edisassm::x86_64>::Opcodes_2Byte_66[0x100] = {
	
	/* 0x0f 0x00 - 0x0f 0x0f */
	{ "group6", &Instruction::decode_group6, OP_GROUP6 },
	{ "group7", &Instruction::decode_group7, OP_GROUP7 },
	{ "lar", &Instruction::decode_Gv_Ew, OP_LAR },
	{ "lsl", &Instruction::decode_Gv_Ew, OP_LSL },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "syscall", &Instruction::decode0, OP_SYSCALL },
	{ "clts", &Instruction::decode0, OP_CLTS },
	{ "sysret", &Instruction::decode0, OP_SYSRET },
	{ "invd", &Instruction::decode0, OP_INVD },
	{ "wbinvd", &Instruction::decode0, OP_WBINVD },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "ud2", &Instruction::decode0, OP_UD2 },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "nop", &Instruction::decode_Ev, OP_NOP },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	
	/* 0x0f 0x10 - 0x0f 0x1f */
	{ "movupd", &Instruction::decode_Vo_Wo, OP_MOVUPD },
	{ "movupd", &Instruction::decode_Wo_Vo, OP_MOVUPD },
	{ "movlpd", &Instruction::decode_Vq_Mq, OP_MOVLPD },
	{ "movlpd", &Instruction::decode_Mq_Vq, OP_MOVLPD },
	{ "unpcklpd", &Instruction::decode_Vo_Wq, OP_UNPCKLPD },
	{ "unpckhpd", &Instruction::decode_Vo_Wq, OP_UNPCKHPD },
	{ "movhpd", &Instruction::decode_Vq_Mq, OP_MOVHPD },
	{ "movhpd", &Instruction::decode_Mq_Vq, OP_MOVHPD },
	{ "group17", &Instruction::decode_group17, OP_GROUP17 },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "nop", &Instruction::decode_Ev, OP_NOP },
	
	/* 0x0f 0x20 - 0x0f 0x2f */
	{ "mov", &Instruction::decode_Rd_Cd, OP_MOV },
	{ "mov", &Instruction::decode_Rd_Dd, OP_MOV },
	{ "mov", &Instruction::decode_Cd_Rd, OP_MOV },
	{ "mov", &Instruction::decode_Dd_Rd, OP_MOV },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "movapd", &Instruction::decode_Vo_Wo, OP_MOVAPD },
	{ "movapd", &Instruction::decode_Wo_Vo, OP_MOVAPD },
	{ "cvtpi2pd", &Instruction::decode_Vo_Qq, OP_CVTPI2PD },
	{ "movntpd",  &Instruction::decode_Mo_Vo, OP_MOVNTPD },	
	{ "cvttpd2pi",  &Instruction::decode_Pq_Wo, OP_CVTTPD2PI },
	{ "cvtpd2pi",  &Instruction::decode_Qq_Wo, OP_CVTPD2PI },
	{ "ucomisd",  &Instruction::decode_Vo_Wo, OP_UCOMISD },
	{ "comisd",  &Instruction::decode_Vo_Wo, OP_COMISD },
	
	/* 0x0f 0x30 - 0x0f 0x3f */
	{ "wrmsr", &Instruction::decode0, OP_WRMSR },
	{ "rdtsc", &Instruction::decode0, OP_RDTSC },
	{ "rdmsr", &Instruction::decode0, OP_RDMSR },
	{ "rdpmc", &Instruction::decode0, OP_RDPMC },
	{ "sysenter", &Instruction::decode0, OP_SYSENTER },
	{ "sysexit", &Instruction::decode0, OP_SYSEXIT },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "getsec", &Instruction::decode0, OP_GETSEC },
	{ "3byte", &Instruction::decode_3byte_38, OP_3BYTE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "3byte", &Instruction::decode_3byte_3A, OP_3BYTE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	
	/* 0x0f 0x40 - 0x0f 0x4f */
	{ "cmovo", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovno", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovb", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovnb", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovz", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovnz", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovb", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovnbe", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovs", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovns", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovp", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovnp", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovl", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovnl", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovle", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovnle", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	
	/* 0x0f 0x50 - 0x0f 0x5f */
	{ "movmskpd", &Instruction::decode_Gq_Uo, OP_MOVMSKPD },	// x86: movmskpd Gd, Uo
	{ "sqrtpd", &Instruction::decode_Vo_Wo, OP_SQRTPD },
	{ "rsqrtps", &Instruction::decode_Vo_Wo, OP_RSQRTPS },
	{ "rcpps", &Instruction::decode_Vo_Wo, OP_RCPPS },
	{ "andpd", &Instruction::decode_Vo_Wo, OP_ANDPD },
	{ "andnpd", &Instruction::decode_Vo_Wo, OP_ANDNPD },
	{ "orpd", &Instruction::decode_Vo_Wo, OP_ORPD },
	{ "xorpd", &Instruction::decode_Vo_Wo, OP_XORPD },
	{ "addpd", &Instruction::decode_Vo_Wo, OP_ADDPD },
	{ "mulpd", &Instruction::decode_Vo_Wo, OP_MULPD },
	{ "cvtpd2ps", &Instruction::decode_Vo_Wo, OP_CVTPD2PS },
	{ "cvtps2dq", &Instruction::decode_Vo_Wo, OP_CVTPS2DQ },
	{ "subpd", &Instruction::decode_Vo_Wo, OP_SUBPD },
	{ "minpd", &Instruction::decode_Vo_Wo, OP_MINPD },
	{ "divpd", &Instruction::decode_Vo_Wo, OP_DIVPD },
	{ "maxpd", &Instruction::decode_Vo_Wo, OP_MAXPD },
	
	/* 0x0f 0x60 - 0x0f 0x6f */
	{ "punpcklbw", &Instruction::decode_Vo_Wo, OP_PUNPCKLBW },
	{ "punpcklwd", &Instruction::decode_Vo_Wo, OP_PUNPCKLWD },
	{ "punpckldq", &Instruction::decode_Vo_Wo, OP_PUNPCKLDQ },
	{ "packsswb", &Instruction::decode_Vo_Wo, OP_PACKSSWB },
	{ "pcmpgtb", &Instruction::decode_Vo_Wo, OP_PCMPGTB },
	{ "pcmpgtw", &Instruction::decode_Vo_Wo, OP_PCMPGTW },
	{ "pcmpgtd", &Instruction::decode_Vo_Wo, OP_PCMPGTD },
	{ "packuswb", &Instruction::decode_Vo_Wo, OP_PACKUSWB },
	{ "punpckhbw", &Instruction::decode_Vo_Wo, OP_PUNPCKHBW },
	{ "punpckhwd", &Instruction::decode_Vo_Wo, OP_PUNPCKHWD },
	{ "punpckhdq", &Instruction::decode_Vo_Wo, OP_PUNPCKHDQ },
	{ "packssdw", &Instruction::decode_Vo_Wo, OP_PACKSSDW },
	{ "punpcklqdq", &Instruction::decode_Vo_Wo, OP_PUNPCKLQDQ },
	{ "punpckhqdq", &Instruction::decode_Vo_Wo, OP_PUNPCKHQDQ },
	{ "movq", &Instruction::decode_Vo_Eq, OP_MOVQ },		// x86: movd Vo, Ed
	{ "movq", &Instruction::decode_Vo_Qq, OP_MOVQ },
	
	/* 0x0f 0x70 - 0x0f 0x7f */
	{ "pshufd", &Instruction::decode_Vo_Wo_Ib, OP_PSHUFD },
	{ "group13", &Instruction::decode_group13, OP_GROUP13 },
	{ "group14", &Instruction::decode_group14, OP_GROUP14 },
	{ "group15", &Instruction::decode_group15, OP_GROUP15 },
	{ "pcmpeqb", &Instruction::decode_Vo_Wo, OP_PCMPEQB },
	{ "pcmpeqw", &Instruction::decode_Vo_Wo, OP_PCMPEQW },
	{ "pcmpeqd", &Instruction::decode_Vo_Wo, OP_PCMPEQD },
	{ "emms", &Instruction::decode0, OP_EMMS },
	{ "vmread", &Instruction::decode_Eq_Gq, OP_VMREAD },	// x86: vmread Ed, Gd
	{ "vmwrite", &Instruction::decode_Gq_Eq, OP_VMWRITE },	// x86: vmwrite Gd, Ed
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "haddpd", &Instruction::decode_Vo_Wo, OP_HADDPD },
	{ "hsubpd", &Instruction::decode_Vo_Wo, OP_HSUBPD },
	{ "movq", &Instruction::decode_Eq_Vo, OP_MOVD },		// x86: movd Ed, Vo
	{ "movdqa", &Instruction::decode_Wo_Vo, OP_MOVDQA },
	
	/* 0x0f 0x80 - 0x0f 0x8f */
	{ "jo", &Instruction::decode_Jz, OP_JCC },
	{ "jno", &Instruction::decode_Jz, OP_JCC },
	{ "jb", &Instruction::decode_Jz, OP_JCC },
	{ "jnb", &Instruction::decode_Jz, OP_JCC },
	{ "jz", &Instruction::decode_Jz, OP_JCC },
	{ "jnz", &Instruction::decode_Jz, OP_JCC },
	{ "jbe", &Instruction::decode_Jz, OP_JCC },
	{ "jnbe", &Instruction::decode_Jz, OP_JCC },
	{ "js", &Instruction::decode_Jz, OP_JCC },
	{ "jns", &Instruction::decode_Jz, OP_JCC },
	{ "jp", &Instruction::decode_Jz, OP_JCC },
	{ "jnp", &Instruction::decode_Jz, OP_JCC },
	{ "jl", &Instruction::decode_Jz, OP_JCC },
	{ "jnl", &Instruction::decode_Jz, OP_JCC },
	{ "jle", &Instruction::decode_Jz, OP_JCC },
	{ "jnle", &Instruction::decode_Jz, OP_JCC },
	
	/* 0x0f 0x90 - 0x0f 0x9f */
	{ "seto", &Instruction::decode_Eb, OP_SETCC },
	{ "setno", &Instruction::decode_Eb, OP_SETCC },
	{ "setb", &Instruction::decode_Eb, OP_SETCC },
	{ "setnb", &Instruction::decode_Eb, OP_SETCC },
	{ "setz", &Instruction::decode_Eb, OP_SETCC },
	{ "setnz", &Instruction::decode_Eb, OP_SETCC },
	{ "setbe", &Instruction::decode_Eb, OP_SETCC },
	{ "setnbe", &Instruction::decode_Eb, OP_SETCC },
	{ "sets", &Instruction::decode_Eb, OP_SETCC },
	{ "setns", &Instruction::decode_Eb, OP_SETCC },
	{ "setp", &Instruction::decode_Eb, OP_SETCC },
	{ "setnp", &Instruction::decode_Eb, OP_SETCC },
	{ "setl", &Instruction::decode_Eb, OP_SETCC },
	{ "setnl", &Instruction::decode_Eb, OP_SETCC },
	{ "setle", &Instruction::decode_Eb, OP_SETCC },
	{ "setnle", &Instruction::decode_Eb, OP_SETCC },
	
	/* 0x0f 0xa0 - 0x0f 0xaf */
	{ "push", &Instruction::decode_Reg<operand_t::REG_FS>, OP_PUSH },
	{ "pop", &Instruction::decode_Reg<operand_t::REG_FS>, OP_POP },
	{ "cpuid", &Instruction::decode0, OP_CPUID },
	{ "bt", &Instruction::decode_Ev_Gv, OP_BT },
	{ "shld", &Instruction::decode_Ev_Gv_Ib, OP_SHLD },
	{ "shld", &Instruction::decode_Ev_Gv_Reg<operand_t::REG_CL>, OP_SHLD },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "push", &Instruction::decode_Reg<operand_t::REG_GS>, OP_PUSH },
	{ "pop", &Instruction::decode_Reg<operand_t::REG_GS>, OP_POP },
	{ "rsm", &Instruction::decode0, OP_RSM },
	{ "bts", &Instruction::decode_Ev_Gv, OP_BTS },
	{ "shrd", &Instruction::decode_Ev_Gv_Ib, OP_SHRD },
	{ "shrd", &Instruction::decode_Ev_Gv_Reg<operand_t::REG_CL>, OP_SHRD },
	{ "group16", &Instruction::decode_group16, OP_GROUP16 },
	{ "imul",  &Instruction::decode_Gv_Ev, OP_IMUL },
	
	/* 0x0f 0xb0 - 0x0f 0xbf */
	{ "cmpxchg", &Instruction::decode_Eb_Gb, OP_CMPXCHG },
	{ "cmpxchg", &Instruction::decode_Ev_Gv, OP_CMPXCHG },
	{ "lss", &Instruction::decode_Gv_Mp, OP_LSS },
	{ "btr", &Instruction::decode_Ev_Gv, OP_BTR },
	{ "lfs", &Instruction::decode_Gv_Mp, OP_LFS },
	{ "lgs", &Instruction::decode_Gv_Mp, OP_LGS },
	{ "movzx", &Instruction::decode_Gv_Eb, OP_MOVZX },
	{ "movzx", &Instruction::decode_Gv_Ew, OP_MOVZX },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "group11", &Instruction::decode_group11, OP_GROUP11 },
	{ "group8", &Instruction::decode_group8, OP_GROUP8 },
	{ "btc", &Instruction::decode_Ev_Gv, OP_BTC },
	{ "bsf", &Instruction::decode_Gv_Ev, OP_BSF },
	{ "bsr", &Instruction::decode_Gv_Ev, OP_BSR },
	{ "movsx", &Instruction::decode_Gv_Eb, OP_MOVSX },
	{ "movsx", &Instruction::decode_Gv_Ew, OP_MOVSX },
	
	/* 0x0f 0xc0 - 0x0f 0xcf */
	{ "xadd", &Instruction::decode_Eb_Gb, OP_XADD },
	{ "xadd", &Instruction::decode_Ev_Gv, OP_XADD },
	{ "cmppd", &Instruction::decode_Vo_Wo_Ib, OP_CMPPD },
	{ "movnti", &Instruction::decode_Nq_Gq, OP_MOVNTI },		// x86: movnti Md, Gd
	{ "pinsrw", &Instruction::decode_Vo_Rq_Mw_Ib, OP_PINSRW },	// x86: pinsrw Vo, Rd/Mw,Ib
	{ "pextrw", &Instruction::decode_Gd_Uo_Ib, OP_PEXTRW },
	{ "shufpd", &Instruction::decode_Vo_Wo_Ib, OP_SHUFPD },
	{ "group9", &Instruction::decode_group9, OP_GROUP9 },
	{ "bswap", &Instruction::decode_rAX, OP_BSWAP },
	{ "bswap", &Instruction::decode_rCX, OP_BSWAP },
	{ "bswap", &Instruction::decode_rDX, OP_BSWAP },
	{ "bswap", &Instruction::decode_rBX, OP_BSWAP },
	{ "bswap", &Instruction::decode_rSP, OP_BSWAP },
	{ "bswap", &Instruction::decode_rBP, OP_BSWAP },
	{ "bswap", &Instruction::decode_rSI, OP_BSWAP },
	{ "bswap", &Instruction::decode_rDI, OP_BSWAP },
	
	/* 0x0f 0xd0 - 0x0f 0xdf */
	{ "addsubpd", &Instruction::decode_Vo_Wo, OP_ADDSUBPD },
	{ "psrlw", &Instruction::decode_Vo_Wo, OP_PSRLW },
	{ "psrld", &Instruction::decode_Vo_Wo, OP_PSRLD },
	{ "psrlq", &Instruction::decode_Vo_Wo, OP_PSRLQ },
	{ "paddq", &Instruction::decode_Vo_Wo, OP_PADDQ },
	{ "pmullw", &Instruction::decode_Vo_Wo, OP_PMULLW },
	{ "movq", &Instruction::decode_Vo_Wo, OP_MOVQ },
	{ "pmovmskb", &Instruction::decode_Gd_Uo, OP_PMOVMSKB },
    { "psubusb", &Instruction::decode_Vo_Wo, OP_PSUBUSB },
    { "psubusw", &Instruction::decode_Vo_Wo, OP_PSUBUSW },
    { "pminub", &Instruction::decode_Vo_Wo, OP_PMINUB },
    { "pand", &Instruction::decode_Vo_Wo, OP_PAND },
    { "paddusb", &Instruction::decode_Vo_Wo, OP_PADDUSB },
    { "paddusw", &Instruction::decode_Vo_Wo, OP_PADDUSW },
    { "pmaxub", &Instruction::decode_Vo_Wo, OP_PMAXUB },
    { "pandn", &Instruction::decode_Vo_Wo, OP_PANDN },
	
	/* 0x0f 0xe0 - 0x0f 0xef */
	{ "pavgb", &Instruction::decode_Vo_Wo, OP_PAVGB },
	{ "psraw", &Instruction::decode_Vo_Wo, OP_PSRAW },
	{ "psrad", &Instruction::decode_Vo_Wo, OP_PSRAD },
	{ "pavgw", &Instruction::decode_Vo_Wo, OP_PAVGW },
	{ "pmulhuw", &Instruction::decode_Vo_Wo, OP_PMULHUW },
	{ "pmulhw", &Instruction::decode_Vo_Wo, OP_PMULHW },
	{ "cvttpd2dq", &Instruction::decode_Vo_Wo, OP_CVTTPD2DQ },
	{ "movntdq", &Instruction::decode_Mo_Vo, OP_MOVNTDQ },
	{ "psubsb", &Instruction::decode_Vo_Wo, OP_PSUBSB },
	{ "psubsw", &Instruction::decode_Vo_Wo, OP_PSUBSW },
	{ "pminsw", &Instruction::decode_Vo_Wo, OP_PMINSW },
	{ "por", &Instruction::decode_Vo_Wo, OP_POR },  
	{ "paddsb", &Instruction::decode_Vo_Wo, OP_PADDSB },
	{ "paddsw", &Instruction::decode_Vo_Wo, OP_PADDSW },
	{ "pmaxsw", &Instruction::decode_Vo_Wo, OP_PMAXSW },
	{ "pxor", &Instruction::decode_Vo_Wo, OP_PXOR },
	
	/* 0x0f 0xf0 - 0x0f 0xff */
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "psllw", &Instruction::decode_Vo_Wo, OP_PSLLW },
	{ "pslld", &Instruction::decode_Vo_Wo, OP_PSLLD },
	{ "psllq", &Instruction::decode_Vo_Wo, OP_PSLLQ },
	{ "pmuludq", &Instruction::decode_Vo_Wo, OP_PMULUDQ },
	{ "pmaddwd", &Instruction::decode_Vo_Wo, OP_PMADDWD },
	{ "psadbw", &Instruction::decode_Vo_Wo, OP_PSADBW },
	{ "maskmovdqu", &Instruction::decode_Vo_Uo, OP_MASKMOVDQU },
	{ "psubb", &Instruction::decode_Vo_Wo, OP_PSUBB },
	{ "psubw", &Instruction::decode_Vo_Wo, OP_PSUBW },
	{ "psubd", &Instruction::decode_Vo_Wo, OP_PSUBD },
	{ "psubq", &Instruction::decode_Vo_Wo, OP_PSUBQ },	
	{ "paddb", &Instruction::decode_Vo_Wo, OP_PADDB },
	{ "paddw", &Instruction::decode_Vo_Wo, OP_PADDW },
	{ "paddd", &Instruction::decode_Vo_Wo, OP_PADDD },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID }
};

// 2 byte opcodes with a f2 prefix
template <>
const Instruction<edisassm::x86_64>::OpcodeEntry Instruction<edisassm::x86_64>::Opcodes_2Byte_F2[0x100] = {

	/* 0x0f 0x00 - 0x0f 0x0f */
	{ "group6", &Instruction::decode_group6, OP_GROUP6 },
	{ "group7", &Instruction::decode_group7, OP_GROUP7 },
	{ "lar", &Instruction::decode_Gv_Ew, OP_LAR },
	{ "lsl", &Instruction::decode_Gv_Ew, OP_LSL },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "syscall", &Instruction::decode0, OP_SYSCALL },
	{ "clts", &Instruction::decode0, OP_CLTS },
	{ "sysret", &Instruction::decode0, OP_SYSRET },
	{ "invd", &Instruction::decode0, OP_INVD },
	{ "wbinvd", &Instruction::decode0, OP_WBINVD },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "ud2", &Instruction::decode0, OP_UD2 },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "nop", &Instruction::decode_Ev, OP_NOP },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	
	/* 0x0f 0x10 - 0x0f 0x1f */
	{ "movsd", &Instruction::decode_Vo_Wo, OP_MOVSD },
	{ "movsd", &Instruction::decode_Wo_Vo, OP_MOVSD },
	{ "movddup", &Instruction::decode_Vq_Mq, OP_MOVDDUP },
	{ "movlps", &Instruction::decode_Mq_Vq, OP_MOVLPS },
	{ "unpcklps", &Instruction::decode_Vo_Wq, OP_UNPCKLPS },
	{ "unpckhps", &Instruction::decode_Vo_Wq, OP_UNPCKHPS },
	{ "movhps", &Instruction::decode_Vq_Mq, OP_MOVHPS },
	{ "movhps", &Instruction::decode_Mq_Vq, OP_MOVHPS },
	{ "group17", &Instruction::decode_group17, OP_GROUP17 },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "nop", &Instruction::decode_Ev, OP_NOP },
	
	/* 0x0f 0x20 - 0x0f 0x2f */
	{ "mov", &Instruction::decode_Rd_Cd, OP_MOV },
	{ "mov", &Instruction::decode_Rd_Dd, OP_MOV },
	{ "mov", &Instruction::decode_Cd_Rd, OP_MOV },
	{ "mov", &Instruction::decode_Dd_Rd, OP_MOV },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "movaps", &Instruction::decode_Vo_Wo, OP_MOVAPS },
	{ "movaps", &Instruction::decode_Wo_Vo, OP_MOVAPS },
	{ "cvtsi2sd", &Instruction::decode_Vo_Eq, OP_CVTSI2SD },	// x86: cvtsi2sd Vo, Ed
	{ "movntps",  &Instruction::decode_Mo_Vo, OP_MOVNTPS },	
	{ "cvttsd2si",  &Instruction::decode_Gq_Wo, OP_CVTTSD2SI },	// x86: cvttsd2si Gd, Wo
	{ "cvtsd2si",  &Instruction::decode_Gq_Wo, OP_CVTSD2SI },	// x86: cvtsd2si Gd, Wo
	{ "ucomiss",  &Instruction::decode_Vo_Wo, OP_UCOMISS },
	{ "comiss",  &Instruction::decode_Vo_Wo, OP_COMISS },
	
	/* 0x0f 0x30 - 0x0f 0x3f */
	{ "wrmsr", &Instruction::decode0, OP_WRMSR },
	{ "rdtsc", &Instruction::decode0, OP_RDTSC },
	{ "rdmsr", &Instruction::decode0, OP_RDMSR },
	{ "rdpmc", &Instruction::decode0, OP_RDPMC },
	{ "sysenter", &Instruction::decode0, OP_SYSENTER },
	{ "sysexit", &Instruction::decode0, OP_SYSEXIT },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "getsec", &Instruction::decode0, OP_GETSEC },
	{ "3byte", &Instruction::decode_3byte_38, OP_3BYTE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "3byte", &Instruction::decode_3byte_3A, OP_3BYTE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	
	/* 0x0f 0x40 - 0x0f 0x4f */
	{ "cmovo", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovno", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovb", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovnb", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovz", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovnz", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovb", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovnbe", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovs", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovns", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovp", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovnp", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovl", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovnl", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovle", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovnle", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	
	/* 0x0f 0x50 - 0x0f 0x5f */
	{ "movmskps", &Instruction::decode_Gq_Uo, OP_MOVMSKPS },	// x86: movmskps Gd, Uo
	{ "sqrtsd", &Instruction::decode_Vo_Wo, OP_SQRTSD },
	{ "rsqrtps", &Instruction::decode_Vo_Wo, OP_RSQRTPS },
	{ "rcpps", &Instruction::decode_Vo_Wo, OP_RCPPS },
	{ "andps", &Instruction::decode_Vo_Wo, OP_ANDPS },
	{ "andnps", &Instruction::decode_Vo_Wo, OP_ANDNPS },
	{ "orps", &Instruction::decode_Vo_Wo, OP_ORPS },
	{ "xorps", &Instruction::decode_Vo_Wo, OP_XORPS },
	{ "addsd", &Instruction::decode_Vo_Wo, OP_ADDSD },
	{ "mulsd", &Instruction::decode_Vo_Wo, OP_MULSD },
	{ "cvtsd2ss", &Instruction::decode_Vo_Wo, OP_CVTSD2SS },
	{ "cvtdq2ps", &Instruction::decode_Vo_Wo, OP_CVTDQ2PS },
	{ "subsd", &Instruction::decode_Vo_Wo, OP_SUBSD },
	{ "minsd", &Instruction::decode_Vo_Wo, OP_MINSD },
	{ "divsd", &Instruction::decode_Vo_Wo, OP_DIVSD },
	{ "maxsd", &Instruction::decode_Vo_Wo, OP_MAXSD },
	
	/* 0x0f 0x60 - 0x0f 0x6f */
	{ "punpcklbw", &Instruction::decode_Pq_Qd, OP_PUNPCKLBW },
	{ "punpcklwd", &Instruction::decode_Pq_Qd, OP_PUNPCKLWD },
	{ "punpckldq", &Instruction::decode_Pq_Qd, OP_PUNPCKLDQ },
	{ "packsswb", &Instruction::decode_Pq_Qq, OP_PACKSSWB },
	{ "pcmpgtb", &Instruction::decode_Pq_Qq, OP_PCMPGTB },
	{ "pcmpgtw", &Instruction::decode_Pq_Qq, OP_PCMPGTW },
	{ "pcmpgtd", &Instruction::decode_Pq_Qq, OP_PCMPGTD },
	{ "packuswb", &Instruction::decode_Pq_Qq, OP_PACKUSWB },
	{ "punpckhbw", &Instruction::decode_Pq_Qd, OP_PUNPCKHBW },
	{ "punpckhwd", &Instruction::decode_Pq_Qd, OP_PUNPCKHWD },
	{ "punpckhdq", &Instruction::decode_Pq_Qd, OP_PUNPCKHDQ },
	{ "packssdw", &Instruction::decode_Pq_Qq, OP_PACKSSDW },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "movq", &Instruction::decode_Pd_Eq, OP_MOVQ },		// x86: movq Pd, Ed
	{ "movq", &Instruction::decode_Pq_Qq, OP_MOVQ },
	
	/* 0x0f 0x70 - 0x0f 0x7f */
	{ "pshuflw", &Instruction::decode_Vo_Wo_Ib, OP_PSHUFLW },
	{ "group13", &Instruction::decode_group13, OP_GROUP13 },
	{ "group14", &Instruction::decode_group14, OP_GROUP14 },
	{ "group15", &Instruction::decode_group15, OP_GROUP15 },
	{ "pcmpeqb", &Instruction::decode_Pq_Qq, OP_PCMPEQB },
	{ "pcmpeqw", &Instruction::decode_Pq_Qq, OP_PCMPEQW },
	{ "pcmpeqd", &Instruction::decode_Pq_Qq, OP_PCMPEQD },
	{ "emms", &Instruction::decode0, OP_EMMS },
	{ "vmread", &Instruction::decode_Eq_Gq, OP_VMREAD },	// x86: vmread Ed, Gd
	{ "vmwrite", &Instruction::decode_Gq_Eq, OP_VMWRITE },	// x86: vmwrite Gd, Ed
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "haddps", &Instruction::decode_Vo_Wo, OP_HADDPS },
	{ "hsubps", &Instruction::decode_Vo_Wo, OP_HSUBPS },
	{ "movq", &Instruction::decode_Eq_Pd, OP_MOVD },		// x86: movq Ed, Pd
	{ "movq", &Instruction::decode_Qq_Pq, OP_MOVQ },
	
	/* 0x0f 0x80 - 0x0f 0x8f */
	{ "jo", &Instruction::decode_Jz, OP_JCC },
	{ "jno", &Instruction::decode_Jz, OP_JCC },
	{ "jb", &Instruction::decode_Jz, OP_JCC },
	{ "jnb", &Instruction::decode_Jz, OP_JCC },
	{ "jz", &Instruction::decode_Jz, OP_JCC },
	{ "jnz", &Instruction::decode_Jz, OP_JCC },
	{ "jbe", &Instruction::decode_Jz, OP_JCC },
	{ "jnbe", &Instruction::decode_Jz, OP_JCC },
	{ "js", &Instruction::decode_Jz, OP_JCC },
	{ "jns", &Instruction::decode_Jz, OP_JCC },
	{ "jp", &Instruction::decode_Jz, OP_JCC },
	{ "jnp", &Instruction::decode_Jz, OP_JCC },
	{ "jl", &Instruction::decode_Jz, OP_JCC },
	{ "jnl", &Instruction::decode_Jz, OP_JCC },
	{ "jle", &Instruction::decode_Jz, OP_JCC },
	{ "jnle", &Instruction::decode_Jz, OP_JCC },
	
	/* 0x0f 0x90 - 0x0f 0x9f */
	{ "seto", &Instruction::decode_Eb, OP_SETCC },
	{ "setno", &Instruction::decode_Eb, OP_SETCC },
	{ "setb", &Instruction::decode_Eb, OP_SETCC },
	{ "setnb", &Instruction::decode_Eb, OP_SETCC },
	{ "setz", &Instruction::decode_Eb, OP_SETCC },
	{ "setnz", &Instruction::decode_Eb, OP_SETCC },
	{ "setbe", &Instruction::decode_Eb, OP_SETCC },
	{ "setnbe", &Instruction::decode_Eb, OP_SETCC },
	{ "sets", &Instruction::decode_Eb, OP_SETCC },
	{ "setns", &Instruction::decode_Eb, OP_SETCC },
	{ "setp", &Instruction::decode_Eb, OP_SETCC },
	{ "setnp", &Instruction::decode_Eb, OP_SETCC },
	{ "setl", &Instruction::decode_Eb, OP_SETCC },
	{ "setnl", &Instruction::decode_Eb, OP_SETCC },
	{ "setle", &Instruction::decode_Eb, OP_SETCC },
	{ "setnle", &Instruction::decode_Eb, OP_SETCC },
	
	/* 0x0f 0xa0 - 0x0f 0xaf */
	{ "push", &Instruction::decode_Reg<operand_t::REG_FS>, OP_PUSH },
	{ "pop", &Instruction::decode_Reg<operand_t::REG_FS>, OP_POP },
	{ "cpuid", &Instruction::decode0, OP_CPUID },
	{ "bt", &Instruction::decode_Ev_Gv, OP_BT },
	{ "shld", &Instruction::decode_Ev_Gv_Ib, OP_SHLD },
	{ "shld", &Instruction::decode_Ev_Gv_Reg<operand_t::REG_CL>, OP_SHLD },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "push", &Instruction::decode_Reg<operand_t::REG_GS>, OP_PUSH },
	{ "pop", &Instruction::decode_Reg<operand_t::REG_GS>, OP_POP },
	{ "rsm", &Instruction::decode0, OP_RSM },
	{ "bts", &Instruction::decode_Ev_Gv, OP_BTS },
	{ "shrd", &Instruction::decode_Ev_Gv_Ib, OP_SHRD },
	{ "shrd", &Instruction::decode_Ev_Gv_Reg<operand_t::REG_CL>, OP_SHRD },
	{ "group16", &Instruction::decode_group16, OP_GROUP16 },
	{ "imul",  &Instruction::decode_Gv_Ev, OP_IMUL },
	
	/* 0x0f 0xb0 - 0x0f 0xbf */
	{ "cmpxchg", &Instruction::decode_Eb_Gb, OP_CMPXCHG },
	{ "cmpxchg", &Instruction::decode_Ev_Gv, OP_CMPXCHG },
	{ "lss", &Instruction::decode_Gv_Mp, OP_LSS },
	{ "btr", &Instruction::decode_Ev_Gv, OP_BTR },
	{ "lfs", &Instruction::decode_Gv_Mp, OP_LFS },
	{ "lgs", &Instruction::decode_Gv_Mp, OP_LGS },
	{ "movzx", &Instruction::decode_Gv_Eb, OP_MOVZX },
	{ "movzx", &Instruction::decode_Gv_Ew, OP_MOVZX },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "group11", &Instruction::decode_group11, OP_GROUP11 },
	{ "group8", &Instruction::decode_group8, OP_GROUP8 },
	{ "btc", &Instruction::decode_Ev_Gv, OP_BTC },
	{ "bsf", &Instruction::decode_Gv_Ev, OP_BSF },
	{ "bsr", &Instruction::decode_Gv_Ev, OP_BSR },
	{ "movsx", &Instruction::decode_Gv_Eb, OP_MOVSX },
	{ "movsx", &Instruction::decode_Gv_Ew, OP_MOVSX },
	
	/* 0x0f 0xc0 - 0x0f 0xcf */
	{ "xadd", &Instruction::decode_Eb_Gb, OP_XADD },
	{ "xadd", &Instruction::decode_Ev_Gv, OP_XADD },
	{ "cmpsd", &Instruction::decode_Vo_Wo_Ib, OP_CMPSD },
	{ "movnti", &Instruction::decode_Nq_Gq, OP_MOVNTI },	// x86: movnti Md, Gd
	{ "pinsrw", &Instruction::decode_Pq_Rq_Mw_Ib, OP_PINSRW },	// x86: pinsrw Pq, Rd/Mw,Ib
	{ "pextrw", &Instruction::decode_Gd_Nq_Ib, OP_PEXTRW },
	{ "shufps", &Instruction::decode_Vo_Wo_Ib, OP_SHUFPS },
	{ "group9", &Instruction::decode_group9, OP_GROUP9 },
	{ "bswap", &Instruction::decode_rAX, OP_BSWAP },
	{ "bswap", &Instruction::decode_rCX, OP_BSWAP },
	{ "bswap", &Instruction::decode_rDX, OP_BSWAP },
	{ "bswap", &Instruction::decode_rBX, OP_BSWAP },
	{ "bswap", &Instruction::decode_rSP, OP_BSWAP },
	{ "bswap", &Instruction::decode_rBP, OP_BSWAP },
	{ "bswap", &Instruction::decode_rSI, OP_BSWAP },
	{ "bswap", &Instruction::decode_rDI, OP_BSWAP },
	
	/* 0x0f 0xd0 - 0x0f 0xdf */
	{ "addsubps", &Instruction::decode_Vo_Wo, OP_ADDSUBPS },
	{ "psrlw", &Instruction::decode_Pq_Qq, OP_PSRLW },
	{ "psrld", &Instruction::decode_Pq_Qq, OP_PSRLD },
	{ "psrlq", &Instruction::decode_Pq_Qq, OP_PSRLQ },
	{ "paddq", &Instruction::decode_Pq_Qq, OP_PADDQ },
	{ "pmullw", &Instruction::decode_Pq_Qq, OP_PMULLW },
	{ "movdq2q", &Instruction::decode_Pq_Qq, OP_MOVDQ2Q },
	{ "pmovmskb", &Instruction::decode_Gd_Nq, OP_PMOVMSKB },
    { "psubusb", &Instruction::decode_Pq_Qq, OP_PSUBUSB },
    { "psubusw", &Instruction::decode_Pq_Qq, OP_PSUBUSW },
    { "pminub", &Instruction::decode_Pq_Qq, OP_PMINUB },
    { "pand", &Instruction::decode_Pq_Qq, OP_PAND },
    { "paddusb", &Instruction::decode_Pq_Qq, OP_PADDUSB },
    { "paddusw", &Instruction::decode_Pq_Qq, OP_PADDUSW },
    { "pmaxub", &Instruction::decode_Pq_Qq, OP_PMAXUB },
    { "pandn", &Instruction::decode_Pq_Qq, OP_PANDN },
	
	/* 0x0f 0xe0 - 0x0f 0xef */
	{ "pavgb", &Instruction::decode_Pq_Qq, OP_PAVGB },
	{ "psraw", &Instruction::decode_Pq_Qq, OP_PSRAW },
	{ "psrad", &Instruction::decode_Pq_Qq, OP_PSRAD },
	{ "pavgw", &Instruction::decode_Pq_Qq, OP_PAVGW },
	{ "pmulhuw", &Instruction::decode_Pq_Qq, OP_PMULHUW },
	{ "pmulhw", &Instruction::decode_Pq_Qq, OP_PMULHW },
	{ "cvtpd2dq", &Instruction::decode_Vo_Wo, OP_CVTPD2DQ },
	{ "movntq", &Instruction::decode_Mq_Pq, OP_MOVNTQ },
	{ "psubsb", &Instruction::decode_Pq_Qq, OP_PSUBSB },
	{ "psubsw", &Instruction::decode_Pq_Qq, OP_PSUBSW },
	{ "pminsw", &Instruction::decode_Pq_Qq, OP_PMINSW },
	{ "por", &Instruction::decode_Pq_Qq, OP_POR },  
	{ "paddsb", &Instruction::decode_Pq_Qq, OP_PADDSB },
	{ "paddsw", &Instruction::decode_Pq_Qq, OP_PADDSW },
	{ "pmaxsw", &Instruction::decode_Pq_Qq, OP_PMAXSW },
	{ "pxor", &Instruction::decode_Pq_Qq, OP_PXOR },
	
	/* 0x0f 0xf0 - 0x0f 0xff */
	{ "lddqu", &Instruction::decode_Vo_Mo, OP_LDDQU },
	{ "psllw", &Instruction::decode_Pq_Qq, OP_PSLLW },
	{ "pslld", &Instruction::decode_Pq_Qq, OP_PSLLD },
	{ "psllq", &Instruction::decode_Pq_Qq, OP_PSLLQ },
	{ "pmuludq", &Instruction::decode_Pq_Qq, OP_PMULUDQ },
	{ "pmaddwd", &Instruction::decode_Pq_Qq, OP_PMADDWD },
	{ "psadbw", &Instruction::decode_Pq_Qq, OP_PSADBW },
	{ "maskmovq", &Instruction::decode_Pq_Nq, OP_MASKMOVQ },
	{ "psubb", &Instruction::decode_Pq_Qq, OP_PSUBB },
	{ "psubw", &Instruction::decode_Pq_Qq, OP_PSUBW },
	{ "psubd", &Instruction::decode_Pq_Qq, OP_PSUBD },
	{ "psubq", &Instruction::decode_Pq_Qq, OP_PSUBQ },	
	{ "paddb", &Instruction::decode_Pq_Qq, OP_PADDB },
	{ "paddw", &Instruction::decode_Pq_Qq, OP_PADDW },
	{ "paddd", &Instruction::decode_Pq_Qq, OP_PADDD },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID }
};

// 2 byte opcodes with a f3 prefix
template <>
const Instruction<edisassm::x86_64>::OpcodeEntry Instruction<edisassm::x86_64>::Opcodes_2Byte_F3[0x100] = {

	/* 0x0f 0x00 - 0x0f 0x0f */
	{ "group6", &Instruction::decode_group6, OP_GROUP6 },
	{ "group7", &Instruction::decode_group7, OP_GROUP7 },
	{ "lar", &Instruction::decode_Gv_Ew, OP_LAR },
	{ "lsl", &Instruction::decode_Gv_Ew, OP_LSL },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "syscall", &Instruction::decode0, OP_SYSCALL },
	{ "clts", &Instruction::decode0, OP_CLTS },
	{ "sysret", &Instruction::decode0, OP_SYSRET },
	{ "invd", &Instruction::decode0, OP_INVD },
	{ "wbinvd", &Instruction::decode0, OP_WBINVD },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "ud2", &Instruction::decode0, OP_UD2 },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "nop", &Instruction::decode_Ev, OP_NOP },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	
	/* 0x0f 0x10 - 0x0f 0x1f */
	{ "movss", &Instruction::decode_Vo_Wo, OP_MOVSS },
	{ "movss", &Instruction::decode_Wo_Vo, OP_MOVSS },
	{ "movsldup", &Instruction::decode_Vq_Wq, OP_MOVSLDUP },
	{ "movlps", &Instruction::decode_Mq_Vq, OP_MOVLPS },
	{ "unpcklps", &Instruction::decode_Vo_Wq, OP_UNPCKLPS },
	{ "unpckhps", &Instruction::decode_Vo_Wq, OP_UNPCKHPS },
	{ "movshdup", &Instruction::decode_Vq_Wq, OP_MOVSHDUP },
	{ "movhps", &Instruction::decode_Mq_Vq, OP_MOVHPS },
	{ "group17", &Instruction::decode_group17, OP_GROUP17 },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "nop", &Instruction::decode_Ev, OP_NOP },
	
	/* 0x0f 0x20 - 0x0f 0x2f */
	{ "mov", &Instruction::decode_Rd_Cd, OP_MOV },
	{ "mov", &Instruction::decode_Rd_Dd, OP_MOV },
	{ "mov", &Instruction::decode_Cd_Rd, OP_MOV },
	{ "mov", &Instruction::decode_Dd_Rd, OP_MOV },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "movaps", &Instruction::decode_Vo_Wo, OP_MOVAPS },
	{ "movaps", &Instruction::decode_Wo_Vo, OP_MOVAPS },
	{ "cvtsi2ss", &Instruction::decode_Vo_Eq, OP_CVTSI2SS },	// x86: cvtsi2ss Vo, Ed
	{ "movntps",  &Instruction::decode_Mo_Vo, OP_MOVNTPS },	
	{ "cvttss2si",  &Instruction::decode_Gq_Wo, OP_CVTTSS2SI },	// x86: cvttss2si Gd, Wo
	{ "cvtss2si",  &Instruction::decode_Gq_Wo, OP_CVTSS2SI },	// x86: cvtss2si Gd, Wo
	{ "ucomiss",  &Instruction::decode_Vo_Wo, OP_UCOMISS },
	{ "comiss",  &Instruction::decode_Vo_Wo, OP_COMISS },
	
	/* 0x0f 0x30 - 0x0f 0x3f */
	{ "wrmsr", &Instruction::decode0, OP_WRMSR },
	{ "rdtsc", &Instruction::decode0, OP_RDTSC },
	{ "rdmsr", &Instruction::decode0, OP_RDMSR },
	{ "rdpmc", &Instruction::decode0, OP_RDPMC },
	{ "sysenter", &Instruction::decode0, OP_SYSENTER },
	{ "sysexit", &Instruction::decode0, OP_SYSEXIT },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "getsec", &Instruction::decode0, OP_GETSEC },
	{ "3byte", &Instruction::decode_3byte_38, OP_3BYTE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "3byte", &Instruction::decode_3byte_3A, OP_3BYTE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	
	/* 0x0f 0x40 - 0x0f 0x4f */
	{ "cmovo", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovno", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovb", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovnb", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovz", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovnz", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovb", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovnbe", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovs", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovns", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovp", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovnp", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovl", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovnl", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovle", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	{ "cmovnle", &Instruction::decode_Gv_Ev, OP_CMOVCC },
	
	/* 0x0f 0x50 - 0x0f 0x5f */
	{ "movmskps", &Instruction::decode_Gq_Uo, OP_MOVMSKPS },	// x86: movmskps Gd, Uo
	{ "sqrtss", &Instruction::decode_Vo_Wo, OP_SQRTSS },
	{ "rsqrtss", &Instruction::decode_Vo_Wo, OP_RSQRTSS },
	{ "rcpss", &Instruction::decode_Vo_Wo, OP_RCPSS },
	{ "andps", &Instruction::decode_Vo_Wo, OP_ANDPS },
	{ "andnps", &Instruction::decode_Vo_Wo, OP_ANDNPS },
	{ "orps", &Instruction::decode_Vo_Wo, OP_ORPS },
	{ "xorps", &Instruction::decode_Vo_Wo, OP_XORPS },
	{ "addss", &Instruction::decode_Vo_Wo, OP_ADDSS },
	{ "mulss", &Instruction::decode_Vo_Wo, OP_MULSS },
	{ "cvtss2sd", &Instruction::decode_Vo_Wo, OP_CVTSS2SD },
	{ "cvttps2dq", &Instruction::decode_Vo_Wo, OP_CVTTPS2DQ },
	{ "subss", &Instruction::decode_Vo_Wo, OP_SUBSS },
	{ "minss", &Instruction::decode_Vo_Wo, OP_MINSS },
	{ "divss", &Instruction::decode_Vo_Wo, OP_DIVSS },
	{ "maxss", &Instruction::decode_Vo_Wo, OP_MAXSS },
	
	/* 0x0f 0x60 - 0x0f 0x6f */
	{ "punpcklbw", &Instruction::decode_Pq_Qd, OP_PUNPCKLBW },
	{ "punpcklwd", &Instruction::decode_Pq_Qd, OP_PUNPCKLWD },
	{ "punpckldq", &Instruction::decode_Pq_Qd, OP_PUNPCKLDQ },
	{ "packsswb", &Instruction::decode_Pq_Qq, OP_PACKSSWB },
	{ "pcmpgtb", &Instruction::decode_Pq_Qq, OP_PCMPGTB },
	{ "pcmpgtw", &Instruction::decode_Pq_Qq, OP_PCMPGTW },
	{ "pcmpgtd", &Instruction::decode_Pq_Qq, OP_PCMPGTD },
	{ "packuswb", &Instruction::decode_Pq_Qq, OP_PACKUSWB },
	{ "punpckhbw", &Instruction::decode_Pq_Qd, OP_PUNPCKHBW },
	{ "punpckhwd", &Instruction::decode_Pq_Qd, OP_PUNPCKHWD },
	{ "punpckhdq", &Instruction::decode_Pq_Qd, OP_PUNPCKHDQ },
	{ "packssdw", &Instruction::decode_Pq_Qq, OP_PACKSSDW },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "movq", &Instruction::decode_Pd_Eq, OP_MOVQ },		// x86: movq Pd, Ed
	{ "movdqu", &Instruction::decode_Vo_Wo, OP_MOVDQU },
	
	/* 0x0f 0x70 - 0x0f 0x7f */
	{ "pshufhw", &Instruction::decode_Vo_Wo_Ib, OP_PSHUFHW },
	{ "group13", &Instruction::decode_group13, OP_GROUP13 },
	{ "group14", &Instruction::decode_group14, OP_GROUP14 },
	{ "group15", &Instruction::decode_group15, OP_GROUP15 },
	{ "pcmpeqb", &Instruction::decode_Pq_Qq, OP_PCMPEQB },
	{ "pcmpeqw", &Instruction::decode_Pq_Qq, OP_PCMPEQW },
	{ "pcmpeqd", &Instruction::decode_Pq_Qq, OP_PCMPEQD },
	{ "emms", &Instruction::decode0, OP_EMMS },
	{ "vmread", &Instruction::decode_Eq_Gq, OP_VMREAD },	// x86: vmread Ed, Gd
	{ "vmwrite", &Instruction::decode_Gq_Eq, OP_VMWRITE },	// x86: vmwrite Gd, Ed
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "movq", &Instruction::decode_Vq_Wq, OP_MOVQ },
	{ "movdqu", &Instruction::decode_Wo_Vo, OP_MOVDQU },
	
	/* 0x0f 0x80 - 0x0f 0x8f */
	{ "jo", &Instruction::decode_Jz, OP_JCC },
	{ "jno", &Instruction::decode_Jz, OP_JCC },
	{ "jb", &Instruction::decode_Jz, OP_JCC },
	{ "jnb", &Instruction::decode_Jz, OP_JCC },
	{ "jz", &Instruction::decode_Jz, OP_JCC },
	{ "jnz", &Instruction::decode_Jz, OP_JCC },
	{ "jbe", &Instruction::decode_Jz, OP_JCC },
	{ "jnbe", &Instruction::decode_Jz, OP_JCC },
	{ "js", &Instruction::decode_Jz, OP_JCC },
	{ "jns", &Instruction::decode_Jz, OP_JCC },
	{ "jp", &Instruction::decode_Jz, OP_JCC },
	{ "jnp", &Instruction::decode_Jz, OP_JCC },
	{ "jl", &Instruction::decode_Jz, OP_JCC },
	{ "jnl", &Instruction::decode_Jz, OP_JCC },
	{ "jle", &Instruction::decode_Jz, OP_JCC },
	{ "jnle", &Instruction::decode_Jz, OP_JCC },
	
	/* 0x0f 0x90 - 0x0f 0x9f */
	{ "seto", &Instruction::decode_Eb, OP_SETCC },
	{ "setno", &Instruction::decode_Eb, OP_SETCC },
	{ "setb", &Instruction::decode_Eb, OP_SETCC },
	{ "setnb", &Instruction::decode_Eb, OP_SETCC },
	{ "setz", &Instruction::decode_Eb, OP_SETCC },
	{ "setnz", &Instruction::decode_Eb, OP_SETCC },
	{ "setbe", &Instruction::decode_Eb, OP_SETCC },
	{ "setnbe", &Instruction::decode_Eb, OP_SETCC },
	{ "sets", &Instruction::decode_Eb, OP_SETCC },
	{ "setns", &Instruction::decode_Eb, OP_SETCC },
	{ "setp", &Instruction::decode_Eb, OP_SETCC },
	{ "setnp", &Instruction::decode_Eb, OP_SETCC },
	{ "setl", &Instruction::decode_Eb, OP_SETCC },
	{ "setnl", &Instruction::decode_Eb, OP_SETCC },
	{ "setle", &Instruction::decode_Eb, OP_SETCC },
	{ "setnle", &Instruction::decode_Eb, OP_SETCC },
	
	/* 0x0f 0xa0 - 0x0f 0xaf */
	{ "push", &Instruction::decode_Reg<operand_t::REG_FS>, OP_PUSH },
	{ "pop", &Instruction::decode_Reg<operand_t::REG_FS>, OP_POP },
	{ "cpuid", &Instruction::decode0, OP_CPUID },
	{ "bt", &Instruction::decode_Ev_Gv, OP_BT },
	{ "shld", &Instruction::decode_Ev_Gv_Ib, OP_SHLD },
	{ "shld", &Instruction::decode_Ev_Gv_Reg<operand_t::REG_CL>, OP_SHLD },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "push", &Instruction::decode_Reg<operand_t::REG_GS>, OP_PUSH },
	{ "pop", &Instruction::decode_Reg<operand_t::REG_GS>, OP_POP },
	{ "rsm", &Instruction::decode0, OP_RSM },
	{ "bts", &Instruction::decode_Ev_Gv, OP_BTS },
	{ "shrd", &Instruction::decode_Ev_Gv_Ib, OP_SHRD },
	{ "shrd", &Instruction::decode_Ev_Gv_Reg<operand_t::REG_CL>, OP_SHRD },
	{ "group16", &Instruction::decode_group16, OP_GROUP16 },
	{ "imul",  &Instruction::decode_Gv_Ev, OP_IMUL },
	
	/* 0x0f 0xb0 - 0x0f 0xbf */
	{ "cmpxchg", &Instruction::decode_Eb_Gb, OP_CMPXCHG },
	{ "cmpxchg", &Instruction::decode_Ev_Gv, OP_CMPXCHG },
	{ "lss", &Instruction::decode_Gv_Mp, OP_LSS },
	{ "btr", &Instruction::decode_Ev_Gv, OP_BTR },
	{ "lfs", &Instruction::decode_Gv_Mp, OP_LFS },
	{ "lgs", &Instruction::decode_Gv_Mp, OP_LGS },
	{ "movzx", &Instruction::decode_Gv_Eb, OP_MOVZX },
	{ "movzx", &Instruction::decode_Gv_Ew, OP_MOVZX },
	{ "popcnt", &Instruction::decode_Gv_Ev, OP_POPCNT },
	{ "group11", &Instruction::decode_group11, OP_GROUP11 },
	{ "group8", &Instruction::decode_group8, OP_GROUP8 },
	{ "btc", &Instruction::decode_Ev_Gv, OP_BTC },
	{ "bsf", &Instruction::decode_Gv_Ev, OP_BSF },
	{ "bsr", &Instruction::decode_Gv_Ev, OP_BSR },
	{ "movsx", &Instruction::decode_Gv_Eb, OP_MOVSX },
	{ "movsx", &Instruction::decode_Gv_Ew, OP_MOVSX },
	
	/* 0x0f 0xc0 - 0x0f 0xcf */
	{ "xadd", &Instruction::decode_Eb_Gb, OP_XADD },
	{ "xadd", &Instruction::decode_Ev_Gv, OP_XADD },
	{ "cmpss", &Instruction::decode_Vo_Wo_Ib, OP_CMPSS },
	{ "movnti", &Instruction::decode_Nq_Gq, OP_MOVNTI },	// x86: movnti Md, Gd
	{ "pinsrw", &Instruction::decode_Pq_Rq_Mw_Ib, OP_PINSRW },	// x86: pinsrw Pq, Rd/Mw,Ib
	{ "pextrw", &Instruction::decode_Gd_Nq_Ib, OP_PEXTRW },
	{ "shufps", &Instruction::decode_Vo_Wo_Ib, OP_SHUFPS },
	{ "group9", &Instruction::decode_group9, OP_GROUP9 },
	{ "bswap", &Instruction::decode_rAX, OP_BSWAP },
	{ "bswap", &Instruction::decode_rCX, OP_BSWAP },
	{ "bswap", &Instruction::decode_rDX, OP_BSWAP },
	{ "bswap", &Instruction::decode_rBX, OP_BSWAP },
	{ "bswap", &Instruction::decode_rSP, OP_BSWAP },
	{ "bswap", &Instruction::decode_rBP, OP_BSWAP },
	{ "bswap", &Instruction::decode_rSI, OP_BSWAP },
	{ "bswap", &Instruction::decode_rDI, OP_BSWAP },
	
	/* 0x0f 0xd0 - 0x0f 0xdf */
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "psrlw", &Instruction::decode_Pq_Qq, OP_PSRLW },
	{ "psrld", &Instruction::decode_Pq_Qq, OP_PSRLD },
	{ "psrlq", &Instruction::decode_Pq_Qq, OP_PSRLQ },
	{ "paddq", &Instruction::decode_Pq_Qq, OP_PADDQ },
	{ "pmullw", &Instruction::decode_Pq_Qq, OP_PMULLW },
	{ "movq2dq", &Instruction::decode_Vo_Nq, OP_MOVQ2DQ },
	{ "pmovmskb", &Instruction::decode_Gd_Nq, OP_PMOVMSKB },
    { "psubusb", &Instruction::decode_Pq_Qq, OP_PSUBUSB },
    { "psubusw", &Instruction::decode_Pq_Qq, OP_PSUBUSW },
    { "pminub", &Instruction::decode_Pq_Qq, OP_PMINUB },
    { "pand", &Instruction::decode_Pq_Qq, OP_PAND },
    { "paddusb", &Instruction::decode_Pq_Qq, OP_PADDUSB },
    { "paddusw", &Instruction::decode_Pq_Qq, OP_PADDUSW },
    { "pmaxub", &Instruction::decode_Pq_Qq, OP_PMAXUB },
    { "pandn", &Instruction::decode_Pq_Qq, OP_PANDN },
	
	/* 0x0f 0xe0 - 0x0f 0xef */
	{ "pavgb", &Instruction::decode_Pq_Qq, OP_PAVGB },
	{ "psraw", &Instruction::decode_Pq_Qq, OP_PSRAW },
	{ "psrad", &Instruction::decode_Pq_Qq, OP_PSRAD },
	{ "pavgw", &Instruction::decode_Pq_Qq, OP_PAVGW },
	{ "pmulhuw", &Instruction::decode_Pq_Qq, OP_PMULHUW },
	{ "pmulhw", &Instruction::decode_Pq_Qq, OP_PMULHW },
	{ "cvtdq2pd", &Instruction::decode_Vo_Wo, OP_CVTDQ2PD },
	{ "movntq", &Instruction::decode_Mq_Pq, OP_MOVNTQ },
	{ "psubsb", &Instruction::decode_Pq_Qq, OP_PSUBSB },
	{ "psubsw", &Instruction::decode_Pq_Qq, OP_PSUBSW },
	{ "pminsw", &Instruction::decode_Pq_Qq, OP_PMINSW },
	{ "por", &Instruction::decode_Pq_Qq, OP_POR },  
	{ "paddsb", &Instruction::decode_Pq_Qq, OP_PADDSB },
	{ "paddsw", &Instruction::decode_Pq_Qq, OP_PADDSW },
	{ "pmaxsw", &Instruction::decode_Pq_Qq, OP_PMAXSW },
	{ "pxor", &Instruction::decode_Pq_Qq, OP_PXOR },
	
	/* 0x0f 0xf0 - 0x0f 0xff */
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "psllw", &Instruction::decode_Pq_Qq, OP_PSLLW },
	{ "pslld", &Instruction::decode_Pq_Qq, OP_PSLLD },
	{ "psllq", &Instruction::decode_Pq_Qq, OP_PSLLQ },
	{ "pmuludq", &Instruction::decode_Pq_Qq, OP_PMULUDQ },
	{ "pmaddwd", &Instruction::decode_Pq_Qq, OP_PMADDWD },
	{ "psadbw", &Instruction::decode_Pq_Qq, OP_PSADBW },
	{ "maskmovq", &Instruction::decode_Pq_Nq, OP_MASKMOVQ },
	{ "psubb", &Instruction::decode_Pq_Qq, OP_PSUBB },
	{ "psubw", &Instruction::decode_Pq_Qq, OP_PSUBW },
	{ "psubd", &Instruction::decode_Pq_Qq, OP_PSUBD },
	{ "psubq", &Instruction::decode_Pq_Qq, OP_PSUBQ },	
	{ "paddb", &Instruction::decode_Pq_Qq, OP_PADDB },
	{ "paddw", &Instruction::decode_Pq_Qq, OP_PADDW },
	{ "paddd", &Instruction::decode_Pq_Qq, OP_PADDD },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID }
};


template <>
const Instruction<edisassm::x86_64>::OpcodeEntry Instruction<edisassm::x86_64>::Opcodes_3Byte_38_66[0x100] = {
	
	/* 0x0f 0x38 0x00 - 0x0f 0x38 0x0f */
	{ "pshufb", &Instruction::decode_Vo_Wo, OP_PSHUFB },
	{ "phaddw", &Instruction::decode_Vo_Wo, OP_PHADDW },
	{ "phaddd", &Instruction::decode_Vo_Wo, OP_PHADDD },
	{ "phaddsw", &Instruction::decode_Vo_Wo, OP_PHADDSW },
	{ "pmaddubsw", &Instruction::decode_Vo_Wo, OP_PMADDUBSW },
	{ "phsubw", &Instruction::decode_Vo_Wo, OP_PHSUBW },
	{ "phsubd", &Instruction::decode_Vo_Wo, OP_PHSUBD },
	{ "phsubsw", &Instruction::decode_Vo_Wo, OP_PHSUBSW },
	{ "psignb", &Instruction::decode_Vo_Wo, OP_PSIGNB },
	{ "psignw", &Instruction::decode_Vo_Wo, OP_PSIGNW },
	{ "psignd", &Instruction::decode_Vo_Wo, OP_PSIGND },
	{ "pmulhrsw", &Instruction::decode_Vo_Wo, OP_PMULHRSW },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	
	/* 0x0f 0x38 0x10 - 0x0f 0x38 0x1f */
	{ "pblendvb", &Instruction::decode_Vo_Wo, OP_PBLENDVB },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "blendvps", &Instruction::decode_Vo_Wo, OP_BLENDVPS },
	{ "blendvpd", &Instruction::decode_Vo_Wo, OP_BLENDVPD },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "ptest", &Instruction::decode_Vo_Wo, OP_PTEST },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "pabsb", &Instruction::decode_Vo_Wo, OP_PABSB },
	{ "pabsw", &Instruction::decode_Vo_Wo, OP_PABSW },
	{ "pabsd", &Instruction::decode_Vo_Wo, OP_PABSD },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	
	/* 0x0f 0x38 0x20 - 0x0f 0x38 0x2f */
	{ "pmovsxbw", &Instruction::decode_Vo_Uo_Mq, OP_PMOVSXBW },
	{ "pmovsxbd", &Instruction::decode_Vo_Uo_Md, OP_PMOVSXBD },
	{ "pmovsxbq", &Instruction::decode_Vo_Uo_Mw, OP_PMOVSXBQ },
	{ "pmovsxwd", &Instruction::decode_Vo_Uo_Mq, OP_PMOVSXWD },
	{ "pmovsxwq", &Instruction::decode_Vo_Uo_Md, OP_PMOVSXWQ },
	{ "pmovsxdq", &Instruction::decode_Vo_Uo_Mq, OP_PMOVSXDQ },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "pmuldq", &Instruction::decode_Vo_Wo, OP_PMULDQ },
	{ "pcmpeqq", &Instruction::decode_Vo_Wo, OP_PCMPEQQ },
	{ "movntdqa", &Instruction::decode_Vo_Mo, OP_MOVNTDQA },
	{ "packusdw", &Instruction::decode_Vo_Wo, OP_PACKUSDW },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	
	/* 0x0f 0x38 0x30 - 0x0f 0x38 0x3f */
	{ "pmovzxbw", &Instruction::decode_Vo_Uo_Mq, OP_PMOVZXBW },
	{ "pmovzxbd", &Instruction::decode_Vo_Uo_Md, OP_PMOVZXBD },
	{ "pmovzxbq", &Instruction::decode_Vo_Uo_Mw, OP_PMOVZXBQ },
	{ "pmovzxwd", &Instruction::decode_Vo_Uo_Mq, OP_PMOVZXWD },
	{ "pmovzxwq", &Instruction::decode_Vo_Uo_Md, OP_PMOVZXWQ },
	{ "pmovzxdq", &Instruction::decode_Vo_Uo_Mq, OP_PMOVZXDQ },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "pcmpgtq", &Instruction::decode_Vo_Wo, OP_PCMPGTQ },
	{ "pminsb", &Instruction::decode_Vo_Wo, OP_PMINSB },
	{ "pminsd", &Instruction::decode_Vo_Wo, OP_PMINSD },
	{ "pminuw", &Instruction::decode_Vo_Wo, OP_PMINUW },
	{ "pminud", &Instruction::decode_Vo_Wo, OP_PMINUD },
	{ "pmaxsb", &Instruction::decode_Vo_Wo, OP_PMAXSB },
	{ "pmaxsd", &Instruction::decode_Vo_Wo, OP_PMAXSD },
	{ "pmaxuw", &Instruction::decode_Vo_Wo, OP_PMAXUW },
	{ "pmaxud", &Instruction::decode_Vo_Wo, OP_PMAXUD },
	
	/* 0x0f 0x38 0x40 - 0x0f 0x38 0x4f */
	{ "pmulld", &Instruction::decode_Vo_Wo, OP_PMULLD },
	{ "phminposuw", &Instruction::decode_Vo_Wo, OP_PHMINPOSUW },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	
	/* 0x0f 0x38 0x50 - 0x0f 0x38 0x5f */
	INVALID_BLOCK,
	
	/* 0x0f 0x38 0x60 - 0x0f 0x38 0x6f */
	INVALID_BLOCK,
	
	/* 0x0f 0x38 0x70 - 0x0f 0x38 0x7f */
	INVALID_BLOCK,
	
	/* 0x0f 0x38 0x80 - 0x0f 0x38 0x8f */
	{ "nvept", &Instruction::decode_Gq_Mo, OP_NVEPT },		// x86: nvept Gd, Mo
	{ "nvvpid", &Instruction::decode_Gq_Mo, OP_NVVPID },	// x86: nvvpid Gd, Mo
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	
	/* 0x0f 0x38 0x90 - 0x0f 0x38 0x9f */
	INVALID_BLOCK,
	
	/* 0x0f 0x38 0xa0 - 0x0f 0x38 0xaf */
	INVALID_BLOCK,
	
	/* 0x0f 0x38 0xb0 - 0x0f 0x38 0xbf */
	INVALID_BLOCK,
	
	/* 0x0f 0x38 0xc0 - 0x0f 0x38 0xcf */
	INVALID_BLOCK,
	
	/* 0x0f 0x38 0xd0 - 0x0f 0x38 0xdf */
	INVALID_BLOCK,
	
	/* 0x0f 0x38 0xe0 - 0x0f 0x38 0xef */
	INVALID_BLOCK,
	
	/* 0x0f 0x38 0xf0 - 0x0f 0x38 0xff */
	{ "movbe", &Instruction::decode_Gv_Mv, OP_MOVBE },
	{ "movbe", &Instruction::decode_Mv_Gv, OP_MOVBE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
};

template <>
const Instruction<edisassm::x86_64>::OpcodeEntry Instruction<edisassm::x86_64>::Opcodes_3Byte_3A_66[0x100] = {
	/* 0x0f 0x3a 0x00 - 0x0f 0x3a 0x0f */
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "roundps", &Instruction::decode_Vo_Wo_Ib, OP_ROUNDPS },
	{ "roundpd", &Instruction::decode_Vo_Wo_Ib, OP_ROUNDPD },
	{ "roundss", &Instruction::decode_Vo_Wo_Ib, OP_ROUNDSS },
	{ "roundsd", &Instruction::decode_Vo_Wo_Ib, OP_ROUNDSD },
	{ "blendps", &Instruction::decode_Vo_Wo_Ib, OP_BLENDPS },
	{ "blendpd", &Instruction::decode_Vo_Wo_Ib, OP_BLENDPD },
	{ "pblendw", &Instruction::decode_Vo_Wo_Ib, OP_PBLENDW },
	{ "palignr", &Instruction::decode_Vo_Wo_Ib, OP_PALIGNR },
	
	/* 0x0f 0x3a 0x10 - 0x0f 0x3a 0x1f */
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "pextrb", &Instruction::decode_Rd_Mb_Vo_Ib, OP_PEXTRB },
	{ "pextrw", &Instruction::decode_Rd_Mw_Vo_Ib, OP_PEXTRW },
	{ "pextrq", &Instruction::decode_Eq_Vo_Ib, OP_PEXTRQ },		// x86: pextrq Eq, Vo, Ib
	{ "extractps", &Instruction::decode_invalid, OP_EXTRACTPS },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	
	/* 0x0f 0x3a 0x20 - 0x0f 0x3a 0x2f */
	{ "pinsrb", &Instruction::decode_Vo_Mb_Ib, OP_PINSRB },
	{ "insertps", &Instruction::decode_Vo_Md_Ib, OP_INSERTPS },
	{ "pinsrq", &Instruction::decode_Vo_Eq_Ib, OP_PINSRQ },		// x86: pinsrq Vo, Eq, Ib
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	
	/* 0x0f 0x3a 0x30 - 0x0f 0x3a 0x3f */
	INVALID_BLOCK,
	
	/* 0x0f 0x3a 0x40 - 0x0f 0x3a 0x4f */
	{ "dpps", &Instruction::decode_Vo_Wo_Ib, OP_DPPS },
	{ "dppd", &Instruction::decode_Vo_Wo_Ib, OP_DPPD },
	{ "mpsadbw", &Instruction::decode_Vo_Wo_Ib, OP_MPSADBW },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	
	/* 0x0f 0x3a 0x50 - 0x0f 0x3a 0x5f */
	INVALID_BLOCK,
	
	/* 0x0f 0x3a 0x60 - 0x0f 0x3a 0x6f */
	{ "pcmpestrm", &Instruction::decode_Vo_Wo_Ib, OP_PCMPESTRM },
	{ "pcmpestri", &Instruction::decode_Vo_Wo_Ib, OP_PCMPESTRI },
	{ "pcmpistrm", &Instruction::decode_Vo_Wo_Ib, OP_PCMPISTRM },
	{ "pcmpistri", &Instruction::decode_Vo_Wo_Ib, OP_PCMPISTRI },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	
	/* 0x0f 0x3a 0x70 - 0x0f 0x3a 0x7f */
	INVALID_BLOCK,
	
	/* 0x0f 0x3a 0x80 - 0x0f 0x3a 0x8f */
	INVALID_BLOCK,
	
	/* 0x0f 0x3a 0x90 - 0x0f 0x3a 0x9f */
	INVALID_BLOCK,
	
	/* 0x0f 0x3a 0xa0 - 0x0f 0x3a 0xaf */
	INVALID_BLOCK,
	
	/* 0x0f 0x3a 0xb0 - 0x0f 0x3a 0xbf */
	INVALID_BLOCK,
	
	/* 0x0f 0x3a 0xc0 - 0x0f 0x3a 0xcf */
	INVALID_BLOCK,
	
	/* 0x0f 0x3a 0xd0 - 0x0f 0x3a 0xdf */
	INVALID_BLOCK,
	
	/* 0x0f 0x3a 0xe0 - 0x0f 0x3a 0xef */
	INVALID_BLOCK,
	
	/* 0x0f 0x3a 0xf0 - 0x0f 0x3a 0xff */
	INVALID_BLOCK
};

#endif
