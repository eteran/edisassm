/*
Copyright (C) 2006 - 2014 Evan Teran
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

namespace edisassm {

template <class M>
const typename Instruction<M>::opcode_entry Instruction<M>::Opcodes_3Byte_38_NA[0x100] = {

	/* 0x0f 0x38 0x00 - 0x0f 0x38 0x0f */
	{ "pshufb",    &Instruction::decode_Pq_Qq,   OP_PSHUFB,    FLAG_SSSE3 },
	{ "phaddw",    &Instruction::decode_Pq_Qq,   OP_PHADDW,    FLAG_SSSE3 },
	{ "phaddd",    &Instruction::decode_Pq_Qq,   OP_PHADDD,    FLAG_SSSE3 },
	{ "phaddsw",   &Instruction::decode_Pq_Qq,   OP_PHADDSW,   FLAG_SSSE3 },
	{ "pmaddubsw", &Instruction::decode_Pq_Qq,   OP_PMADDUBSW, FLAG_SSSE3 },
	{ "phsubw",    &Instruction::decode_Pq_Qq,   OP_PHSUBW,    FLAG_SSSE3 },
	{ "phsubd",    &Instruction::decode_Pq_Qq,   OP_PHSUBD,    FLAG_SSSE3 },
	{ "phsubsw",   &Instruction::decode_Pq_Qq,   OP_PHSUBSW,   FLAG_SSSE3 },
	{ "psignb",    &Instruction::decode_Pq_Qq,   OP_PSIGNB,    FLAG_SSSE3 },
	{ "psignw",    &Instruction::decode_Pq_Qq,   OP_PSIGNW,    FLAG_SSSE3 },
	{ "psignd",    &Instruction::decode_Pq_Qq,   OP_PSIGND,    FLAG_SSSE3 },
	{ "pmulhrsw",  &Instruction::decode_Pq_Qq,   OP_PMULHRSW,  FLAG_SSSE3 },
	{ "invalid",   &Instruction::decode_invalid, OP_INVALID,   FLAG_NONE },
	{ "invalid",   &Instruction::decode_invalid, OP_INVALID,   FLAG_NONE },
	{ "invalid",   &Instruction::decode_invalid, OP_INVALID,   FLAG_NONE },
	{ "invalid",   &Instruction::decode_invalid, OP_INVALID,   FLAG_NONE },

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
	{ "pabsb",   &Instruction::decode_Pq_Qq,   OP_PABSB,   FLAG_SSSE3 },
	{ "pabsw",   &Instruction::decode_Pq_Qq,   OP_PABSW,   FLAG_SSSE3 },
	{ "pabsd",   &Instruction::decode_Pq_Qq,   OP_PABSD,   FLAG_SSSE3 },
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
const typename Instruction<M>::opcode_entry Instruction<M>::Opcodes_3Byte_38_F2[0x100] = {

	/* 0x0f 0x38 0x00 - 0x0f 0x38 0x0f */
	{ "pshufb", &Instruction::decode_Pq_Qq, OP_PSHUFB, FLAG_SSSE3 },
	{ "phaddw", &Instruction::decode_Pq_Qq, OP_PHADDW, FLAG_SSSE3 },
	{ "phaddd", &Instruction::decode_Pq_Qq, OP_PHADDD, FLAG_SSSE3 },
	{ "phaddsw", &Instruction::decode_Pq_Qq, OP_PHADDSW, FLAG_SSSE3 },
	{ "pmaddubsw", &Instruction::decode_Pq_Qq, OP_PMADDUBSW, FLAG_SSSE3 },
	{ "phsubw", &Instruction::decode_Pq_Qq, OP_PHSUBW, FLAG_SSSE3 },
	{ "phsubd", &Instruction::decode_Pq_Qq, OP_PHSUBD, FLAG_SSSE3 },
	{ "phsubsw", &Instruction::decode_Pq_Qq, OP_PHSUBSW, FLAG_SSSE3 },
	{ "psignb", &Instruction::decode_Pq_Qq, OP_PSIGNB, FLAG_SSSE3 },
	{ "psignw", &Instruction::decode_Pq_Qq, OP_PSIGNW, FLAG_SSSE3 },
	{ "psignd", &Instruction::decode_Pq_Qq, OP_PSIGND, FLAG_SSSE3 },
	{ "pmulhrsw", &Instruction::decode_Pq_Qq, OP_PMULHRSW, FLAG_SSSE3 },
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
	{ "pabsb",   &Instruction::decode_Pq_Qq,   OP_PABSB,   FLAG_SSSE3 },
	{ "pabsw",   &Instruction::decode_Pq_Qq,   OP_PABSW,   FLAG_SSSE3 },
	{ "pabsd",   &Instruction::decode_Pq_Qq,   OP_PABSD,   FLAG_SSSE3 },
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
	{ "crc32",   &Instruction::decode_Gq_Eb,   OP_CRC32,   FLAG_SSE4_2 },
	{ "crc32",   &Instruction::decode_Gq_Eq,   OP_CRC32,   FLAG_SSE4_2 },
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
const typename Instruction<M>::opcode_entry Instruction<M>::Opcodes_3Byte_38_66[0x100] = {

	/* 0x0f 0x38 0x00 - 0x0f 0x38 0x0f */
	{ "pshufb", &Instruction::decode_Vo_Wo, OP_PSHUFB, FLAG_SSSE3 },
	{ "phaddw", &Instruction::decode_Vo_Wo, OP_PHADDW, FLAG_SSSE3 },
	{ "phaddd", &Instruction::decode_Vo_Wo, OP_PHADDD, FLAG_SSSE3 },
	{ "phaddsw", &Instruction::decode_Vo_Wo, OP_PHADDSW, FLAG_SSSE3 },
	{ "pmaddubsw", &Instruction::decode_Vo_Wo, OP_PMADDUBSW, FLAG_SSSE3 },
	{ "phsubw", &Instruction::decode_Vo_Wo, OP_PHSUBW, FLAG_SSSE3 },
	{ "phsubd", &Instruction::decode_Vo_Wo, OP_PHSUBD, FLAG_SSSE3 },
	{ "phsubsw", &Instruction::decode_Vo_Wo, OP_PHSUBSW, FLAG_SSSE3 },
	{ "psignb", &Instruction::decode_Vo_Wo, OP_PSIGNB, FLAG_SSSE3 },
	{ "psignw", &Instruction::decode_Vo_Wo, OP_PSIGNW, FLAG_SSSE3 },
	{ "psignd", &Instruction::decode_Vo_Wo, OP_PSIGND, FLAG_SSSE3 },
	{ "pmulhrsw", &Instruction::decode_Vo_Wo, OP_PMULHRSW, FLAG_SSSE3 },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },

	/* 0x0f 0x38 0x10 - 0x0f 0x38 0x1f */
	{ "pblendvb", &Instruction::decode_Vo_Wo,   OP_PBLENDVB, FLAG_SSE4_1 },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "blendvps", &Instruction::decode_Vo_Wo,   OP_BLENDVPS, FLAG_SSE4_1 },
	{ "blendvpd", &Instruction::decode_Vo_Wo,   OP_BLENDVPD, FLAG_SSE4_1 },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "ptest",    &Instruction::decode_Vo_Wo,   OP_PTEST,    FLAG_SSE4_1 },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "pabsb",    &Instruction::decode_Vo_Wo,   OP_PABSB,    FLAG_SSSE3 },
	{ "pabsw",    &Instruction::decode_Vo_Wo,   OP_PABSW,    FLAG_SSSE3 },
	{ "pabsd",    &Instruction::decode_Vo_Wo,   OP_PABSD,    FLAG_SSSE3 },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },

	/* 0x0f 0x38 0x20 - 0x0f 0x38 0x2f */
	{ "pmovsxbw", &Instruction::decode_Vo_Uo_Mq, OP_PMOVSXBW, FLAG_SSE4_1 },
	{ "pmovsxbd", &Instruction::decode_Vo_Uo_Md, OP_PMOVSXBD, FLAG_SSE4_1 },
	{ "pmovsxbq", &Instruction::decode_Vo_Uo_Mw, OP_PMOVSXBQ, FLAG_SSE4_1 },
	{ "pmovsxwd", &Instruction::decode_Vo_Uo_Mq, OP_PMOVSXWD, FLAG_SSE4_1 },
	{ "pmovsxwq", &Instruction::decode_Vo_Uo_Md, OP_PMOVSXWQ, FLAG_SSE4_1 },
	{ "pmovsxdq", &Instruction::decode_Vo_Uo_Mq, OP_PMOVSXDQ, FLAG_SSE4_1 },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "pmuldq",   &Instruction::decode_Vo_Wo,    OP_PMULDQ,   FLAG_SSE4_1 },
	{ "pcmpeqq",  &Instruction::decode_Vo_Wo,    OP_PCMPEQQ,  FLAG_SSE4_1 },
	{ "movntdqa", &Instruction::decode_Vo_Mo,    OP_MOVNTDQA, FLAG_SSE4_1 },
	{ "packusdw", &Instruction::decode_Vo_Wo,    OP_PACKUSDW, FLAG_SSE4_1 },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },

	/* 0x0f 0x38 0x30 - 0x0f 0x38 0x3f */
	{ "pmovzxbw", &Instruction::decode_Vo_Uo_Mq, OP_PMOVZXBW, FLAG_SSE4_1 },
	{ "pmovzxbd", &Instruction::decode_Vo_Uo_Md, OP_PMOVZXBD, FLAG_SSE4_1 },
	{ "pmovzxbq", &Instruction::decode_Vo_Uo_Mw, OP_PMOVZXBQ, FLAG_SSE4_1 },
	{ "pmovzxwd", &Instruction::decode_Vo_Uo_Mq, OP_PMOVZXWD, FLAG_SSE4_1 },
	{ "pmovzxwq", &Instruction::decode_Vo_Uo_Md, OP_PMOVZXWQ, FLAG_SSE4_1 },
	{ "pmovzxdq", &Instruction::decode_Vo_Uo_Mq, OP_PMOVZXDQ, FLAG_SSE4_1 },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "pcmpgtq", &Instruction::decode_Vo_Wo, OP_PCMPGTQ, FLAG_SSE4_2 },
	{ "pminsb", &Instruction::decode_Vo_Wo, OP_PMINSB, FLAG_SSE4_1 },
	{ "pminsd", &Instruction::decode_Vo_Wo, OP_PMINSD, FLAG_SSE4_1 },
	{ "pminuw", &Instruction::decode_Vo_Wo, OP_PMINUW, FLAG_SSE4_1 },
	{ "pminud", &Instruction::decode_Vo_Wo, OP_PMINUD, FLAG_SSE4_1 },
	{ "pmaxsb", &Instruction::decode_Vo_Wo, OP_PMAXSB, FLAG_SSE4_1 },
	{ "pmaxsd", &Instruction::decode_Vo_Wo, OP_PMAXSD, FLAG_SSE4_1 },
	{ "pmaxuw", &Instruction::decode_Vo_Wo, OP_PMAXUW, FLAG_SSE4_1 },
	{ "pmaxud", &Instruction::decode_Vo_Wo, OP_PMAXUD, FLAG_SSE4_1 },

	/* 0x0f 0x38 0x40 - 0x0f 0x38 0x4f */
	{ "pmulld", &Instruction::decode_Vo_Wo, OP_PMULLD, FLAG_SSE4_1 },
	{ "phminposuw", &Instruction::decode_Vo_Wo, OP_PHMINPOSUW, FLAG_SSE4_1 },
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
	{ "nvept", &Instruction::decode_Gd_Mo, OP_NVEPT, FLAG_NONE },   // x86-64: nvept Gq, Mo
	{ "nvvpid", &Instruction::decode_Gd_Mo, OP_NVVPID, FLAG_NONE }, // x86-64: nvvpid Gq, Mo
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
const typename Instruction<M>::opcode_entry Instruction<M>::Opcodes_3Byte_3A_66[0x100] = {
	/* 0x0f 0x3a 0x00 - 0x0f 0x3a 0x0f */
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "roundps", &Instruction::decode_Vo_Wo_Ib, OP_ROUNDPS, FLAG_SSE4_1 },
	{ "roundpd", &Instruction::decode_Vo_Wo_Ib, OP_ROUNDPD, FLAG_SSE4_1 },
	{ "roundss", &Instruction::decode_Vo_Wo_Ib, OP_ROUNDSS, FLAG_SSE4_1 },
	{ "roundsd", &Instruction::decode_Vo_Wo_Ib, OP_ROUNDSD, FLAG_SSE4_1 },
	{ "blendps", &Instruction::decode_Vo_Wo_Ib, OP_BLENDPS, FLAG_SSE4_1 },
	{ "blendpd", &Instruction::decode_Vo_Wo_Ib, OP_BLENDPD, FLAG_SSE4_1 },
	{ "pblendw", &Instruction::decode_Vo_Wo_Ib, OP_PBLENDW, FLAG_SSE4_1 },
	{ "palignr", &Instruction::decode_Vo_Wo_Ib, OP_PALIGNR, FLAG_SSSE3 },

	/* 0x0f 0x3a 0x10 - 0x0f 0x3a 0x1f */
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "pextrb", &Instruction::decode_Rd_Mb_Vo_Ib, OP_PEXTRB, FLAG_SSE4_1 },
	{ "pextrw", &Instruction::decode_Rd_Mw_Vo_Ib, OP_PEXTRW, FLAG_SSE | FLAG_SSE4_1 },
	{ "pextrd", &Instruction::decode_Ed_Vo_Ib, OP_PEXTRD, FLAG_NONE },         // x86-64: pextrq Eq, Vo, Ib
	{ "extractps", &Instruction::decode_Ed_Vo_Ib, OP_EXTRACTPS, FLAG_SSE4_1 }, // x86-64: extractps Ev, Vo, Ib
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },

	/* 0x0f 0x3a 0x20 - 0x0f 0x3a 0x2f */
	{ "pinsrb",   &Instruction::decode_Vo_Mb_Ib, OP_PINSRB,   FLAG_SSE4_1 },
	{ "insertps", &Instruction::decode_Vo_Md_Ib, OP_INSERTPS, FLAG_SSE4_1 },
	{ "pinsrd",   &Instruction::decode_Vo_Ed_Ib, OP_PINSRD,   FLAG_NONE }, // x86-64: pinsrq Vo, Eq, Ib
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },

	/* 0x0f 0x3a 0x30 - 0x0f 0x3a 0x3f */
	INVALID_BLOCK,

	/* 0x0f 0x3a 0x40 - 0x0f 0x3a 0x4f */
	{ "dpps",    &Instruction::decode_Vo_Wo_Ib, OP_DPPS,    FLAG_SSE4_1 },
	{ "dppd",    &Instruction::decode_Vo_Wo_Ib, OP_DPPD,    FLAG_SSE4_1 },
	{ "mpsadbw", &Instruction::decode_Vo_Wo_Ib, OP_MPSADBW, FLAG_SSE4_1 },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },

	/* 0x0f 0x3a 0x50 - 0x0f 0x3a 0x5f */
	INVALID_BLOCK,

	/* 0x0f 0x3a 0x60 - 0x0f 0x3a 0x6f */
	{ "pcmpestrm", &Instruction::decode_Vo_Wo_Ib, OP_PCMPESTRM, FLAG_SSE4_2 | FLAG_W_FLAGS },
	{ "pcmpestri", &Instruction::decode_Vo_Wo_Ib, OP_PCMPESTRI, FLAG_SSE4_2 | FLAG_W_FLAGS },
	{ "pcmpistrm", &Instruction::decode_Vo_Wo_Ib, OP_PCMPISTRM, FLAG_SSE4_2 | FLAG_W_FLAGS },
	{ "pcmpistri", &Instruction::decode_Vo_Wo_Ib, OP_PCMPISTRI, FLAG_SSE4_2 | FLAG_W_FLAGS },
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
const typename Instruction<M>::opcode_entry Instruction<M>::Opcodes_3Byte_3A_NA[0x100] = {
	/* 0x0f 0x3a 0x00 - 0x0f 0x3a 0x0f */
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "palignr",  &Instruction::decode_Pq_Qq_Ib, OP_PALIGNR, FLAG_SSSE3 },

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

}

#endif
