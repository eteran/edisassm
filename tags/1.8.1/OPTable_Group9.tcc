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

#ifndef OPTABLE_GROUP9_20080314_TCC_
#define OPTABLE_GROUP9_20080314_TCC_

namespace edisassm {

template <class M>
const typename Instruction<M>::opcode_entry Instruction<M>::Opcodes_Group9[8] = {
	{ "invalid",              &Instruction::decode_invalid,                      OP_INVALID, FLAG_NONE },
	{ "cmpxchg8b/cmpxchg16b", &Instruction::decode_invalid_cmpxchg8b_cmpxchg16b, OP_GROUP,   FLAG_NONE },
	{ "invalid",              &Instruction::decode_invalid,                      OP_INVALID, FLAG_NONE },
	{ "invalid",              &Instruction::decode_invalid,                      OP_INVALID, FLAG_NONE },
	{ "invalid",              &Instruction::decode_invalid,                      OP_INVALID, FLAG_NONE },
	{ "invalid",              &Instruction::decode_invalid,                      OP_INVALID, FLAG_NONE },
	{ "vmptrld",              &Instruction::decode_Mq,                           OP_VMPTRLD, FLAG_VMX },
	{ "vmptrst",              &Instruction::decode_Mq,                           OP_VMPTRST, FLAG_VMX },
};

template <class M>
const typename Instruction<M>::opcode_entry Instruction<M>::Opcodes_Group9_66[8] = {
	{ "invalid",              &Instruction::decode_invalid,                      OP_INVALID, FLAG_NONE },
	{ "cmpxchg8b/cmpxchg16b", &Instruction::decode_invalid_cmpxchg8b_cmpxchg16b, OP_GROUP,   FLAG_NONE },
	{ "invalid",              &Instruction::decode_invalid,                      OP_INVALID, FLAG_NONE },
	{ "invalid",              &Instruction::decode_invalid,                      OP_INVALID, FLAG_NONE },
	{ "invalid",              &Instruction::decode_invalid,                      OP_INVALID, FLAG_NONE },
	{ "invalid",              &Instruction::decode_invalid,                      OP_INVALID, FLAG_NONE },
	{ "vmclear",              &Instruction::decode_Mq,                           OP_VMCLEAR, FLAG_VMX },
	{ "vmptrst",              &Instruction::decode_Mq,                           OP_VMPTRST, FLAG_VMX },
};

template <class M>
const typename Instruction<M>::opcode_entry Instruction<M>::Opcodes_Group9_F3[8] = {
	{ "invalid",              &Instruction::decode_invalid,                       OP_INVALID, FLAG_NONE },
	{ "cmpxchg8b/cmpxchg16b", &Instruction::decode_invalid_cmpxchg8b_cmpxchg16b,  OP_GROUP,   FLAG_NONE },
	{ "invalid",              &Instruction::decode_invalid,                       OP_INVALID, FLAG_NONE },
	{ "invalid",              &Instruction::decode_invalid,                       OP_INVALID, FLAG_NONE },
	{ "invalid",              &Instruction::decode_invalid,                       OP_INVALID, FLAG_NONE },
	{ "invalid",              &Instruction::decode_invalid,                       OP_INVALID, FLAG_NONE },
	{ "vmxon",                &Instruction::decode_Mq,                            OP_VMXON,   FLAG_VMX },
	{ "vmptrst",              &Instruction::decode_Mq,                            OP_VMPTRST, FLAG_VMX },
};

}

#endif

