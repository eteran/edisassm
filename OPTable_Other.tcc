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

#ifndef OPTABLE_OTHER_20110314_TCC_
#define OPTABLE_OTHER_20110314_TCC_

namespace edisassm {

template <class M>
const typename Instruction<M>::opcode_entry Instruction<M>::Opcode_invalid =
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE };

template <class M>
const typename Instruction<M>::opcode_entry Instruction<M>::Opcodes_nop_pause_xchg[3] = {
	{ "nop",   &Instruction::decode0,                                                                        OP_NOP,   FLAG_NONE },
	{ "pause", &Instruction::decode0,                                                                        OP_PAUSE, FLAG_SSE2 },
	{ "xchg",  &Instruction::template decode2<&instruction_type::decode_rAX, &instruction_type::decode_rAX_NOREX>, OP_XCHG,  FLAG_NONE },
};

template <class M>
const typename Instruction<M>::opcode_entry Instruction<M>::Opcodes_cbw_cwde_cdqe[3] = {
	{ "cbw",  &Instruction::decode0, OP_CBW,  FLAG_NONE },
	{ "cwde", &Instruction::decode0, OP_CWDE, FLAG_NONE },
	{ "cdqe", &Instruction::decode0, OP_CDQE, FLAG_NONE },
};

template <class M>
const typename Instruction<M>::opcode_entry Instruction<M>::Opcodes_cwd_cdq_cqo[3] = {
	{ "cwd", &Instruction::decode0, OP_CWD, FLAG_NONE },
	{ "cdq", &Instruction::decode0, OP_CDQ, FLAG_NONE },
	{ "cqo", &Instruction::decode0, OP_CQO, FLAG_NONE },
};

template <class M>
const typename Instruction<M>::opcode_entry Instruction<M>::Opcodes_stosw_stosd_stosq[3] = {
	{ "stosw", &Instruction::decode0, OP_STOS, FLAG_R_FLAGS },
	{ "stosd", &Instruction::decode0, OP_STOS, FLAG_R_FLAGS },
	{ "stosq", &Instruction::decode0, OP_STOS, FLAG_R_FLAGS },
};

template <class M>
const typename Instruction<M>::opcode_entry Instruction<M>::Opcodes_lodsw_lodsd_lodsq[3] = {
	{ "lodsw", &Instruction::decode0, OP_LODS, FLAG_R_FLAGS },
	{ "lodsd", &Instruction::decode0, OP_LODS, FLAG_R_FLAGS },
	{ "lodsq", &Instruction::decode0, OP_LODS, FLAG_R_FLAGS },
};

template <class M>
const typename Instruction<M>::opcode_entry Instruction<M>::Opcodes_scasw_scasd_scasq[3] = {
	{ "scasw", &Instruction::decode0, OP_SCAS, FLAG_RW_FLAGS },
	{ "scasd", &Instruction::decode0, OP_SCAS, FLAG_RW_FLAGS },
	{ "scasq", &Instruction::decode0, OP_SCAS, FLAG_RW_FLAGS },
};

template <class M>
const typename Instruction<M>::opcode_entry Instruction<M>::Opcodes_iretw_iret_iretq[3] = {
	{ "iretw", &Instruction::decode0, OP_IRET, FLAG_W_FLAGS | FLAG_STACK },
	{ "iret",  &Instruction::decode0, OP_IRET, FLAG_W_FLAGS | FLAG_STACK },
	{ "iretq", &Instruction::decode0, OP_IRET, FLAG_W_FLAGS | FLAG_STACK },
};

template <class M>
const typename Instruction<M>::opcode_entry Instruction<M>::Opcodes_movsw_movsd_movsq[3] = {
	{ "movsw", &Instruction::decode0, OP_MOVS, FLAG_R_FLAGS },
	{ "movsd", &Instruction::decode0, OP_MOVS, FLAG_R_FLAGS },
	{ "movsq", &Instruction::decode0, OP_MOVS, FLAG_R_FLAGS },
};

template <class M>
const typename Instruction<M>::opcode_entry Instruction<M>::Opcodes_popfw_popfd_popfq[3] = {
	{ "popfw", &Instruction::decode0, OP_POPF, FLAG_STACK | FLAG_W_FLAGS },
	{ "popfd", &Instruction::decode0, OP_POPF, FLAG_STACK | FLAG_W_FLAGS },
	{ "popfq", &Instruction::decode0, OP_POPF, FLAG_STACK | FLAG_W_FLAGS },
};

template <class M>
const typename Instruction<M>::opcode_entry Instruction<M>::Opcodes_pushfw_pushfd_pushfq[3] = {
	{ "pushfw", &Instruction::decode0, OP_PUSHF, FLAG_STACK | FLAG_R_FLAGS },
	{ "pushfd", &Instruction::decode0, OP_PUSHF, FLAG_STACK | FLAG_R_FLAGS },
	{ "pushfq", &Instruction::decode0, OP_PUSHF, FLAG_STACK | FLAG_R_FLAGS },
};

template <class M>
const typename Instruction<M>::opcode_entry Instruction<M>::Opcodes_invalid_cmpxchg8b_cmpxchg16b[3] = {
	{ "invalid",    &Instruction::decode_invalid, OP_INVALID,    FLAG_NONE },
	{ "cmpxchg8b",  &Instruction::decode_Mo,      OP_CMPXCHG8B,  FLAG_W_FLAGS },
	{ "cmpxchg16b", &Instruction::decode_Mo,      OP_CMPXCHG16B, FLAG_W_FLAGS },
};

template <class M>
const typename Instruction<M>::opcode_entry Instruction<M>::Opcodes_insw_insd_invalid[3] = {
	{ "insw",    &Instruction::decode0,        OP_INS,     FLAG_R_FLAGS },
	{ "insd",    &Instruction::decode0,        OP_INS,     FLAG_R_FLAGS },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
};

template <class M>
const typename Instruction<M>::opcode_entry Instruction<M>::Opcodes_outsw_outsd_invalid[3] = {
	{ "outsw",   &Instruction::decode0,        OP_OUTS,    FLAG_R_FLAGS },
	{ "outsd",   &Instruction::decode0,        OP_OUTS,    FLAG_R_FLAGS },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
};

template <class M>
const typename Instruction<M>::opcode_entry Instruction<M>::Opcodes_cmpsw_cmpsd_cmpsq[3] = {
	{ "cmpsw",  &Instruction::decode0,         OP_CMPS,    FLAG_RW_FLAGS },
	{ "cmpsd",  &Instruction::decode0,         OP_CMPS,    FLAG_RW_FLAGS },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
};

template <class M>
const typename Instruction<M>::opcode_entry Instruction<M>::Opcodes_pushaw_pushad_invalid[3] = {
	{ "pushaw",  &Instruction::decode0,        OP_PUSHA,   FLAG_32BIT_ONLY | FLAG_STACK }, // ia-32 only
	{ "pushad",  &Instruction::decode0,        OP_PUSHA,   FLAG_32BIT_ONLY | FLAG_STACK }, // ia-32 only
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
};

template <class M>
const typename Instruction<M>::opcode_entry Instruction<M>::Opcodes_popaw_popad_invalid[3] = {
	{ "popaw",   &Instruction::decode0,        OP_POPA,    FLAG_32BIT_ONLY | FLAG_STACK }, // ia-32 only
	{ "popad",   &Instruction::decode0,        OP_POPA,    FLAG_32BIT_ONLY | FLAG_STACK }, // ia-32 only
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
};

}

#endif
