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
const typename instruction<M>::opcode_entry instruction<M>::Opcodes_3Byte_38_NA[0x100] = {

	/* 0x0f 0x38 0x00 - 0x0f 0x38 0x0f */
	{ "pshufb",    &instruction::decode_Pq_Qq,   OP_PSHUFB,    FLAG_SSSE3 },
	{ "phaddw",    &instruction::decode_Pq_Qq,   OP_PHADDW,    FLAG_SSSE3 },
	{ "phaddd",    &instruction::decode_Pq_Qq,   OP_PHADDD,    FLAG_SSSE3 },
	{ "phaddsw",   &instruction::decode_Pq_Qq,   OP_PHADDSW,   FLAG_SSSE3 },
	{ "pmaddubsw", &instruction::decode_Pq_Qq,   OP_PMADDUBSW, FLAG_SSSE3 },
	{ "phsubw",    &instruction::decode_Pq_Qq,   OP_PHSUBW,    FLAG_SSSE3 },
	{ "phsubd",    &instruction::decode_Pq_Qq,   OP_PHSUBD,    FLAG_SSSE3 },
	{ "phsubsw",   &instruction::decode_Pq_Qq,   OP_PHSUBSW,   FLAG_SSSE3 },
	{ "psignb",    &instruction::decode_Pq_Qq,   OP_PSIGNB,    FLAG_SSSE3 },
	{ "psignw",    &instruction::decode_Pq_Qq,   OP_PSIGNW,    FLAG_SSSE3 },
	{ "psignd",    &instruction::decode_Pq_Qq,   OP_PSIGND,    FLAG_SSSE3 },
	{ "pmulhrsw",  &instruction::decode_Pq_Qq,   OP_PMULHRSW,  FLAG_SSSE3 },
	{ "invalid",   &instruction::decode_invalid, OP_INVALID,   FLAG_NONE },
	{ "invalid",   &instruction::decode_invalid, OP_INVALID,   FLAG_NONE },
	{ "invalid",   &instruction::decode_invalid, OP_INVALID,   FLAG_NONE },
	{ "invalid",   &instruction::decode_invalid, OP_INVALID,   FLAG_NONE },

	/* 0x0f 0x38 0x10 - 0x0f 0x38 0x1f */
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "pabsb",   &instruction::decode_Pq_Qq,   OP_PABSB,   FLAG_SSSE3 },
	{ "pabsw",   &instruction::decode_Pq_Qq,   OP_PABSW,   FLAG_SSSE3 },
	{ "pabsd",   &instruction::decode_Pq_Qq,   OP_PABSD,   FLAG_SSSE3 },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },

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
	{ "movbe", &instruction::decode_Gv_Mv, OP_MOVBE, FLAG_NONE },
	{ "movbe", &instruction::decode_Mv_Gv, OP_MOVBE, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
};

template <class M>
const typename instruction<M>::opcode_entry instruction<M>::Opcodes_3Byte_38_F2[0x100] = {

	/* 0x0f 0x38 0x00 - 0x0f 0x38 0x0f */
	{ "pshufb", &instruction::decode_Pq_Qq, OP_PSHUFB, FLAG_SSSE3 },
	{ "phaddw", &instruction::decode_Pq_Qq, OP_PHADDW, FLAG_SSSE3 },
	{ "phaddd", &instruction::decode_Pq_Qq, OP_PHADDD, FLAG_SSSE3 },
	{ "phaddsw", &instruction::decode_Pq_Qq, OP_PHADDSW, FLAG_SSSE3 },
	{ "pmaddubsw", &instruction::decode_Pq_Qq, OP_PMADDUBSW, FLAG_SSSE3 },
	{ "phsubw", &instruction::decode_Pq_Qq, OP_PHSUBW, FLAG_SSSE3 },
	{ "phsubd", &instruction::decode_Pq_Qq, OP_PHSUBD, FLAG_SSSE3 },
	{ "phsubsw", &instruction::decode_Pq_Qq, OP_PHSUBSW, FLAG_SSSE3 },
	{ "psignb", &instruction::decode_Pq_Qq, OP_PSIGNB, FLAG_SSSE3 },
	{ "psignw", &instruction::decode_Pq_Qq, OP_PSIGNW, FLAG_SSSE3 },
	{ "psignd", &instruction::decode_Pq_Qq, OP_PSIGND, FLAG_SSSE3 },
	{ "pmulhrsw", &instruction::decode_Pq_Qq, OP_PMULHRSW, FLAG_SSSE3 },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },

	/* 0x0f 0x38 0x10 - 0x0f 0x38 0x1f */
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "pabsb",   &instruction::decode_Pq_Qq,   OP_PABSB,   FLAG_SSSE3 },
	{ "pabsw",   &instruction::decode_Pq_Qq,   OP_PABSW,   FLAG_SSSE3 },
	{ "pabsd",   &instruction::decode_Pq_Qq,   OP_PABSD,   FLAG_SSSE3 },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },

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
	{ "crc32",   &instruction::decode_Gq_Eb,   OP_CRC32,   FLAG_SSE4_2 },
	{ "crc32",   &instruction::decode_Gq_Eq,   OP_CRC32,   FLAG_SSE4_2 },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
};

template <class M>
const typename instruction<M>::opcode_entry instruction<M>::Opcodes_3Byte_38_66[0x100] = {

	/* 0x0f 0x38 0x00 - 0x0f 0x38 0x0f */
	{ "pshufb", &instruction::decode_Vo_Wo, OP_PSHUFB, FLAG_SSSE3 },
	{ "phaddw", &instruction::decode_Vo_Wo, OP_PHADDW, FLAG_SSSE3 },
	{ "phaddd", &instruction::decode_Vo_Wo, OP_PHADDD, FLAG_SSSE3 },
	{ "phaddsw", &instruction::decode_Vo_Wo, OP_PHADDSW, FLAG_SSSE3 },
	{ "pmaddubsw", &instruction::decode_Vo_Wo, OP_PMADDUBSW, FLAG_SSSE3 },
	{ "phsubw", &instruction::decode_Vo_Wo, OP_PHSUBW, FLAG_SSSE3 },
	{ "phsubd", &instruction::decode_Vo_Wo, OP_PHSUBD, FLAG_SSSE3 },
	{ "phsubsw", &instruction::decode_Vo_Wo, OP_PHSUBSW, FLAG_SSSE3 },
	{ "psignb", &instruction::decode_Vo_Wo, OP_PSIGNB, FLAG_SSSE3 },
	{ "psignw", &instruction::decode_Vo_Wo, OP_PSIGNW, FLAG_SSSE3 },
	{ "psignd", &instruction::decode_Vo_Wo, OP_PSIGND, FLAG_SSSE3 },
	{ "pmulhrsw", &instruction::decode_Vo_Wo, OP_PMULHRSW, FLAG_SSSE3 },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },

	/* 0x0f 0x38 0x10 - 0x0f 0x38 0x1f */
	{ "pblendvb", &instruction::decode_Vo_Wo,   OP_PBLENDVB, FLAG_SSE4_1 },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "blendvps", &instruction::decode_Vo_Wo,   OP_BLENDVPS, FLAG_SSE4_1 },
	{ "blendvpd", &instruction::decode_Vo_Wo,   OP_BLENDVPD, FLAG_SSE4_1 },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "ptest",    &instruction::decode_Vo_Wo,   OP_PTEST,    FLAG_SSE4_1 },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "pabsb",    &instruction::decode_Vo_Wo,   OP_PABSB,    FLAG_SSSE3 },
	{ "pabsw",    &instruction::decode_Vo_Wo,   OP_PABSW,    FLAG_SSSE3 },
	{ "pabsd",    &instruction::decode_Vo_Wo,   OP_PABSD,    FLAG_SSSE3 },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID,  FLAG_NONE },

	/* 0x0f 0x38 0x20 - 0x0f 0x38 0x2f */
	{ "pmovsxbw", &instruction::decode_Vo_Uo_Mq, OP_PMOVSXBW, FLAG_SSE4_1 },
	{ "pmovsxbd", &instruction::decode_Vo_Uo_Md, OP_PMOVSXBD, FLAG_SSE4_1 },
	{ "pmovsxbq", &instruction::decode_Vo_Uo_Mw, OP_PMOVSXBQ, FLAG_SSE4_1 },
	{ "pmovsxwd", &instruction::decode_Vo_Uo_Mq, OP_PMOVSXWD, FLAG_SSE4_1 },
	{ "pmovsxwq", &instruction::decode_Vo_Uo_Md, OP_PMOVSXWQ, FLAG_SSE4_1 },
	{ "pmovsxdq", &instruction::decode_Vo_Uo_Mq, OP_PMOVSXDQ, FLAG_SSE4_1 },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "pmuldq",   &instruction::decode_Vo_Wo,    OP_PMULDQ,   FLAG_SSE4_1 },
	{ "pcmpeqq",  &instruction::decode_Vo_Wo,    OP_PCMPEQQ,  FLAG_SSE4_1 },
	{ "movntdqa", &instruction::decode_Vo_Mo,    OP_MOVNTDQA, FLAG_SSE4_1 },
	{ "packusdw", &instruction::decode_Vo_Wo,    OP_PACKUSDW, FLAG_SSE4_1 },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },

	/* 0x0f 0x38 0x30 - 0x0f 0x38 0x3f */
	{ "pmovzxbw", &instruction::decode_Vo_Uo_Mq, OP_PMOVZXBW, FLAG_SSE4_1 },
	{ "pmovzxbd", &instruction::decode_Vo_Uo_Md, OP_PMOVZXBD, FLAG_SSE4_1 },
	{ "pmovzxbq", &instruction::decode_Vo_Uo_Mw, OP_PMOVZXBQ, FLAG_SSE4_1 },
	{ "pmovzxwd", &instruction::decode_Vo_Uo_Mq, OP_PMOVZXWD, FLAG_SSE4_1 },
	{ "pmovzxwq", &instruction::decode_Vo_Uo_Md, OP_PMOVZXWQ, FLAG_SSE4_1 },
	{ "pmovzxdq", &instruction::decode_Vo_Uo_Mq, OP_PMOVZXDQ, FLAG_SSE4_1 },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "pcmpgtq", &instruction::decode_Vo_Wo, OP_PCMPGTQ, FLAG_SSE4_2 },
	{ "pminsb", &instruction::decode_Vo_Wo, OP_PMINSB, FLAG_SSE4_1 },
	{ "pminsd", &instruction::decode_Vo_Wo, OP_PMINSD, FLAG_SSE4_1 },
	{ "pminuw", &instruction::decode_Vo_Wo, OP_PMINUW, FLAG_SSE4_1 },
	{ "pminud", &instruction::decode_Vo_Wo, OP_PMINUD, FLAG_SSE4_1 },
	{ "pmaxsb", &instruction::decode_Vo_Wo, OP_PMAXSB, FLAG_SSE4_1 },
	{ "pmaxsd", &instruction::decode_Vo_Wo, OP_PMAXSD, FLAG_SSE4_1 },
	{ "pmaxuw", &instruction::decode_Vo_Wo, OP_PMAXUW, FLAG_SSE4_1 },
	{ "pmaxud", &instruction::decode_Vo_Wo, OP_PMAXUD, FLAG_SSE4_1 },

	/* 0x0f 0x38 0x40 - 0x0f 0x38 0x4f */
	{ "pmulld", &instruction::decode_Vo_Wo, OP_PMULLD, FLAG_SSE4_1 },
	{ "phminposuw", &instruction::decode_Vo_Wo, OP_PHMINPOSUW, FLAG_SSE4_1 },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },

	/* 0x0f 0x38 0x50 - 0x0f 0x38 0x5f */
	INVALID_BLOCK,

	/* 0x0f 0x38 0x60 - 0x0f 0x38 0x6f */
	INVALID_BLOCK,

	/* 0x0f 0x38 0x70 - 0x0f 0x38 0x7f */
	INVALID_BLOCK,

	/* 0x0f 0x38 0x80 - 0x0f 0x38 0x8f */
	{ "nvept", &instruction::decode_Gd_Mo, OP_NVEPT, FLAG_NONE },   // x86-64: nvept Gq, Mo
	{ "nvvpid", &instruction::decode_Gd_Mo, OP_NVVPID, FLAG_NONE }, // x86-64: nvvpid Gq, Mo
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },

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
	{ "movbe", &instruction::decode_Gv_Mv, OP_MOVBE, FLAG_NONE },
	{ "movbe", &instruction::decode_Mv_Gv, OP_MOVBE, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
};

template <class M>
const typename instruction<M>::opcode_entry instruction<M>::Opcodes_3Byte_3A_66[0x100] = {
	/* 0x0f 0x3a 0x00 - 0x0f 0x3a 0x0f */
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "roundps", &instruction::decode_Vo_Wo_Ib, OP_ROUNDPS, FLAG_SSE4_1 },
	{ "roundpd", &instruction::decode_Vo_Wo_Ib, OP_ROUNDPD, FLAG_SSE4_1 },
	{ "roundss", &instruction::decode_Vo_Wo_Ib, OP_ROUNDSS, FLAG_SSE4_1 },
	{ "roundsd", &instruction::decode_Vo_Wo_Ib, OP_ROUNDSD, FLAG_SSE4_1 },
	{ "blendps", &instruction::decode_Vo_Wo_Ib, OP_BLENDPS, FLAG_SSE4_1 },
	{ "blendpd", &instruction::decode_Vo_Wo_Ib, OP_BLENDPD, FLAG_SSE4_1 },
	{ "pblendw", &instruction::decode_Vo_Wo_Ib, OP_PBLENDW, FLAG_SSE4_1 },
	{ "palignr", &instruction::decode_Vo_Wo_Ib, OP_PALIGNR, FLAG_SSSE3 },

	/* 0x0f 0x3a 0x10 - 0x0f 0x3a 0x1f */
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "pextrb", &instruction::decode_Rd_Mb_Vo_Ib, OP_PEXTRB, FLAG_SSE4_1 },
	{ "pextrw", &instruction::decode_Rd_Mw_Vo_Ib, OP_PEXTRW, FLAG_SSE | FLAG_SSE4_1 },
	{ "pextrd", &instruction::decode_Ed_Vo_Ib, OP_PEXTRD, FLAG_NONE },         // x86-64: pextrq Eq, Vo, Ib
	{ "extractps", &instruction::decode_Ed_Vo_Ib, OP_EXTRACTPS, FLAG_SSE4_1 }, // x86-64: extractps Ev, Vo, Ib
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },

	/* 0x0f 0x3a 0x20 - 0x0f 0x3a 0x2f */
	{ "pinsrb",   &instruction::decode_Vo_Mb_Ib, OP_PINSRB,   FLAG_SSE4_1 },
	{ "insertps", &instruction::decode_Vo_Md_Ib, OP_INSERTPS, FLAG_SSE4_1 },
	{ "pinsrd",   &instruction::decode_Vo_Ed_Ib, OP_PINSRD,   FLAG_NONE }, // x86-64: pinsrq Vo, Eq, Ib
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },

	/* 0x0f 0x3a 0x30 - 0x0f 0x3a 0x3f */
	INVALID_BLOCK,

	/* 0x0f 0x3a 0x40 - 0x0f 0x3a 0x4f */
	{ "dpps",    &instruction::decode_Vo_Wo_Ib, OP_DPPS,    FLAG_SSE4_1 },
	{ "dppd",    &instruction::decode_Vo_Wo_Ib, OP_DPPD,    FLAG_SSE4_1 },
	{ "mpsadbw", &instruction::decode_Vo_Wo_Ib, OP_MPSADBW, FLAG_SSE4_1 },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },

	/* 0x0f 0x3a 0x50 - 0x0f 0x3a 0x5f */
	INVALID_BLOCK,

	/* 0x0f 0x3a 0x60 - 0x0f 0x3a 0x6f */
	{ "pcmpestrm", &instruction::decode_Vo_Wo_Ib, OP_PCMPESTRM, FLAG_SSE4_2 | FLAG_W_FLAGS },
	{ "pcmpestri", &instruction::decode_Vo_Wo_Ib, OP_PCMPESTRI, FLAG_SSE4_2 | FLAG_W_FLAGS },
	{ "pcmpistrm", &instruction::decode_Vo_Wo_Ib, OP_PCMPISTRM, FLAG_SSE4_2 | FLAG_W_FLAGS },
	{ "pcmpistri", &instruction::decode_Vo_Wo_Ib, OP_PCMPISTRI, FLAG_SSE4_2 | FLAG_W_FLAGS },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },

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
const typename instruction<M>::opcode_entry instruction<M>::Opcodes_3Byte_3A_NA[0x100] = {
	/* 0x0f 0x3a 0x00 - 0x0f 0x3a 0x0f */
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "palignr",  &instruction::decode_Pq_Qq_Ib, OP_PALIGNR, FLAG_SSSE3 },

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
