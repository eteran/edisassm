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

#ifndef OPTABLE_GROUP16_20080314_TCC_
#define OPTABLE_GROUP16_20080314_TCC_

namespace edisassm {

template <class M>
const typename Instruction<M>::opcode_entry Instruction<M>::Opcodes_Group16_Mem[8] = {
	{ "fxsave",  &Instruction::decode_M512,    OP_FXSAVE,  FLAG_SSE },
	{ "fxrstor", &Instruction::decode_M512,    OP_FXRSTOR, FLAG_SSE },
	{ "ldmxcsr", &Instruction::decode_Md,      OP_LDMXCSR, FLAG_SSE },
	{ "stmxcsr", &Instruction::decode_Md,      OP_STMXCSR, FLAG_SSE },
	{ "xsave",   &Instruction::decode_M,       OP_XSAVE,   FLAG_NONE },
	{ "xrstor",  &Instruction::decode_M,       OP_XRSTOR,  FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "clflush", &Instruction::decode_M,       OP_CLFLUSH, FLAG_SSE2 },
};

template <class M>
const typename Instruction<M>::opcode_entry Instruction<M>::Opcodes_Group16_Reg[8] = {
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "lfence",  &Instruction::decode0,        OP_LFENCE,  FLAG_SSE2 },
	{ "mfence",  &Instruction::decode0,        OP_MFENCE,  FLAG_SSE2 },
	{ "sfence",  &Instruction::decode0,        OP_SFENCE,  FLAG_SSE },
};

}

#endif

