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

#ifndef OPTABLE_GROUP2_20080314_TCC_
#define OPTABLE_GROUP2_20080314_TCC_

namespace edisassm {

template <class M>
const typename Instruction<M>::opcode_entry Instruction<M>::Opcodes_Group2[16] = {
	{ "rol", &Instruction::decode_Eb_Ib, OP_ROL, FLAG_NONE },
	{ "ror", &Instruction::decode_Eb_Ib, OP_ROR, FLAG_NONE },
	{ "rcl", &Instruction::decode_Eb_Ib, OP_RCL, FLAG_NONE },
	{ "rcr", &Instruction::decode_Eb_Ib, OP_RCR, FLAG_NONE },
	{ "shl", &Instruction::decode_Eb_Ib, OP_SHL, FLAG_NONE },
	{ "shr", &Instruction::decode_Eb_Ib, OP_SHR, FLAG_NONE },
	{ "sal", &Instruction::decode_Eb_Ib, OP_SAL, FLAG_NONE },
	{ "sar", &Instruction::decode_Eb_Ib, OP_SAR, FLAG_NONE },

	{ "rol", &Instruction::decode_Ev_Ib, OP_ROL, FLAG_NONE },
	{ "ror", &Instruction::decode_Ev_Ib, OP_ROR, FLAG_NONE },
	{ "rcl", &Instruction::decode_Ev_Ib, OP_RCL, FLAG_NONE },
	{ "rcr", &Instruction::decode_Ev_Ib, OP_RCR, FLAG_NONE },
	{ "shl", &Instruction::decode_Ev_Ib, OP_SHL, FLAG_NONE },
	{ "shr", &Instruction::decode_Ev_Ib, OP_SHR, FLAG_NONE },
	{ "sal", &Instruction::decode_Ev_Ib, OP_SAL, FLAG_NONE },
	{ "sar", &Instruction::decode_Ev_Ib, OP_SAR, FLAG_NONE },
};

template <class M>
const typename Instruction<M>::opcode_entry Instruction<M>::Opcodes_Group2D[32] = {
	{ "rol", &Instruction::decode_Eb_1, OP_ROL, FLAG_NONE },
	{ "ror", &Instruction::decode_Eb_1, OP_ROR, FLAG_NONE },
	{ "rcl", &Instruction::decode_Eb_1, OP_RCL, FLAG_NONE },
	{ "rcr", &Instruction::decode_Eb_1, OP_RCR, FLAG_NONE },
	{ "shl", &Instruction::decode_Eb_1, OP_SHL, FLAG_NONE },
	{ "shr", &Instruction::decode_Eb_1, OP_SHR, FLAG_NONE },
	{ "sal", &Instruction::decode_Eb_1, OP_SAL, FLAG_NONE },
	{ "sar", &Instruction::decode_Eb_1, OP_SAR, FLAG_NONE },

	{ "rol", &Instruction::decode_Ev_1, OP_ROL, FLAG_NONE },
	{ "ror", &Instruction::decode_Ev_1, OP_ROR, FLAG_NONE },
	{ "rcl", &Instruction::decode_Ev_1, OP_RCL, FLAG_NONE },
	{ "rcr", &Instruction::decode_Ev_1, OP_RCR, FLAG_NONE },
	{ "shl", &Instruction::decode_Ev_1, OP_SHL, FLAG_NONE },
	{ "shr", &Instruction::decode_Ev_1, OP_SHR, FLAG_NONE },
	{ "sal", &Instruction::decode_Ev_1, OP_SAL, FLAG_NONE },
	{ "sar", &Instruction::decode_Ev_1, OP_SAR, FLAG_NONE },

	{ "rol", &Instruction::decode_Eb_CL, OP_ROL, FLAG_NONE },
	{ "ror", &Instruction::decode_Eb_CL, OP_ROR, FLAG_NONE },
	{ "rcl", &Instruction::decode_Eb_CL, OP_RCL, FLAG_NONE },
	{ "rcr", &Instruction::decode_Eb_CL, OP_RCR, FLAG_NONE },
	{ "shl", &Instruction::decode_Eb_CL, OP_SHL, FLAG_NONE },
	{ "shr", &Instruction::decode_Eb_CL, OP_SHR, FLAG_NONE },
	{ "sal", &Instruction::decode_Eb_CL, OP_SAL, FLAG_NONE },
	{ "sar", &Instruction::decode_Eb_CL, OP_SAR, FLAG_NONE },

	{ "rol", &Instruction::decode_Ev_CL, OP_ROL, FLAG_NONE },
	{ "ror", &Instruction::decode_Ev_CL, OP_ROR, FLAG_NONE },
	{ "rcl", &Instruction::decode_Ev_CL, OP_RCL, FLAG_NONE },
	{ "rcr", &Instruction::decode_Ev_CL, OP_RCR, FLAG_NONE },
	{ "shl", &Instruction::decode_Ev_CL, OP_SHL, FLAG_NONE },
	{ "shr", &Instruction::decode_Ev_CL, OP_SHR, FLAG_NONE },
	{ "sal", &Instruction::decode_Ev_CL, OP_SAL, FLAG_NONE },
	{ "sar", &Instruction::decode_Ev_CL, OP_SAR, FLAG_NONE },
};

}

#endif

