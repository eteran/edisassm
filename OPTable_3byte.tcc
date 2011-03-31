/*
Copyright (C) 2006 - 2011 Evan Teran
                          eteran@alum.rit.edu
				   
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef OPTABLE_3BYTE_20080314_TCC_
#define OPTABLE_3BYTE_20080314_TCC_

#include "Operand.h"

template <class M>
const typename Instruction<M>::OpcodeEntry Instruction<M>::Opcodes_3Byte_38_NA[0x100] = {
	
	/* 0x0f 0x38 0x00 - 0x0f 0x38 0x0f */
	{ "pshufb", &Instruction::decode_Pq_Qq, OP_PSHUFB, FLAG_NONE },
	{ "phaddw", &Instruction::decode_Pq_Qq, OP_PHADDW, FLAG_NONE },
	{ "phaddd", &Instruction::decode_Pq_Qq, OP_PHADDD, FLAG_NONE },
	{ "phaddsw", &Instruction::decode_Pq_Qq, OP_PHADDSW, FLAG_NONE },
	{ "pmaddubsw", &Instruction::decode_Pq_Qq, OP_PMADDUBSW, FLAG_NONE },
	{ "phsubw", &Instruction::decode_Pq_Qq, OP_PHSUBW, FLAG_NONE },
	{ "phsubd", &Instruction::decode_Pq_Qq, OP_PHSUBD, FLAG_NONE },
	{ "phsubsw", &Instruction::decode_Pq_Qq, OP_PHSUBSW, FLAG_NONE },
	{ "psignb", &Instruction::decode_Pq_Qq, OP_PSIGNB, FLAG_NONE },
	{ "psignw", &Instruction::decode_Pq_Qq, OP_PSIGNW, FLAG_NONE },
	{ "psignd", &Instruction::decode_Pq_Qq, OP_PSIGND, FLAG_NONE },
	{ "pmulhrsw", &Instruction::decode_Pq_Qq, OP_PMULHRSW, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	
	/* 0x0f 0x38 0x10 - 0x0f 0x38 0x1f */
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "pabsb", &Instruction::decode_Pq_Qq, OP_PABSB, FLAG_NONE },
	{ "pabsw", &Instruction::decode_Pq_Qq, OP_PABSW, FLAG_NONE },
	{ "pabsd", &Instruction::decode_Pq_Qq, OP_PABSD, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	
	/* 0x0f 0x38 0x20 - 0x0f 0x38 0x2f */
	INVALID_BLOCK,
	
	/* 0x0f 0x38 0x30 - 0x0f 0x38 0x3f */
	INVALID_BLOCK,
	
	/* 0x0f 0x38 0x40 - 0x0f 0x38 0x4f */
	INVALID_BLOCK,
	
	/* 0x0f 0x38 0x50 - 0x0f 0x38 0x5f */
	INVALID_BLOCK,
	
	/* 0x0f 0x38 0x60 - 0x0f 0x38 0x6f */
	INVALID_BLOCK,
	
	/* 0x0f 0x38 0x70 - 0x0f 0x38 0x7f */
	INVALID_BLOCK,
	
	/* 0x0f 0x38 0x80 - 0x0f 0x38 0x8f */
	INVALID_BLOCK,
	
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
	{ "movbe", &Instruction::decode_Gv_Mv, OP_MOVBE, FLAG_NONE },
	{ "movbe", &Instruction::decode_Mv_Gv, OP_MOVBE, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
};

template <class M>
const typename Instruction<M>::OpcodeEntry Instruction<M>::Opcodes_3Byte_38_F2[0x100] = {
	
	/* 0x0f 0x38 0x00 - 0x0f 0x38 0x0f */
	{ "pshufb", &Instruction::decode_Pq_Qq, OP_PSHUFB, FLAG_NONE },
	{ "phaddw", &Instruction::decode_Pq_Qq, OP_PHADDW, FLAG_NONE },
	{ "phaddd", &Instruction::decode_Pq_Qq, OP_PHADDD, FLAG_NONE },
	{ "phaddsw", &Instruction::decode_Pq_Qq, OP_PHADDSW, FLAG_NONE },
	{ "pmaddubsw", &Instruction::decode_Pq_Qq, OP_PMADDUBSW, FLAG_NONE },
	{ "phsubw", &Instruction::decode_Pq_Qq, OP_PHSUBW, FLAG_NONE },
	{ "phsubd", &Instruction::decode_Pq_Qq, OP_PHSUBD, FLAG_NONE },
	{ "phsubsw", &Instruction::decode_Pq_Qq, OP_PHSUBSW, FLAG_NONE },
	{ "psignb", &Instruction::decode_Pq_Qq, OP_PSIGNB, FLAG_NONE },
	{ "psignw", &Instruction::decode_Pq_Qq, OP_PSIGNW, FLAG_NONE },
	{ "psignd", &Instruction::decode_Pq_Qq, OP_PSIGND, FLAG_NONE },
	{ "pmulhrsw", &Instruction::decode_Pq_Qq, OP_PMULHRSW, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	
	/* 0x0f 0x38 0x10 - 0x0f 0x38 0x1f */
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "pabsb", &Instruction::decode_Pq_Qq, OP_PABSB, FLAG_NONE },
	{ "pabsw", &Instruction::decode_Pq_Qq, OP_PABSW, FLAG_NONE },
	{ "pabsd", &Instruction::decode_Pq_Qq, OP_PABSD, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	
	/* 0x0f 0x38 0x20 - 0x0f 0x38 0x2f */
	INVALID_BLOCK,
	
	/* 0x0f 0x38 0x30 - 0x0f 0x38 0x3f */
	INVALID_BLOCK,
	
	/* 0x0f 0x38 0x40 - 0x0f 0x38 0x4f */
	INVALID_BLOCK,
	
	/* 0x0f 0x38 0x50 - 0x0f 0x38 0x5f */
	INVALID_BLOCK,
	
	/* 0x0f 0x38 0x60 - 0x0f 0x38 0x6f */
	INVALID_BLOCK,
	
	/* 0x0f 0x38 0x70 - 0x0f 0x38 0x7f */
	INVALID_BLOCK,
	
	/* 0x0f 0x38 0x80 - 0x0f 0x38 0x8f */
	INVALID_BLOCK,
	
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
	{ "crc32", &Instruction::decode_Gq_Eb, OP_CRC32, FLAG_NONE },
	{ "crc32", &Instruction::decode_Gq_Eq, OP_CRC32, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
};

template <class M>
const typename Instruction<M>::OpcodeEntry Instruction<M>::Opcodes_3Byte_38_66[0x100] = {
	
	/* 0x0f 0x38 0x00 - 0x0f 0x38 0x0f */
	{ "pshufb", &Instruction::decode_Vo_Wo, OP_PSHUFB, FLAG_NONE },
	{ "phaddw", &Instruction::decode_Vo_Wo, OP_PHADDW, FLAG_NONE },
	{ "phaddd", &Instruction::decode_Vo_Wo, OP_PHADDD, FLAG_NONE },
	{ "phaddsw", &Instruction::decode_Vo_Wo, OP_PHADDSW, FLAG_NONE },
	{ "pmaddubsw", &Instruction::decode_Vo_Wo, OP_PMADDUBSW, FLAG_NONE },
	{ "phsubw", &Instruction::decode_Vo_Wo, OP_PHSUBW, FLAG_NONE },
	{ "phsubd", &Instruction::decode_Vo_Wo, OP_PHSUBD, FLAG_NONE },
	{ "phsubsw", &Instruction::decode_Vo_Wo, OP_PHSUBSW, FLAG_NONE },
	{ "psignb", &Instruction::decode_Vo_Wo, OP_PSIGNB, FLAG_NONE },
	{ "psignw", &Instruction::decode_Vo_Wo, OP_PSIGNW, FLAG_NONE },
	{ "psignd", &Instruction::decode_Vo_Wo, OP_PSIGND, FLAG_NONE },
	{ "pmulhrsw", &Instruction::decode_Vo_Wo, OP_PMULHRSW, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	
	/* 0x0f 0x38 0x10 - 0x0f 0x38 0x1f */
	{ "pblendvb", &Instruction::decode_Vo_Wo, OP_PBLENDVB, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "blendvps", &Instruction::decode_Vo_Wo, OP_BLENDVPS, FLAG_NONE },
	{ "blendvpd", &Instruction::decode_Vo_Wo, OP_BLENDVPD, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "ptest", &Instruction::decode_Vo_Wo, OP_PTEST, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "pabsb", &Instruction::decode_Vo_Wo, OP_PABSB, FLAG_NONE },
	{ "pabsw", &Instruction::decode_Vo_Wo, OP_PABSW, FLAG_NONE },
	{ "pabsd", &Instruction::decode_Vo_Wo, OP_PABSD, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	
	/* 0x0f 0x38 0x20 - 0x0f 0x38 0x2f */
	{ "pmovsxbw", &Instruction::decode_Vo_Uo_Mq, OP_PMOVSXBW, FLAG_NONE },
	{ "pmovsxbd", &Instruction::decode_Vo_Uo_Md, OP_PMOVSXBD, FLAG_NONE },
	{ "pmovsxbq", &Instruction::decode_Vo_Uo_Mw, OP_PMOVSXBQ, FLAG_NONE },
	{ "pmovsxwd", &Instruction::decode_Vo_Uo_Mq, OP_PMOVSXWD, FLAG_NONE },
	{ "pmovsxwq", &Instruction::decode_Vo_Uo_Md, OP_PMOVSXWQ, FLAG_NONE },
	{ "pmovsxdq", &Instruction::decode_Vo_Uo_Mq, OP_PMOVSXDQ, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "pmuldq", &Instruction::decode_Vo_Wo, OP_PMULDQ, FLAG_NONE },
	{ "pcmpeqq", &Instruction::decode_Vo_Wo, OP_PCMPEQQ, FLAG_NONE },
	{ "movntdqa", &Instruction::decode_Vo_Mo, OP_MOVNTDQA, FLAG_NONE },
	{ "packusdw", &Instruction::decode_Vo_Wo, OP_PACKUSDW, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	
	/* 0x0f 0x38 0x30 - 0x0f 0x38 0x3f */
	{ "pmovzxbw", &Instruction::decode_Vo_Uo_Mq, OP_PMOVZXBW, FLAG_NONE },
	{ "pmovzxbd", &Instruction::decode_Vo_Uo_Md, OP_PMOVZXBD, FLAG_NONE },
	{ "pmovzxbq", &Instruction::decode_Vo_Uo_Mw, OP_PMOVZXBQ, FLAG_NONE },
	{ "pmovzxwd", &Instruction::decode_Vo_Uo_Mq, OP_PMOVZXWD, FLAG_NONE },
	{ "pmovzxwq", &Instruction::decode_Vo_Uo_Md, OP_PMOVZXWQ, FLAG_NONE },
	{ "pmovzxdq", &Instruction::decode_Vo_Uo_Mq, OP_PMOVZXDQ, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "pcmpgtq", &Instruction::decode_Vo_Wo, OP_PCMPGTQ, FLAG_NONE },
	{ "pminsb", &Instruction::decode_Vo_Wo, OP_PMINSB, FLAG_NONE },
	{ "pminsd", &Instruction::decode_Vo_Wo, OP_PMINSD, FLAG_NONE },
	{ "pminuw", &Instruction::decode_Vo_Wo, OP_PMINUW, FLAG_NONE },
	{ "pminud", &Instruction::decode_Vo_Wo, OP_PMINUD, FLAG_NONE },
	{ "pmaxsb", &Instruction::decode_Vo_Wo, OP_PMAXSB, FLAG_NONE },
	{ "pmaxsd", &Instruction::decode_Vo_Wo, OP_PMAXSD, FLAG_NONE },
	{ "pmaxuw", &Instruction::decode_Vo_Wo, OP_PMAXUW, FLAG_NONE },
	{ "pmaxud", &Instruction::decode_Vo_Wo, OP_PMAXUD, FLAG_NONE },
	
	/* 0x0f 0x38 0x40 - 0x0f 0x38 0x4f */
	{ "pmulld", &Instruction::decode_Vo_Wo, OP_PMULLD, FLAG_NONE },
	{ "phminposuw", &Instruction::decode_Vo_Wo, OP_PHMINPOSUW, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	
	/* 0x0f 0x38 0x50 - 0x0f 0x38 0x5f */
	INVALID_BLOCK,
	
	/* 0x0f 0x38 0x60 - 0x0f 0x38 0x6f */
	INVALID_BLOCK,
	
	/* 0x0f 0x38 0x70 - 0x0f 0x38 0x7f */
	INVALID_BLOCK,
	
	/* 0x0f 0x38 0x80 - 0x0f 0x38 0x8f */
	{ "nvept", &Instruction::decode_Gd_Mo, OP_NVEPT, FLAG_NONE },		// x86-64: nvept Gq, Mo
	{ "nvvpid", &Instruction::decode_Gd_Mo, OP_NVVPID, FLAG_NONE },	// x86-64: nvvpid Gq, Mo
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	
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
	{ "movbe", &Instruction::decode_Gv_Mv, OP_MOVBE, FLAG_NONE },
	{ "movbe", &Instruction::decode_Mv_Gv, OP_MOVBE, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
};

template <class M>
const typename Instruction<M>::OpcodeEntry Instruction<M>::Opcodes_3Byte_3A_66[0x100] = {
	/* 0x0f 0x3a 0x00 - 0x0f 0x3a 0x0f */
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "roundps", &Instruction::decode_Vo_Wo_Ib, OP_ROUNDPS, FLAG_NONE },
	{ "roundpd", &Instruction::decode_Vo_Wo_Ib, OP_ROUNDPD, FLAG_NONE },
	{ "roundss", &Instruction::decode_Vo_Wo_Ib, OP_ROUNDSS, FLAG_NONE },
	{ "roundsd", &Instruction::decode_Vo_Wo_Ib, OP_ROUNDSD, FLAG_NONE },
	{ "blendps", &Instruction::decode_Vo_Wo_Ib, OP_BLENDPS, FLAG_NONE },
	{ "blendpd", &Instruction::decode_Vo_Wo_Ib, OP_BLENDPD, FLAG_NONE },
	{ "pblendw", &Instruction::decode_Vo_Wo_Ib, OP_PBLENDW, FLAG_NONE },
	{ "palignr", &Instruction::decode_Vo_Wo_Ib, OP_PALIGNR, FLAG_NONE },
	
	/* 0x0f 0x3a 0x10 - 0x0f 0x3a 0x1f */
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "pextrb", &Instruction::decode_Rd_Mb_Vo_Ib, OP_PEXTRB, FLAG_NONE },
	{ "pextrw", &Instruction::decode_Rd_Mw_Vo_Ib, OP_PEXTRW, FLAG_NONE },
	{ "pextrd", &Instruction::decode_Ed_Vo_Ib, OP_PEXTRD, FLAG_NONE },		// x86-64: pextrq Eq, Vo, Ib
	{ "extractps", &Instruction::decode_invalid, OP_EXTRACTPS, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	
	/* 0x0f 0x3a 0x20 - 0x0f 0x3a 0x2f */
	{ "pinsrb", &Instruction::decode_Vo_Mb_Ib, OP_PINSRB, FLAG_NONE },
	{ "insertps", &Instruction::decode_Vo_Md_Ib, OP_INSERTPS, FLAG_NONE },
	{ "pinsrd", &Instruction::decode_Vo_Ed_Ib, OP_PINSRD, FLAG_NONE },		// x86-64: pinsrq Vo, Eq, Ib
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	
	/* 0x0f 0x3a 0x30 - 0x0f 0x3a 0x3f */
	INVALID_BLOCK,
	
	/* 0x0f 0x3a 0x40 - 0x0f 0x3a 0x4f */
	{ "dpps", &Instruction::decode_Vo_Wo_Ib, OP_DPPS, FLAG_NONE },
	{ "dppd", &Instruction::decode_Vo_Wo_Ib, OP_DPPD, FLAG_NONE },
	{ "mpsadbw", &Instruction::decode_Vo_Wo_Ib, OP_MPSADBW, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	
	/* 0x0f 0x3a 0x50 - 0x0f 0x3a 0x5f */
	INVALID_BLOCK,
	
	/* 0x0f 0x3a 0x60 - 0x0f 0x3a 0x6f */
	{ "pcmpestrm", &Instruction::decode_Vo_Wo_Ib, OP_PCMPESTRM, FLAG_NONE },
	{ "pcmpestri", &Instruction::decode_Vo_Wo_Ib, OP_PCMPESTRI, FLAG_NONE },
	{ "pcmpistrm", &Instruction::decode_Vo_Wo_Ib, OP_PCMPISTRM, FLAG_NONE },
	{ "pcmpistri", &Instruction::decode_Vo_Wo_Ib, OP_PCMPISTRI, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	
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

template <class M>
const typename Instruction<M>::OpcodeEntry Instruction<M>::Opcodes_3Byte_3A_NA[0x100] = {
	/* 0x0f 0x3a 0x00 - 0x0f 0x3a 0x0f */
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "palignr", &Instruction::decode_Pq_Qq_Ib, OP_PALIGNR, FLAG_NONE },
	
	/* 0x0f 0x3a 0x10 - 0x0f 0x3a 0x1f */
	INVALID_BLOCK,
	
	/* 0x0f 0x3a 0x20 - 0x0f 0x3a 0x2f */
	INVALID_BLOCK,
	
	/* 0x0f 0x3a 0x30 - 0x0f 0x3a 0x3f */
	INVALID_BLOCK,
	
	/* 0x0f 0x3a 0x40 - 0x0f 0x3a 0x4f */
	INVALID_BLOCK,
	
	/* 0x0f 0x3a 0x50 - 0x0f 0x3a 0x5f */
	INVALID_BLOCK,
	
	/* 0x0f 0x3a 0x60 - 0x0f 0x3a 0x6f */
	INVALID_BLOCK,
	
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
