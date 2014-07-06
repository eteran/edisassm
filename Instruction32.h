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

#ifndef INSTRUCTION_20080314_TCC_
#define INSTRUCTION_20080314_TCC_

#include <iostream>

#include "OPTable_FPU.tcc"
#include "OPTable_1byte.tcc"
#include "OPTable_2byte.tcc"
#include "OPTable_3byte.tcc"
#include "OPTable_Group1.tcc"
#include "OPTable_Group2.tcc"
#include "OPTable_Group3.tcc"
#include "OPTable_Group4.tcc"
#include "OPTable_Group5.tcc"
#include "OPTable_Group6.tcc"
#include "OPTable_Group7.tcc"
#include "OPTable_Group8.tcc"
#include "OPTable_Group9.tcc"
#include "OPTable_Group10.tcc"
#include "OPTable_Group11.tcc"
#include "OPTable_Group12.tcc"
#include "OPTable_Group13.tcc"
#include "OPTable_Group14.tcc"
#include "OPTable_Group15.tcc"
#include "OPTable_Group16.tcc"
#include "OPTable_Group17.tcc"
#include "OPTable_Other.tcc"
#include "ModRM.h"
#include "SIB.h"
#include "REX.h"
namespace edisassm {

//------------------------------------------------------------------------------
// Name: decode_Gx
//------------------------------------------------------------------------------
template <class M>
template <typename Operand<M>::Register (*REG_DECODE)(uint8_t)>
void Instruction<M>::decode_Gx() {

	const uint8_t modrm_byte = get_modrm();

	int reg_index = modrm::reg(modrm_byte);
	if(BITS == 64 && rex::is_rex(rex_byte_)) {
		reg_index |= (rex::r(rex_byte_) << 3);

		if(REG_DECODE == &index_to_reg_8) {
			if(reg_index > 3 && reg_index < 8) {
				reg_index += 12;
			}
		}
	}

	operand_type &op = next_operand();
	op.u.reg         = (*REG_DECODE)(reg_index);
	op.type_         = operand_type::TYPE_REGISTER;
}

//------------------------------------------------------------------------------
// Name: decode_STig
//------------------------------------------------------------------------------
template <class M>
template <int index>
void Instruction<M>::decode_STi() {

	operand_type &op = next_operand();
	op.u.reg         = index_to_reg_fpu(index);
	op.type_         = operand_type::TYPE_REGISTER;
}

//------------------------------------------------------------------------------
// Name: decode_ModRM_0_16
//------------------------------------------------------------------------------
template <class M>
template <typename Operand<M>::Type TYPE, typename Operand<M>::Register (*REG_DECODE)(uint8_t)>
void Instruction<M>::decode_ModRM_0_16(uint8_t rm, operand_type &op) {

	op.type_                          = TYPE;
	op.u.expression.scale             = 1;
	op.u.expression.displacement_type = operand_type::DISP_NONE;

	switch(modrm::rm(rm)) {
	case 0x00:
		op.u.expression.index = operand_type::REG_SI;
		op.u.expression.base  = operand_type::REG_BX;
		break;
	case 0x01:
		op.u.expression.index = operand_type::REG_DI;
		op.u.expression.base  = operand_type::REG_BX;
		break;
	case 0x02:
		op.u.expression.index = operand_type::REG_SI;
		op.u.expression.base  = operand_type::REG_BP;
		break;
	case 0x03:
		op.u.expression.index = operand_type::REG_DI;
		op.u.expression.base  = operand_type::REG_BP;
		break;
	case 0x04:
		op.u.expression.index = operand_type::REG_SI;
		op.u.expression.base  = operand_type::REG_NULL;
		break;
	case 0x05:
		op.u.expression.index = operand_type::REG_DI;
		op.u.expression.base  = operand_type::REG_NULL;
		break;
	case 0x06:
		op.u.expression.index             = operand_type::REG_NULL;
		op.u.expression.base              = operand_type::REG_NULL;
		op.u.expression.s_disp16          = get_displacement_s16();
		op.u.expression.displacement_type = operand_type::DISP_S16;
		break;
	case 0x07:
		op.u.expression.index = operand_type::REG_NULL;
		op.u.expression.base  = operand_type::REG_BX;
		break;
	}
}

//------------------------------------------------------------------------------
// Name: decode_ModRM_1_16
//------------------------------------------------------------------------------
template <class M>
template <typename Operand<M>::Type TYPE, typename Operand<M>::Register (*REG_DECODE)(uint8_t)>
void Instruction<M>::decode_ModRM_1_16(uint8_t rm, operand_type &op) {

	op.type_                          = TYPE;
	op.u.expression.scale             = 1;
	op.u.expression.s_disp8           = get_displacement_s8();
	op.u.expression.displacement_type = operand_type::DISP_S8;

	switch(modrm::rm(rm)) {
	case 0x00:
		op.u.expression.index = operand_type::REG_SI;
		op.u.expression.base  = operand_type::REG_BX;
		break;
	case 0x01:
		op.u.expression.index = operand_type::REG_DI;
		op.u.expression.base  = operand_type::REG_BX;
		break;
	case 0x02:
		op.u.expression.index = operand_type::REG_SI;
		op.u.expression.base  = operand_type::REG_BP;
		break;
	case 0x03:
		op.u.expression.index = operand_type::REG_DI;
		op.u.expression.base  = operand_type::REG_BP;
		break;
	case 0x04:
		op.u.expression.index = operand_type::REG_SI;
		op.u.expression.base  = operand_type::REG_NULL;
		break;
	case 0x05:
		op.u.expression.index = operand_type::REG_DI;
		op.u.expression.base  = operand_type::REG_NULL;
		break;
	case 0x06:
		op.u.expression.index = operand_type::REG_NULL;
		op.u.expression.base  = operand_type::REG_BP;
		break;
	case 0x07:
		op.u.expression.index = operand_type::REG_NULL;
		op.u.expression.base  = operand_type::REG_BX;
		break;
	}
}

//------------------------------------------------------------------------------
// Name: decode_ModRM_2_16
//------------------------------------------------------------------------------
template <class M>
template <typename Operand<M>::Type TYPE, typename Operand<M>::Register (*REG_DECODE)(uint8_t)>
void Instruction<M>::decode_ModRM_2_16(uint8_t rm, operand_type &op) {

	op.type_                          = TYPE;
	op.u.expression.scale             = 1;
	op.u.expression.s_disp16          = get_displacement_s16();
	op.u.expression.displacement_type = operand_type::DISP_S16;

	switch(modrm::rm(rm)) {
	case 0x00:
		op.u.expression.index = operand_type::REG_SI;
		op.u.expression.base  = operand_type::REG_BX;
		break;
	case 0x01:
		op.u.expression.index = operand_type::REG_DI;
		op.u.expression.base  = operand_type::REG_BX;
		break;
	case 0x02:
		op.u.expression.index = operand_type::REG_SI;
		op.u.expression.base  = operand_type::REG_BP;
		break;
	case 0x03:
		op.u.expression.index = operand_type::REG_DI;
		op.u.expression.base  = operand_type::REG_BP;
		break;
	case 0x04:
		op.u.expression.index = operand_type::REG_SI;
		op.u.expression.base  = operand_type::REG_NULL;
		break;
	case 0x05:
		op.u.expression.index = operand_type::REG_DI;
		op.u.expression.base  = operand_type::REG_NULL;
		break;
	case 0x06:
		op.u.expression.index = operand_type::REG_NULL;
		op.u.expression.base  = operand_type::REG_BP;
		break;
	case 0x07:
		op.u.expression.index = operand_type::REG_NULL;
		op.u.expression.base  = operand_type::REG_BX;
		break;
	}
}

//------------------------------------------------------------------------------
// Name: decode_Reg
//------------------------------------------------------------------------------
template <class M>
template <typename Operand<M>::Register REG>
void Instruction<M>::decode_Reg() {

	operand_type &op = next_operand();
	op.u.reg         = REG;
	op.type_         = operand_type::TYPE_REGISTER;
}

//------------------------------------------------------------------------------
// Name: decode_const_Iq
//------------------------------------------------------------------------------
template <class M>
template <int64_t IMM>
void Instruction<M>::decode_const_Iq() {

	operand_type &operand = next_operand();

	operand.u.sqword = IMM;
	operand.type_    = operand_type::TYPE_IMMEDIATE64;

	// NOTE: so far this is only used for implicit constants, other
	// ones may need a size!
	//immediate_size_ += sizeof(int64_t);
}

//------------------------------------------------------------------------------
// Name: decode_const_Id
//------------------------------------------------------------------------------
template <class M>
template <int32_t IMM>
void Instruction<M>::decode_const_Id() {

	operand_type &operand = next_operand();

	operand.u.sdword = IMM;
	operand.type_    = operand_type::TYPE_IMMEDIATE32;

	// NOTE: so far this is only used for implicit constants, other
	// ones may need a size!
	//immediate_size_ += sizeof(int32_t);
}

//------------------------------------------------------------------------------
// Name: decode_const_Iw
//------------------------------------------------------------------------------
template <class M>
template <int16_t IMM>
void Instruction<M>::decode_const_Iw() {

	operand_type &operand = next_operand();

	operand.u.sword = IMM;
	operand.type_   = operand_type::TYPE_IMMEDIATE16;

	// NOTE: so far this is only used for implicit constants, other
	// ones may need a size!
	//immediate_size_ += sizeof(int16_t);
}

//------------------------------------------------------------------------------
// Name: decode_const_Ib
//------------------------------------------------------------------------------
template <class M>
template <int8_t IMM>
void Instruction<M>::decode_const_Ib() {

	operand_type &operand = next_operand();

	operand.u.sbyte = IMM;
	operand.type_   = operand_type::TYPE_IMMEDIATE8;

	// NOTE: so far this is only used for implicit constants, other
	// ones may need a size!
	//immediate_size_ += sizeof(int8_t);
}

//------------------------------------------------------------------------------
// Name: get_modrm
//------------------------------------------------------------------------------
template <class M>
uint8_t Instruction<M>::get_modrm() {
	if(modrm_size_ == 0) {
		modrm_byte_ = next_byte();
		modrm_size_ = 1;
	}

	return modrm_byte_;
}


//------------------------------------------------------------------------------
// Name: get_sib
//------------------------------------------------------------------------------
template <class M>
uint8_t Instruction<M>::get_sib() {
	if(sib_size_ == 0) {
		sib_byte_ = next_byte();
		sib_size_ = 1;
	}

	return sib_byte_;
}

//------------------------------------------------------------------------------
// Name: get_displacement_s8
//------------------------------------------------------------------------------
template <class M>
int8_t Instruction<M>::get_displacement_s8() {
	// there should only every be one displacement value!
	if(disp_size_ != 0) {
		throw multiple_displacements(byte_index_);
	}

	int8_t ret = next_byte();
	disp_size_ = sizeof(int8_t);
	return ret;
}

//------------------------------------------------------------------------------
// Name: get_displacement_s16
//------------------------------------------------------------------------------
template <class M>
int16_t Instruction<M>::get_displacement_s16() {
	// there should only every be one displacement value!
	if(disp_size_ != 0) {
		throw multiple_displacements(byte_index_);
	}

	int16_t ret = 0;
	ret = (ret & 0xff00) | static_cast<int16_t>(next_byte());
	ret = (ret & 0x00ff) | (static_cast<int16_t>(next_byte()) << 8);

	disp_size_ = sizeof(int16_t);
	return ret;
}

//------------------------------------------------------------------------------
// Name: get_displacement_s32
//------------------------------------------------------------------------------
template <class M>
int32_t Instruction<M>::get_displacement_s32() {
	// there should only every be one displacement value!
	if(disp_size_ != 0) {
		throw multiple_displacements(byte_index_);
	}

	int32_t ret = 0;
	ret = (ret & 0xffffff00) | static_cast<int32_t>(next_byte());
	ret = (ret & 0xffff00ff) | (static_cast<int32_t>(next_byte()) << 8);
	ret = (ret & 0xff00ffff) | (static_cast<int32_t>(next_byte()) << 16);
	ret = (ret & 0x00ffffff) | (static_cast<int32_t>(next_byte()) << 24);

	disp_size_ = sizeof(int32_t);
	return ret;
}

//------------------------------------------------------------------------------
// Name: get_displacement_s64
//------------------------------------------------------------------------------
template <class M>
int64_t Instruction<M>::get_displacement_s64() {

	// there should only every be one displacement value!
	if(disp_size_ != 0) {
		throw multiple_displacements(byte_index_);
	}

	int64_t ret = 0;
	ret = (ret & 0xffffffffffffff00LL) | static_cast<int64_t>(next_byte());
	ret = (ret & 0xffffffffffff00ffLL) | (static_cast<int64_t>(next_byte()) << 8);
	ret = (ret & 0xffffffffff00ffffLL) | (static_cast<int64_t>(next_byte()) << 16);
	ret = (ret & 0xffffffff00ffffffLL) | (static_cast<int64_t>(next_byte()) << 24);
	ret = (ret & 0xffffff00ffffffffLL) | (static_cast<int64_t>(next_byte()) << 32);
	ret = (ret & 0xffff00ffffffffffLL) | (static_cast<int64_t>(next_byte()) << 40);
	ret = (ret & 0xff00ffffffffffffLL) | (static_cast<int64_t>(next_byte()) << 48);
	ret = (ret & 0x00ffffffffffffffLL) | (static_cast<int64_t>(next_byte()) << 56);

	disp_size_ = sizeof(int64_t);
	return ret;
}

//------------------------------------------------------------------------------
// Name: get_immediate_s8
//------------------------------------------------------------------------------
template <class M>
int8_t Instruction<M>::get_immediate_s8() {

	const int8_t ret = next_byte();

	immediate_size_ += sizeof(int8_t);
	return ret;
}

//------------------------------------------------------------------------------
// Name: get_immediate_s16
//------------------------------------------------------------------------------
template <class M>
int16_t Instruction<M>::get_immediate_s16() {

	int16_t ret = 0;
	ret = (ret & 0xff00) | static_cast<int16_t>(next_byte());
	ret = (ret & 0x00ff) | (static_cast<int16_t>(next_byte()) << 8);

	immediate_size_ += sizeof(int16_t);
	return ret;
}

//------------------------------------------------------------------------------
// Name: get_immediate_s32
//------------------------------------------------------------------------------
template <class M>
int32_t Instruction<M>::get_immediate_s32() {

	int32_t ret = 0;

	ret = (ret & 0xffffff00) | static_cast<int32_t>(next_byte());
	ret = (ret & 0xffff00ff) | (static_cast<int32_t>(next_byte()) << 8);
	ret = (ret & 0xff00ffff) | (static_cast<int32_t>(next_byte()) << 16);
	ret = (ret & 0x00ffffff) | (static_cast<int32_t>(next_byte()) << 24);


	immediate_size_ += sizeof(int32_t);
	return ret;
}

//------------------------------------------------------------------------------
// Name: get_immediate_s64
//------------------------------------------------------------------------------
template <class M>
int64_t Instruction<M>::get_immediate_s64() {

	int64_t ret = 0;

	ret = (ret & 0xffffffffffffff00LL) | static_cast<int64_t>(next_byte());
	ret = (ret & 0xffffffffffff00ffLL) | (static_cast<int64_t>(next_byte()) << 8);
	ret = (ret & 0xffffffffff00ffffLL) | (static_cast<int64_t>(next_byte()) << 16);
	ret = (ret & 0xffffffff00ffffffLL) | (static_cast<int64_t>(next_byte()) << 24);
	ret = (ret & 0xffffff00ffffffffLL) | (static_cast<int64_t>(next_byte()) << 32);
	ret = (ret & 0xffff00ffffffffffLL) | (static_cast<int64_t>(next_byte()) << 40);
	ret = (ret & 0xff00ffffffffffffLL) | (static_cast<int64_t>(next_byte()) << 48);
	ret = (ret & 0x00ffffffffffffffLL) | (static_cast<int64_t>(next_byte()) << 56);

	immediate_size_ += sizeof(int64_t);
	return ret;
}

//------------------------------------------------------------------------------
// Name: get_immediate_u8
//------------------------------------------------------------------------------
template <class M>
uint8_t Instruction<M>::get_immediate_u8() {

	const uint8_t ret = next_byte();

	immediate_size_ += sizeof(uint8_t);
	return ret;
}

//------------------------------------------------------------------------------
// Name: get_immediate_u16
//------------------------------------------------------------------------------
template <class M>
uint16_t Instruction<M>::get_immediate_u16() {

	uint16_t ret = 0;

	ret = (ret & 0xff00) | static_cast<uint16_t>(next_byte());
	ret = (ret & 0x00ff) | (static_cast<uint16_t>(next_byte()) << 8);

	immediate_size_ += sizeof(uint16_t);
	return ret;
}

//------------------------------------------------------------------------------
// Name: get_immediate_u32
//------------------------------------------------------------------------------
template <class M>
uint32_t Instruction<M>::get_immediate_u32() {

	uint32_t ret = 0;

	ret = (ret & 0xffffff00) | static_cast<uint32_t>(next_byte());
	ret = (ret & 0xffff00ff) | (static_cast<uint32_t>(next_byte()) << 8);
	ret = (ret & 0xff00ffff) | (static_cast<uint32_t>(next_byte()) << 16);
	ret = (ret & 0x00ffffff) | (static_cast<uint32_t>(next_byte()) << 24);

	immediate_size_ += sizeof(uint32_t);
	return ret;
}

//------------------------------------------------------------------------------
// Name: get_immediate_u64
//------------------------------------------------------------------------------
template <class M>
uint64_t Instruction<M>::get_immediate_u64() {

	uint64_t ret = 0;

	ret = (ret & 0xffffffffffffff00ULL) | static_cast<uint64_t>(next_byte());
	ret = (ret & 0xffffffffffff00ffULL) | (static_cast<uint64_t>(next_byte()) << 8);
	ret = (ret & 0xffffffffff00ffffULL) | (static_cast<uint64_t>(next_byte()) << 16);
	ret = (ret & 0xffffffff00ffffffULL) | (static_cast<uint64_t>(next_byte()) << 24);
	ret = (ret & 0xffffff00ffffffffULL) | (static_cast<uint64_t>(next_byte()) << 32);
	ret = (ret & 0xffff00ffffffffffULL) | (static_cast<uint64_t>(next_byte()) << 40);
	ret = (ret & 0xff00ffffffffffffULL) | (static_cast<uint64_t>(next_byte()) << 48);
	ret = (ret & 0x00ffffffffffffffULL) | (static_cast<uint64_t>(next_byte()) << 56);

	immediate_size_ += sizeof(uint64_t);
	return ret;
}

//------------------------------------------------------------------------------
// Name: decode_ModRM_0_32
//------------------------------------------------------------------------------
template <class M>
template <typename Operand<M>::Type TYPE, typename Operand<M>::Register (*REG_DECODE)(uint8_t), class DecodeMode>
void Instruction<M>::decode_ModRM_0_32(uint8_t rm, operand_type &operand) {

	operand.type_ = TYPE;

	if(modrm::rm(rm) == 0x04) {
		const uint8_t sib_byte = get_sib();

		int sib_index = sib::index(sib_byte);

		if(BITS == 64 && rex::is_rex(rex_byte_) && DecodeMode::value == 64) {
			sib_index |= (rex::x(rex_byte_) << 3);
		}

		if(sib_index != 0x04) {

			if(BITS == 64 && DecodeMode::value == 64) {
				operand.u.expression.index = index_to_reg_64(sib_index);
			} else {
				operand.u.expression.index = index_to_reg_32(sib_index);
			}


			operand.u.expression.scale = 1 << sib::scale(sib_byte);
		} else {
			operand.u.expression.index = operand_type::REG_NULL;
			operand.u.expression.scale = 1;
		}

		if(sib::base(sib_byte) == 0x05) {

			// we could only get here if modrm.mod == 0x00
			// so it is always sdword
			operand.u.expression.base              = operand_type::REG_NULL;
			operand.u.expression.s_disp32          = get_displacement_s32();
			operand.u.expression.displacement_type = operand_type::DISP_S32;

		} else {

			int sibbase = sib::base(sib_byte);

			if(BITS == 64 && rex::is_rex(rex_byte_) && DecodeMode::value == 64) {
				sibbase |= (rex::b(rex_byte_) << 3);
			}

			if(BITS == 64 && DecodeMode::value == 64) {
				operand.u.expression.base = index_to_reg_64(sibbase);
			} else {
				operand.u.expression.base = index_to_reg_32(sibbase);
			}
			operand.u.expression.displacement_type = operand_type::DISP_NONE;
		}
	} else if(modrm::rm(rm) == 0x05) {
		if(BITS == 64 && DecodeMode::value == 64) {
			operand.u.expression.index             = operand_type::REG_NULL;
			operand.u.expression.scale             = 1;
			operand.u.expression.base              = operand_type::REG_RIP;
			operand.u.expression.s_disp32          = get_displacement_s32();
			operand.u.expression.displacement_type = operand_type::DISP_S32;
		} else {
			operand.u.expression.index             = operand_type::REG_NULL;
			operand.u.expression.scale             = 1;
			operand.u.expression.base              = operand_type::REG_NULL;
			operand.u.expression.s_disp32          = get_displacement_s32();
			operand.u.expression.displacement_type = operand_type::DISP_S32;
		}
	} else {
		operand.u.expression.index = operand_type::REG_NULL;
		operand.u.expression.scale = 1;

		int rmbase = modrm::rm(rm);

		if(BITS == 64 && rex::is_rex(rex_byte_) && DecodeMode::value == 64) {
			rmbase |= (rex::b(rex_byte_) << 3);
		}

		if(BITS == 64 && DecodeMode::value == 64) {
			operand.u.expression.base = index_to_reg_64(rmbase);
		} else {
			operand.u.expression.base = index_to_reg_32(rmbase);
		}
		operand.u.expression.s_disp8           = 0;
		operand.u.expression.displacement_type = operand_type::DISP_NONE;
	}
}

//------------------------------------------------------------------------------
// Name: decode_ModRM_1_32
//------------------------------------------------------------------------------
template <class M>
template <typename Operand<M>::Type TYPE, typename Operand<M>::Register (*REG_DECODE)(uint8_t), class DecodeMode>
void Instruction<M>::decode_ModRM_1_32(uint8_t rm, operand_type &operand) {

	if(modrm::rm(rm) == 0x04) {

		const uint8_t sib_byte = get_sib();

		int sibbase = sib::base(sib_byte);

		if(BITS == 64 && rex::is_rex(rex_byte_) && DecodeMode::value == 64) {
			sibbase |= (rex::b(rex_byte_) << 3);
		}

		if(BITS == 64 && DecodeMode::value == 64) {
			operand.u.expression.base = index_to_reg_64(sibbase);
		} else {
			operand.u.expression.base = index_to_reg_32(sibbase);
		}
		operand.u.expression.scale = 1 << sib::scale(sib_byte);

		int sib_index = sib::index(sib_byte);

		if(BITS == 64 && rex::is_rex(rex_byte_) && DecodeMode::value == 64) {
			sib_index |= (rex::x(rex_byte_) << 3);
		}

		if(sib_index != 0x04) {
			if(BITS == 64 && DecodeMode::value == 64) {
				operand.u.expression.index = index_to_reg_64(sib_index);
			} else {
				operand.u.expression.index = index_to_reg_32(sib_index);
			}
		} else {
			operand.u.expression.index = operand_type::REG_NULL;
		}
	} else {
		operand.u.expression.index = operand_type::REG_NULL;
		operand.u.expression.scale = 1;

		int rmbase = modrm::rm(rm);

		if(BITS == 64 && rex::is_rex(rex_byte_) && DecodeMode::value == 64) {
			rmbase |= (rex::b(rex_byte_) << 3);
		}

		if(BITS == 64 && DecodeMode::value == 64) {
			operand.u.expression.base = index_to_reg_64(rmbase);
		} else {
			operand.u.expression.base = index_to_reg_32(rmbase);
		}

	}

	operand.type_                          = TYPE;
	operand.u.expression.s_disp8           = get_displacement_s8();
	operand.u.expression.displacement_type = operand_type::DISP_S8;
}

//------------------------------------------------------------------------------
// Name: decode_ModRM_2_32
//------------------------------------------------------------------------------
template <class M>
template <typename Operand<M>::Type TYPE, typename Operand<M>::Register (*REG_DECODE)(uint8_t), class DecodeMode>
void Instruction<M>::decode_ModRM_2_32(uint8_t rm, operand_type &operand) {

	if(modrm::rm(rm) == 0x04) {
		const uint8_t sib_byte = get_sib();

		int sibbase = sib::base(sib_byte);

		if(BITS == 64 && rex::is_rex(rex_byte_) && DecodeMode::value == 64) {
			sibbase |= (rex::b(rex_byte_) << 3);
		}

		if(BITS == 64 && DecodeMode::value == 64) {
			operand.u.expression.base = index_to_reg_64(sibbase);
		} else {
			operand.u.expression.base = index_to_reg_32(sibbase);
		}

		operand.u.expression.scale = 1 << sib::scale(sib_byte);

		int sib_index = sib::index(sib_byte);

		if(BITS == 64 && rex::is_rex(rex_byte_) && DecodeMode::value == 64) {
			sib_index |= (rex::x(rex_byte_) << 3);
		}

		if(sib_index != 0x04) {
			if(BITS == 64 && DecodeMode::value == 64) {
				operand.u.expression.index = index_to_reg_64(sib_index);
			} else {
				operand.u.expression.index = index_to_reg_32(sib_index);
			}

		} else {
			operand.u.expression.index = operand_type::REG_NULL;
		}
	} else {
		operand.u.expression.index = operand_type::REG_NULL;
		operand.u.expression.scale = 1;

		int rmbase = modrm::rm(rm);

		if(BITS == 64 && rex::is_rex(rex_byte_) && DecodeMode::value == 64) {
			rmbase |= (rex::b(rex_byte_) << 3);
		}

		if(BITS == 64 && DecodeMode::value == 64) {
			operand.u.expression.base = index_to_reg_64(rmbase);
		} else {
			operand.u.expression.base = index_to_reg_32(rmbase);
		}

	}

	operand.type_                          = TYPE;
	operand.u.expression.s_disp32          = get_displacement_s32();
	operand.u.expression.displacement_type = operand_type::DISP_S32;
}

//------------------------------------------------------------------------------
// Name: decode_ModRM_3_32
//------------------------------------------------------------------------------
template <class M>
template <typename Operand<M>::Type TYPE, typename Operand<M>::Register (*REG_DECODE)(uint8_t), class DecodeMode>
void Instruction<M>::decode_ModRM_3_32(uint8_t rm, operand_type &operand) {

	int rmbase = modrm::rm(rm);

	if(BITS == 64 && rex::is_rex(rex_byte_) && DecodeMode::value == 64) {
		rmbase |= (rex::b(rex_byte_) << 3);
		if(REG_DECODE == &index_to_reg_8) {
			if(rmbase > 3 && rmbase < 8) {
				rmbase += 12;
			}
		}
	}

	operand.u.reg = (*REG_DECODE)(rmbase);
	operand.type_ = operand_type::TYPE_REGISTER;
}

//------------------------------------------------------------------------------
// Name: decode_ModRM_Invalid
//------------------------------------------------------------------------------
template <class M>
template <typename Operand<M>::Type TYPE, typename Operand<M>::Register (*REG_DECODE)(uint8_t)>
void Instruction<M>::decode_ModRM_Invalid(uint8_t modrm_byte, operand_type &operand) {
	(void)modrm_byte;
	(void)operand;
	
	throw invalid_operand(byte_index_);
}

//------------------------------------------------------------------------------
// Name: decode_Ex
//------------------------------------------------------------------------------
template <class M>
template <typename Operand<M>::Type TYPE, typename Operand<M>::Register (*REG_DECODE)(uint8_t)>
void Instruction<M>::decode_Ex() {

	uint8_t modrm_byte = get_modrm();
	
	// it seems that for these cases, the processor just *ignores* the
	// memory selection part of the ModRM. So to simulate this, we just 
	// force that part to have a value indicating a register
	if(TYPE == operand_type::TYPE_INVALID) {
		modrm_byte |= 0xc0;
	}

	operand_type &operand = next_operand();

	if(prefix_ & PREFIX_ADDRESS) {
		if(BITS == 64) {
			// TODO: should this be forced to 
			switch(modrm::mod(modrm_byte)) {
			case 0x00:
				decode_ModRM_0_32<TYPE, REG_DECODE, modrm_32>(modrm_byte, operand);
				break;
			case 0x01:
				decode_ModRM_1_32<TYPE, REG_DECODE, modrm_32>(modrm_byte, operand);
				break;
			case 0x02:
				decode_ModRM_2_32<TYPE, REG_DECODE, modrm_32>(modrm_byte, operand);
				break;
			case 0x03:
				decode_ModRM_3_32<TYPE, REG_DECODE, modrm_32>(modrm_byte, operand);
				break;
			}
		} else {
			switch(modrm::mod(modrm_byte)) {
			case 0x00:
				decode_ModRM_0_16<TYPE, REG_DECODE>(modrm_byte, operand);
				break;
			case 0x01:
				decode_ModRM_1_16<TYPE, REG_DECODE>(modrm_byte, operand);
				break;
			case 0x02:
				decode_ModRM_2_16<TYPE, REG_DECODE>(modrm_byte, operand);
				break;
			case 0x03:
				// same as in 32-bit mode!
				decode_ModRM_3_32<TYPE, REG_DECODE, modrm_64>(modrm_byte, operand);
				break;
			}
		}
	} else {
		switch(modrm::mod(modrm_byte)) {
		case 0x00:
			decode_ModRM_0_32<TYPE, REG_DECODE, modrm_64>(modrm_byte, operand);
			break;
		case 0x01:
			decode_ModRM_1_32<TYPE, REG_DECODE, modrm_64>(modrm_byte, operand);
			break;
		case 0x02:
			decode_ModRM_2_32<TYPE, REG_DECODE, modrm_64>(modrm_byte, operand);
			break;
		case 0x03:
			decode_ModRM_3_32<TYPE, REG_DECODE, modrm_64>(modrm_byte, operand);
			break;
		}
	}
}

//------------------------------------------------------------------------------
// Name: ~Instruction
//------------------------------------------------------------------------------
template <class M>
Instruction<M>::~Instruction() {
	delete byte_stream_;
}

//------------------------------------------------------------------------------
// Name: disassemble
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::disassemble() {

	for(int i = 0; i < M::MAX_OPERANDS; ++i) {
		operands_[i].invalidate();
	}

	process_prefixes();

	// get the first byte of the actual opcode
	byte1_ = next_byte();

	// find the entry in the table
	opcode_ = &Opcodes[byte1_];

	// decode it
	(this->*(opcode_->decoder))();
}

//------------------------------------------------------------------------------
// Name: Instruction
//------------------------------------------------------------------------------
template <class M>
Instruction<M>::Instruction(const Instruction &other) :
	byte_stream_(other.byte_stream_->clone()), byte_index_(other.byte_index_), byte1_(other.byte1_), byte2_(other.byte2_),
	byte3_(other.byte3_), modrm_byte_(other.modrm_byte_),
	sib_byte_(other.sib_byte_), rex_byte_(other.rex_byte_), rva_(other.rva_),
	opcode_(other.opcode_), prefix_(other.prefix_),
	mandatory_prefix_(other.mandatory_prefix_),
	operand_count_(other.operand_count_), modrm_size_(other.modrm_size_),
	sib_size_(other.sib_size_), disp_size_(other.disp_size_),
	prefix_size_(other.prefix_size_), immediate_size_(other.immediate_size_),
	rex_size_(other.rex_size_) {

	for(int i = 0; i < M::MAX_OPERANDS; ++i) {
		operands_[i] = other.operands_[i];
		operands_[i].set_owner(this);
	}

	std::copy(other.bytes_, other.bytes_ + sizeof(other.bytes_), bytes_);
}

//------------------------------------------------------------------------------
// Name: operator=
//------------------------------------------------------------------------------
template <class M>
Instruction<M> &Instruction<M>::operator=(const Instruction &rhs) {
	if(this != &rhs) {
		Instruction(rhs).swap(*this);
	}
	return *this;
}

//------------------------------------------------------------------------------
// Name: swap
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::swap(Instruction &other) {
	using std::swap;

	for(int i = 0; i < MAX_OPERANDS; ++i) {
		operands_[i].swap(other.operands_[i]);
	}

	for(int i = 0; i < MAX_SIZE; ++i) {
		swap(bytes_[i], other.bytes_[i]);
	}

	swap(byte_stream_,      other.byte_stream_);
	swap(byte1_,            other.byte1_);
	swap(byte2_,            other.byte2_);
	swap(byte3_,            other.byte3_);
	swap(byte_index_,       other.byte_index_);
	swap(disp_size_,        other.disp_size_);
	swap(immediate_size_,   other.immediate_size_);
	swap(mandatory_prefix_, other.mandatory_prefix_);
	swap(modrm_byte_,       other.modrm_byte_);
	swap(modrm_size_,       other.modrm_size_);
	swap(opcode_,           other.opcode_);
	swap(operand_count_,    other.operand_count_);
	swap(prefix_,           other.prefix_);
	swap(prefix_size_,      other.prefix_size_);
	swap(rex_byte_,         other.rex_byte_);
	swap(rex_size_,         other.rex_size_);
	swap(rva_,              other.rva_);
	swap(sib_byte_,         other.sib_byte_);
	swap(sib_size_,         other.sib_size_);

}

//------------------------------------------------------------------------------
// Name: process_prefixes
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::process_prefixes() {

	bool done = false;

	// we only allow one prefix from each group to be set,
	// currently, the last one from a given group in the stream
	// will take precedence
	do {
		if(byte_stream_->empty()) {
			break;
		}

		switch(byte_stream_->peek()) {
		// group1
		case 0xf0:
			prefix_ = (prefix_ & 0xffffff00) | PREFIX_LOCK;
			break;
		case 0xf2:
			prefix_ = (prefix_ & 0xffffff00) | PREFIX_REPNE;
			break;
		case 0xf3:
			prefix_ = (prefix_ & 0xffffff00) | PREFIX_REP;
			break;
		// group2
		case 0x2e:
			prefix_ = (prefix_ & 0xffff00ff) | PREFIX_CS;
			break;
		case 0x36:
			prefix_ = (prefix_ & 0xffff00ff) | PREFIX_SS;
			break;
		case 0x3e:
			prefix_ = (prefix_ & 0xffff00ff) | PREFIX_DS;
			break;
		case 0x26:
			prefix_ = (prefix_ & 0xffff00ff) | PREFIX_ES;
			break;
		case 0x64:
			prefix_ = (prefix_ & 0xffff00ff) | PREFIX_FS;
			break;
		case 0x65:
			prefix_ = (prefix_ & 0xffff00ff) | PREFIX_GS;
			break;
		#if 0
		case 0x2e:
			prefix_ = (prefix_ & 0xffff00ff) | PREFIX_BRANCH_NOT_TAKEN;
			break;
		case 0x3e:
			prefix_ = (prefix_ & 0xffff00ff) | PREFIX_BRANCH_TAKEN;
			break;
		#endif
		// group3
		case 0x66:
			prefix_ = (prefix_ & 0xff00ffff) | PREFIX_OPERAND;
			break;
		// group4
		case 0x67:
			prefix_ = (prefix_ & 0x00ffffff) | PREFIX_ADDRESS;
			break;
		default:
			done = true;
			break;
		}

		// this if will get merged with the while's condition if the optimiser
		// is smart
		if(!done) {
			next_byte();
			++prefix_size_;
		}
	} while(!done);

	if(BITS == 64) {
		if(!byte_stream_->empty() && rex::is_rex(byte_stream_->peek())) {
			rex_byte_ = next_byte();
			++rex_size_;
		}
	}
}

//------------------------------------------------------------------------------
// Name: next_operand
//------------------------------------------------------------------------------
template <class M>
typename Instruction<M>::operand_type &Instruction<M>::next_operand() {

	if(operand_count_ >= MAX_OPERANDS) {
		throw too_many_operands(byte_index_);
	}

	operand_type &ret = operands_[operand_count_++];
	ret.set_owner(this);
	return ret;
}

//------------------------------------------------------------------------------
// Name: next_byte
//------------------------------------------------------------------------------
template <class M>
uint8_t Instruction<M>::next_byte() {

	if(byte_index_ == MAX_SIZE) {
		throw instruction_too_big(byte_index_);
	}

	if(byte_stream_->empty()) {
		throw instruction_too_big(byte_index_);
	}

	const uint8_t x = byte_stream_->next();
	bytes_[byte_index_++] = x;
	return x;
}

//------------------------------------------------------------------------------
// Name: decode_invalid
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_invalid() {
	throw invalid_instruction(byte_index_);
}

template <class M> void Instruction<M>::decode_cbw_cwde_cdqe()                { decode_size_sensitive(Opcodes_cbw_cwde_cdqe); }
template <class M> void Instruction<M>::decode_cwd_cdq_cqo()                  { decode_size_sensitive(Opcodes_cwd_cdq_cqo);}
template <class M> void Instruction<M>::decode_stosw_stosd_stosq()            { decode_size_sensitive(Opcodes_stosw_stosd_stosq);}
template <class M> void Instruction<M>::decode_lodsw_lodsd_lodsq()            { decode_size_sensitive(Opcodes_lodsw_lodsd_lodsq);}
template <class M> void Instruction<M>::decode_scasw_scasd_scasq()            { decode_size_sensitive(Opcodes_scasw_scasd_scasq);}
template <class M> void Instruction<M>::decode_iretw_iret_iretq()             { decode_size_sensitive(Opcodes_iretw_iret_iretq);}
template <class M> void Instruction<M>::decode_movsw_movsd_movsq()            { decode_size_sensitive(Opcodes_movsw_movsd_movsq);}
template <class M> void Instruction<M>::decode_popfw_popfd_popfq()            { decode_size_sensitive(Opcodes_popfw_popfd_popfq);}
template <class M> void Instruction<M>::decode_pushfw_pushfd_pushfq()         { decode_size_sensitive(Opcodes_pushfw_pushfd_pushfq);}
template <class M> void Instruction<M>::decode_invalid_cmpxchg8b_cmpxchg16b() { decode_size_sensitive(Opcodes_invalid_cmpxchg8b_cmpxchg16b);}
template <class M> void Instruction<M>::decode_insw_insd_invalid()            { decode_size_sensitive(Opcodes_insw_insd_invalid);}
template <class M> void Instruction<M>::decode_outsw_outsd_invalid()          { decode_size_sensitive(Opcodes_outsw_outsd_invalid);}
template <class M> void Instruction<M>::decode_cmpsw_cmpsd_cmpsq()            { decode_size_sensitive(Opcodes_cmpsw_cmpsd_cmpsq);}
template <class M> void Instruction<M>::decode_pushaw_pushad_invalid()        { decode_size_sensitive(Opcodes_pushaw_pushad_invalid);}
template <class M> void Instruction<M>::decode_popaw_popad_invalid()          { decode_size_sensitive(Opcodes_popaw_popad_invalid);}

//------------------------------------------------------------------------------
// Name: decode_jcxz_jecxz_jrcxz
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_jcxz_jecxz_jrcxz() {

	static const opcode_entry opcodes[3] = {
		{ "jcxz",  &Instruction::decode_Jb, OP_JCC, FLAG_R_FLAGS },
		{ "jecxz", &Instruction::decode_Jb, OP_JCC, FLAG_R_FLAGS },
		{ "jrcxz", &Instruction::decode_Jb, OP_JCC, FLAG_R_FLAGS }
	};

	switch(address_size()) {
	case 16: opcode_ = &opcodes[0]; break;
	case 32: opcode_ = &opcodes[1]; break;
	case 64: opcode_ = &opcodes[2]; break;
	}
	(this->*(opcode_->decoder))();
}

//------------------------------------------------------------------------------
// Name: wait_or_wait_prefix
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::wait_or_wait_prefix() {

	// opcode 0x9b... is annoying :-P
	static const opcode_entry Opcodes_wait[1] = {
		{ "wait",   &Instruction::decode0, OP_WAIT,   FLAG_NONE },
	};

	static const opcode_entry Opcodes_wait_prefix_d9[2] = {
		{ "fstenv", &Instruction::decode_M,  OP_FSTENV, FLAG_FPU },
		{ "fstcw",  &Instruction::decode_Mw, OP_FSTCW,  FLAG_FPU },
	};

	static const opcode_entry Opcodes_wait_prefix_db[5] = {
		{ "feni",   &Instruction::decode0, OP_FENI,   FLAG_FPU },
		{ "fdisi",  &Instruction::decode0, OP_FDISI,  FLAG_FPU },
		{ "fclex",  &Instruction::decode0, OP_FCLEX,  FLAG_FPU | FLAG_W_FLAGS },
		{ "finit",  &Instruction::decode0, OP_FINIT,  FLAG_FPU },
		{ "fsetpm", &Instruction::decode0, OP_FSETPM, FLAG_FPU },
	};

	static const opcode_entry Opcodes_wait_prefix_dd[2] = {
		{ "fsave", &Instruction::decode_M,  OP_FSAVE, FLAG_FPU },
		{ "fstsw", &Instruction::decode_Mw, OP_FSTSW, FLAG_FPU },
	};

	static const opcode_entry Opcodes_wait_prefix_df[2] = {
		{ "fstsw", &Instruction::decode_AX, OP_FSTSW, FLAG_FPU },
	};

	opcode_ = &Opcodes_wait[0];

	if(!byte_stream_->empty()) {
		switch(byte_stream_->peek()) {
		case 0xd9:
			{
				// consume the 0xd9
				next_byte();

				switch(modrm::reg(byte_stream_->peek())) {
				case 0x06:
					opcode_ = &Opcodes_wait_prefix_d9[0];
					break;
				case 0x07:
					opcode_ = &Opcodes_wait_prefix_d9[1];
					break;
				}
			}
			break;
		case 0xdb:
			{
				// consume the 0xdb
				next_byte();

				switch(byte_stream_->peek()) {
				case 0xe0:
					opcode_ = &Opcodes_wait_prefix_db[0];
					next_byte();
					break;
				case 0xe1:
					opcode_ = &Opcodes_wait_prefix_db[1];
					next_byte();
					break;
				case 0xe2:
					opcode_ = &Opcodes_wait_prefix_db[2];
					next_byte();
					break;
				case 0xe3:
					opcode_ = &Opcodes_wait_prefix_db[3];
					next_byte();
					break;
				case 0xe4:
					opcode_ = &Opcodes_wait_prefix_db[4];
					next_byte();
					break;
				}
			}
			break;
		case 0xdd:
			{
				// consume the 0xdd
				next_byte();

				switch(modrm::reg(byte_stream_->peek())) {
				case 0x06:
					opcode_ = &Opcodes_wait_prefix_dd[0];
					break;
				case 0x07:
					opcode_ = &Opcodes_wait_prefix_dd[1];
					break;
				}
			}
			break;
		case 0xdf:
			{
				// consume the 0xdf
				next_byte();

				switch(byte_stream_->peek()) {
				case 0xe0:
					opcode_ = &Opcodes_wait_prefix_df[0];
					next_byte();
					break;
				}
			}
			break;
		}
	}

	(this->*(opcode_->decoder))();
}


//------------------------------------------------------------------------------
// Name: decode_x87
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_x87() {

	const uint8_t modrm_byte = get_modrm();
	const uint8_t esc_num = (byte1_ - 0xd8);

	if((modrm_byte & 0xc0) != 0xc0) {
		opcode_ = &Opcodes_x87_Lo[modrm::reg(modrm_byte) + esc_num * 8];
	} else {
		opcode_ = &Opcodes_x87_Hi[(modrm_byte & 0x3f) + esc_num * 64];
	}

	(this->*(opcode_->decoder))();
}

//------------------------------------------------------------------------------
// Name: decode_2byte
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_2byte() {

	byte2_ = next_byte();

	if(prefix_ & PREFIX_OPERAND) {
		// 0x66
		mandatory_prefix_ |= PREFIX_OPERAND;
		opcode_ = &Opcodes_2Byte_66[byte2_];
	} else if(prefix_ & PREFIX_REPNE) {
		// 0xf2
		mandatory_prefix_ |= PREFIX_REPNE;
		opcode_ = &Opcodes_2Byte_F2[byte2_];
	} else if(prefix_ & PREFIX_REP) {
		// 0xf3
		mandatory_prefix_ |= PREFIX_REP;
		opcode_ = &Opcodes_2Byte_F3[byte2_];
	} else {
		// N/A
		opcode_ = &Opcodes_2Byte_NA[byte2_];
	}

	(this->*(opcode_->decoder))();
}

//------------------------------------------------------------------------------
// Name: decode_3byte_38
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_3byte_38() {

	byte3_ = next_byte();

	if(prefix_ & PREFIX_OPERAND) {
		// 0x66
		mandatory_prefix_ |= PREFIX_OPERAND;
		opcode_ = &Opcodes_3Byte_38_66[byte3_];
	} else if(prefix_ & PREFIX_REPNE) {
		// 0xf2
		mandatory_prefix_ |= PREFIX_REPNE;
		opcode_ = &Opcodes_3Byte_38_F2[byte3_];
	} else {
		// N/A
		opcode_ = &Opcodes_3Byte_38_NA[byte3_];
	}

	(this->*(opcode_->decoder))();
}

//------------------------------------------------------------------------------
// Name: decode_3byte_3A
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_3byte_3A() {

	byte3_ = next_byte();

	if(prefix_ & PREFIX_OPERAND) {
		// 0x66
		mandatory_prefix_ |= PREFIX_OPERAND;
		opcode_ = &Opcodes_3Byte_3A_66[byte3_];
	} else {
		// N/A
		opcode_ = &Opcodes_3Byte_3A_NA[byte3_];
	}

	(this->*(opcode_->decoder))();
}

//------------------------------------------------------------------------------
// Name: decode_group1
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_group1() {

	const uint8_t modrm_byte = get_modrm();

	opcode_ = &Opcodes_Group1[modrm::reg(modrm_byte) + 8 * (byte1_ & 3)];
	(this->*(opcode_->decoder))();
}

//------------------------------------------------------------------------------
// Name: decode_group2
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_group2() {

	const uint8_t modrm_byte = get_modrm();

	opcode_ = &Opcodes_Group2[modrm::reg(modrm_byte) + 8 * (byte1_ & 1)];
	(this->*(opcode_->decoder))();
}

//------------------------------------------------------------------------------
// Name: decode_group2D
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_group2D() {

	const uint8_t modrm_byte = get_modrm();

	opcode_ = &Opcodes_Group2D[modrm::reg(modrm_byte) + 8 * (byte1_ & 3)];
	(this->*(opcode_->decoder))();
}

//------------------------------------------------------------------------------
// Name: decode_group3
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_group3() {

	const uint8_t modrm_byte = get_modrm();

	opcode_ = &Opcodes_Group3[modrm::reg(modrm_byte) + 8 * ((byte1_ - 6) & 1)];
	(this->*(opcode_->decoder))();
}

//------------------------------------------------------------------------------
// Name: decode_group4
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_group4() {

	const uint8_t modrm_byte = get_modrm();

	opcode_ = &Opcodes_Group4[modrm::reg(modrm_byte)];
	(this->*(opcode_->decoder))();
}

//------------------------------------------------------------------------------
// Name: decode_group5
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_group5() {

	const uint8_t modrm_byte = get_modrm();

	opcode_ = &Opcodes_Group5[modrm::reg(modrm_byte)];
	(this->*(opcode_->decoder))();
}

//------------------------------------------------------------------------------
// Name: decode_group6
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_group6() {

	const uint8_t modrm_byte = get_modrm();

	opcode_ = &Opcodes_Group6[modrm::reg(modrm_byte)];
	(this->*(opcode_->decoder))();
}

//------------------------------------------------------------------------------
// Name: decode_group7
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_group7() {

	const uint8_t modrm_byte = get_modrm();

	const uint8_t index = modrm::reg(modrm_byte);

	if(modrm::mod(modrm_byte) == 0x03) {
		opcode_ = &Opcodes_Group7A[(index << 3) | modrm::rm(modrm_byte)];
	} else {
		opcode_ = &Opcodes_Group7[index];
	}
	(this->*(opcode_->decoder))();
}

//------------------------------------------------------------------------------
// Name: decode_group8
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_group8() {

	const uint8_t modrm_byte = get_modrm();

	opcode_ = &Opcodes_Group8[modrm::reg(modrm_byte)];
	(this->*(opcode_->decoder))();
}

//------------------------------------------------------------------------------
// Name: decode_group9
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_group9() {

	const uint8_t modrm_byte = get_modrm();

	const uint8_t index = modrm::reg(modrm_byte);

	if(prefix_ & PREFIX_OPERAND) {
		// 0x66
		opcode_ = &Opcodes_Group9_66[index];
	} else if(prefix_ & PREFIX_REP) {
		// 0xf3
		opcode_ = &Opcodes_Group9_F3[index];
	} else {
		// N/A
		opcode_ = &Opcodes_Group9[index];
	}

	(this->*(opcode_->decoder))();
}


//------------------------------------------------------------------------------
// Name: decode_group10
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_group10() {

	const uint8_t modrm_byte = get_modrm();

	opcode_ = &Opcodes_Group10[modrm::reg(modrm_byte)];
	(this->*(opcode_->decoder))();
}


//------------------------------------------------------------------------------
// Name: decode_group11
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_group11() {

	const uint8_t modrm_byte = get_modrm();

	opcode_ = &Opcodes_Group11[modrm::reg(modrm_byte)];
	(this->*(opcode_->decoder))();
}


//------------------------------------------------------------------------------
// Name: decode_group12
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_group12() {

	const uint8_t modrm_byte = get_modrm();

	opcode_ = &Opcodes_Group12[modrm::reg(modrm_byte) + 8 * ((byte1_ - 6) & 1)];
	(this->*(opcode_->decoder))();
}

//------------------------------------------------------------------------------
// Name: decode_group13
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_group13() {

	const uint8_t modrm_byte = get_modrm();

	const uint8_t index = modrm::reg(modrm_byte);

	if(prefix_ & PREFIX_OPERAND) {
		// 0x66
		opcode_ = &Opcodes_Group13_66[index];
	} else {
		// N/A
		opcode_ = &Opcodes_Group13[index];
	}

	(this->*(opcode_->decoder))();
}


//------------------------------------------------------------------------------
// Name: decode_group14
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_group14() {

	const uint8_t modrm_byte = get_modrm();

	const uint8_t index = modrm::reg(modrm_byte);

	if(prefix_ & PREFIX_OPERAND) {
		// 0x66
		opcode_ = &Opcodes_Group14_66[index];
	} else {
		// N/A
		opcode_ = &Opcodes_Group14[index];
	}

	(this->*(opcode_->decoder))();
}


//------------------------------------------------------------------------------
// Name: decode_group15
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_group15() {

	const uint8_t modrm_byte = get_modrm();

	const uint8_t index = modrm::reg(modrm_byte);

	if(prefix_ & PREFIX_OPERAND) {
		// 0x66
		opcode_ = &Opcodes_Group15_66[index];
	} else {
		// N/A
		opcode_ = &Opcodes_Group15[index];
	}

	(this->*(opcode_->decoder))();
}

//------------------------------------------------------------------------------
// Name: decode_group16
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_group16() {

	const uint8_t modrm_byte = get_modrm();

	const uint8_t index = modrm::reg(modrm_byte);

	if(modrm::mod(modrm_byte) == 0x03) {
		opcode_ = &Opcodes_Group16_Reg[index];
	} else {
		opcode_ = &Opcodes_Group16_Mem[index];
	}

	(this->*(opcode_->decoder))();
}

//------------------------------------------------------------------------------
// Name: decode_group17
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_group17() {

	const uint8_t modrm_byte = get_modrm();

	opcode_ = &Opcodes_Group17[modrm::reg(modrm_byte) + 8 * (byte2_ - 0x18)];
	(this->*(opcode_->decoder))();
}

//------------------------------------------------------------------------------
// Name: decode_Ap
// Desc: absolute pointer (32 or 48 bit)
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_Ap() {

	operand_type &operand = next_operand();
	operand.type_      = operand_type::TYPE_ABSOLUTE;

	if(prefix_ & PREFIX_OPERAND) {
		operand.u.absolute.offset = get_immediate_u16();
	} else {
		operand.u.absolute.offset = get_immediate_u32();
	}

	operand.u.absolute.seg = get_immediate_u16();
}

//------------------------------------------------------------------------------
// Name: decode_Ib
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_Ib() {
	operand_type &operand = next_operand();

	operand.u.sbyte = get_immediate_s8();
	operand.type_   = operand_type::TYPE_IMMEDIATE8;
}

//------------------------------------------------------------------------------
// Name: decode_Iw
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_Iw() {
	operand_type &operand = next_operand();

	operand.u.sword = get_immediate_s16();
	operand.type_   = operand_type::TYPE_IMMEDIATE16;
}

//------------------------------------------------------------------------------
// Name: decode_Id
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_Id() {
	operand_type &operand = next_operand();

	operand.u.sdword = get_immediate_s32();
	operand.type_    = operand_type::TYPE_IMMEDIATE32;
}

//------------------------------------------------------------------------------
// Name: decode_Iq
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_Iq() {
	operand_type &operand = next_operand();

	operand.u.sqword = get_immediate_s64();
	operand.type_    = operand_type::TYPE_IMMEDIATE64;
}

//------------------------------------------------------------------------------
// Name: decode_Jb
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_Jb() {

	operand_type &operand = next_operand();

	operand.u.sbyte = get_immediate_s8();
	operand.type_   = operand_type::TYPE_REL8;
}

//------------------------------------------------------------------------------
// Name: decode_Jw
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_Jw() {

	operand_type &operand = next_operand();

	operand.u.sword = get_immediate_s16();
	operand.type_   = operand_type::TYPE_REL16;
}

//------------------------------------------------------------------------------
// Name: decode_Jd
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_Jd() {

	operand_type &operand = next_operand();

	operand.u.sdword = get_immediate_s32();
	operand.type_    = operand_type::TYPE_REL32;
}

//------------------------------------------------------------------------------
// Name: decode_Jq
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_Jq() {

	operand_type &operand = next_operand();

	operand.u.sqword = get_immediate_s64();
	operand.type_    = operand_type::TYPE_REL64;
}

//------------------------------------------------------------------------------
// Name: decode_Ev
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_Ev() {

	switch(operand_size()) {
	case 16: decode_Ex<operand_type::TYPE_EXPRESSION16, &Instruction::index_to_reg_16>(); break;
	case 32: decode_Ex<operand_type::TYPE_EXPRESSION32, &Instruction::index_to_reg_32>(); break;
	case 64: decode_Ex<operand_type::TYPE_EXPRESSION64, &Instruction::index_to_reg_64>(); break;
	}
}

//------------------------------------------------------------------------------
// Name: decode_Rv
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_Rv() {
	switch(operand_size()) {
	case 16: decode_Ex<operand_type::TYPE_INVALID, &Instruction::index_to_reg_16>(); break;
	case 32: decode_Ex<operand_type::TYPE_INVALID, &Instruction::index_to_reg_32>(); break;
	case 64: decode_Ex<operand_type::TYPE_INVALID, &Instruction::index_to_reg_64>(); break;
	}
}

//------------------------------------------------------------------------------
// Name: decode_Gv
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_Gv() {

	switch(operand_size()) {
	case 16: decode_Gx<&Instruction::index_to_reg_16>(); break;
	case 32: decode_Gx<&Instruction::index_to_reg_32>(); break;
	case 64: decode_Gx<&Instruction::index_to_reg_64>(); break;
	}
}

//------------------------------------------------------------------------------
// Name: decode_Iv
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_Iv() {
	switch(operand_size()) {
	case 16: decode_Iw(); break;
	case 32: decode_Id(); break;
	case 64: decode_Iq(); break;
	}
}

//------------------------------------------------------------------------------
// Name: decode_Ob
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_Ob() {
	operand_type &operand = next_operand();

	operand.type_                          = operand_type::TYPE_EXPRESSION8;
	operand.u.expression.displacement_type = operand_type::DISP_S32;
	operand.u.expression.index             = operand_type::REG_NULL;
	operand.u.expression.base              = operand_type::REG_NULL;
	operand.u.expression.scale             = 1;
	operand.u.expression.s_disp32          = get_displacement_s32();
}

//------------------------------------------------------------------------------
// Name: decode_Ow
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_Ow() {
	operand_type &operand = next_operand();

	operand.type_                          = operand_type::TYPE_EXPRESSION16;
	operand.u.expression.displacement_type = operand_type::DISP_S32;
	operand.u.expression.index             = operand_type::REG_NULL;
	operand.u.expression.base              = operand_type::REG_NULL;
	operand.u.expression.scale             = 1;
	operand.u.expression.s_disp32          = get_displacement_s32();
}

//------------------------------------------------------------------------------
// Name: decode_Od
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_Od() {
	operand_type &operand = next_operand();

	operand.type_                          = operand_type::TYPE_EXPRESSION32;
	operand.u.expression.displacement_type = operand_type::DISP_S32;
	operand.u.expression.index             = operand_type::REG_NULL;
	operand.u.expression.base              = operand_type::REG_NULL;
	operand.u.expression.scale             = 1;
	operand.u.expression.s_disp32          = get_displacement_s32();
}

//------------------------------------------------------------------------------
// Name: decode_Ov
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_Ov() {
	switch(operand_size()) {
	case 16: decode_Ow(); break;
	case 32: decode_Od(); break;
	case 64: throw invalid_instruction(byte_index_); break;
	}
}

//------------------------------------------------------------------------------
// Name: decode_Mv
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_Mv() {
	switch(operand_size()) {
	case 16: decode_Mw(); break;
	case 32: decode_Md(); break;
	case 64: decode_Mq(); break;
	}
}

//------------------------------------------------------------------------------
// Name: decode_AL
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_AL() {
	if(BITS == 64 && rex::is_rex(rex_byte_) && rex::b(rex_byte_)) {
		decode_Reg<operand_type::REG_R8B>();
	} else {
		decode_Reg<operand_type::REG_AL>();
	}
}

//------------------------------------------------------------------------------
// Name: decode_CL
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_CL() {
	if(BITS == 64 && rex::is_rex(rex_byte_) && rex::b(rex_byte_)) {
		decode_Reg<operand_type::REG_R9B>();
	} else {
		decode_Reg<operand_type::REG_CL>();
	}
}

//------------------------------------------------------------------------------
// Name: decode_DL
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_DL() {
	if(BITS == 64 && rex::is_rex(rex_byte_) && rex::b(rex_byte_)) {
		decode_Reg<operand_type::REG_R10B>();
	} else {
		decode_Reg<operand_type::REG_DL>();
	}
}

//------------------------------------------------------------------------------
// Name: decode_BL
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_BL() {
	if(BITS == 64 && rex::is_rex(rex_byte_) && rex::b(rex_byte_)) {
		decode_Reg<operand_type::REG_R11B>();
	} else {
		decode_Reg<operand_type::REG_BL>();
	}
}

//------------------------------------------------------------------------------
// Name: decode_AH
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_AH() {
	if(BITS == 64 && rex::is_rex(rex_byte_) && rex::b(rex_byte_)) {
		decode_Reg<operand_type::REG_R12B>();
	} else {
		decode_Reg<operand_type::REG_AH>();
	}
}

//------------------------------------------------------------------------------
// Name: decode_CH
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_CH() {
	if(BITS == 64 && rex::is_rex(rex_byte_) && rex::b(rex_byte_)) {
		decode_Reg<operand_type::REG_R13B>();
	} else {
		decode_Reg<operand_type::REG_CH>();
	}
}

//------------------------------------------------------------------------------
// Name: decode_DH
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_DH() {
	if(BITS == 64 && rex::is_rex(rex_byte_) && rex::b(rex_byte_)) {
		decode_Reg<operand_type::REG_R14B>();
	} else {
		decode_Reg<operand_type::REG_DH>();
	}
}

//------------------------------------------------------------------------------
// Name: decode_BH
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_BH() {
	if(BITS == 64 && rex::is_rex(rex_byte_) && rex::b(rex_byte_)) {
		decode_Reg<operand_type::REG_R15B>();
	} else {
		decode_Reg<operand_type::REG_BH>();
	}
}

//------------------------------------------------------------------------------
// Name: decode_rAX_NOREX
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_rAX_NOREX() {
	switch(operand_size()) {;
	case 16: decode_Reg<operand_type::REG_AX>();  break;
	case 32: decode_Reg<operand_type::REG_EAX>(); break;
	case 64: decode_Reg<operand_type::REG_RAX>(); break;
	}
}

//------------------------------------------------------------------------------
// Name: decode_eAX
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_eAX() {
	// TODO: is this correct, it seems to be the same
	// because eAX is only used for ops where REX is illegal
	decode_rAX_NOREX();
}

//------------------------------------------------------------------------------
// Name: decode_rAX
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_rAX() {
	switch(operand_size()) {
	case 16:
		if(BITS == 64 && rex::is_rex(rex_byte_) && rex::b(rex_byte_)) {
			decode_Reg<operand_type::REG_R8W>();
		} else {
			decode_Reg<operand_type::REG_AX>();
		}
		break;
	case 32:
		if(BITS == 64 && rex::is_rex(rex_byte_) && rex::b(rex_byte_)) {
			decode_Reg<operand_type::REG_R8D>();
		} else {
			decode_Reg<operand_type::REG_EAX>();
		}
		break;
	case 64:
		if(BITS == 64 && rex::is_rex(rex_byte_) && rex::b(rex_byte_)) {
			decode_Reg<operand_type::REG_R8>();
		} else {
			decode_Reg<operand_type::REG_RAX>();
		}
		break;
	}
}

//------------------------------------------------------------------------------
// Name: decode_rCX
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_rCX() {
	switch(operand_size()) {
	case 16:
		if(BITS == 64 && rex::is_rex(rex_byte_) && rex::b(rex_byte_)) {
			decode_Reg<operand_type::REG_R9W>();
		} else {
			decode_Reg<operand_type::REG_CX>();
		}
		break;
	case 32:
		if(BITS == 64 && rex::is_rex(rex_byte_) && rex::b(rex_byte_)) {
			decode_Reg<operand_type::REG_R9D>();
		} else {
			decode_Reg<operand_type::REG_ECX>();
		}
		break;
	case 64:
		if(BITS == 64 && rex::is_rex(rex_byte_) && rex::b(rex_byte_)) {
			decode_Reg<operand_type::REG_R9>();
		} else {
			decode_Reg<operand_type::REG_RCX>();
		}
		break;
	}
}

//------------------------------------------------------------------------------
// Name: decode_rDX
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_rDX() {
	switch(operand_size()) {
	case 16:
		if(BITS == 64 && rex::is_rex(rex_byte_) && rex::b(rex_byte_)) {
			decode_Reg<operand_type::REG_R10W>();
		} else {
			decode_Reg<operand_type::REG_DX>();
		}
		break;
	case 32:
		if(BITS == 64 && rex::is_rex(rex_byte_) && rex::b(rex_byte_)) {
			decode_Reg<operand_type::REG_R10D>();
		} else {
			decode_Reg<operand_type::REG_EDX>();
		}
		break;
	case 64:
		if(BITS == 64 && rex::is_rex(rex_byte_) && rex::b(rex_byte_)) {
			decode_Reg<operand_type::REG_R10>();
		} else {
			decode_Reg<operand_type::REG_RDX>();
		}
		break;
	}
}

//------------------------------------------------------------------------------
// Name: decode_rBX
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_rBX() {
	switch(operand_size()) {
	case 16:
		if(BITS == 64 && rex::is_rex(rex_byte_) && rex::b(rex_byte_)) {
			decode_Reg<operand_type::REG_R11W>();
		} else {
			decode_Reg<operand_type::REG_BX>();
		}
		break;
	case 32:
		if(BITS == 64 && rex::is_rex(rex_byte_) && rex::b(rex_byte_)) {
			decode_Reg<operand_type::REG_R11D>();
		} else {
			decode_Reg<operand_type::REG_EBX>();
		}
		break;
	case 64:
		if(BITS == 64 && rex::is_rex(rex_byte_) && rex::b(rex_byte_)) {
			decode_Reg<operand_type::REG_R11>();
		} else {
			decode_Reg<operand_type::REG_RBX>();
		}
		break;
	}
}

//------------------------------------------------------------------------------
// Name: decode_rSP
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_rSP() {
	switch(operand_size()) {
	case 16:
		if(BITS == 64 && rex::is_rex(rex_byte_) && rex::b(rex_byte_)) {
			decode_Reg<operand_type::REG_R12W>();
		} else {
			decode_Reg<operand_type::REG_SP>();
		}
		break;
	case 32:
		if(BITS == 64 && rex::is_rex(rex_byte_) && rex::b(rex_byte_)) {
			decode_Reg<operand_type::REG_R12D>();
		} else {
			decode_Reg<operand_type::REG_ESP>();
		}
		break;
	case 64:
		if(BITS == 64 && rex::is_rex(rex_byte_) && rex::b(rex_byte_)) {
			decode_Reg<operand_type::REG_R12>();
		} else {
			decode_Reg<operand_type::REG_RSP>();
		}
		break;
	}
}

//------------------------------------------------------------------------------
// Name: decode_rBP
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_rBP() {
	switch(operand_size()) {
	case 16:
		if(BITS == 64 && rex::is_rex(rex_byte_) && rex::b(rex_byte_)) {
			decode_Reg<operand_type::REG_R13W>();
		} else {
			decode_Reg<operand_type::REG_BP>();
		}
		break;
	case 32:
		if(BITS == 64 && rex::is_rex(rex_byte_) && rex::b(rex_byte_)) {
			decode_Reg<operand_type::REG_R13D>();
		} else {
			decode_Reg<operand_type::REG_EBP>();
		}
		break;
	case 64:
		if(BITS == 64 && rex::is_rex(rex_byte_) && rex::b(rex_byte_)) {
			decode_Reg<operand_type::REG_R13>();
		} else {
			decode_Reg<operand_type::REG_RBP>();
		}
		break;
	}
}

//------------------------------------------------------------------------------
// Name: decode_rSI
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_rSI() {
	switch(operand_size()) {
	case 16:
		if(BITS == 64 && rex::is_rex(rex_byte_) && rex::b(rex_byte_)) {
			decode_Reg<operand_type::REG_R14W>();
		} else {
			decode_Reg<operand_type::REG_SI>();
		}
		break;
	case 32:
		if(BITS == 64 && rex::is_rex(rex_byte_) && rex::b(rex_byte_)) {
			decode_Reg<operand_type::REG_R14D>();
		} else {
			decode_Reg<operand_type::REG_ESI>();
		}
		break;
	case 64:
		if(BITS == 64 && rex::is_rex(rex_byte_) && rex::b(rex_byte_)) {
			decode_Reg<operand_type::REG_R14>();
		} else {
			decode_Reg<operand_type::REG_RSI>();
		}
		break;
	}
}

//------------------------------------------------------------------------------
// Name: decode_rDI
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_rDI() {
	switch(operand_size()) {
	case 16:
		if(BITS == 64 && rex::is_rex(rex_byte_) && rex::b(rex_byte_)) {
			decode_Reg<operand_type::REG_R15W>();
		} else {
			decode_Reg<operand_type::REG_DI>();
		}
		break;
	case 32:
		if(BITS == 64 && rex::is_rex(rex_byte_) && rex::b(rex_byte_)) {
			decode_Reg<operand_type::REG_R15D>();
		} else {
			decode_Reg<operand_type::REG_EDI>();
		}
		break;
	case 64:
		if(BITS == 64 && rex::is_rex(rex_byte_) && rex::b(rex_byte_)) {
			decode_Reg<operand_type::REG_R15>();
		} else {
			decode_Reg<operand_type::REG_RDI>();
		}
		break;
	}
}

//------------------------------------------------------------------------------
// Name: decode_rAX_rAX_NOREX
// NOTE: special case because this represents 3 possible ops!
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_rAX_rAX_NOREX() {

	// TODO: does F3 or xchg r8, rAX take precedence
	if(BITS == 64 && rex::is_rex(rex_byte_) && rex::b(rex_byte_)) {
		opcode_ = &Opcodes_nop_pause_xchg[2];
	} else if(prefix_ & PREFIX_REP) {
		mandatory_prefix_ |= PREFIX_REP;
		opcode_ = &Opcodes_nop_pause_xchg[1]; /* with 0xf3 */
	} else {
		opcode_ = &Opcodes_nop_pause_xchg[0]; /* without 0xf3 */
	}

	(this->*(opcode_->decoder))();
}

//------------------------------------------------------------------------------
// Name: operand_size
//------------------------------------------------------------------------------
template <class M>
int Instruction<M>::operand_size() const {
	int ret = 32;

	// we check if 16-bit mode is enabled
	if(prefix_ & PREFIX_OPERAND) {
		ret = 16;
	}

	// we check if 64-bit mode is enabled
	if(BITS == 64) {
		if(rex::is_rex(rex_byte_) && rex::w(rex_byte_)) {
			ret = 64;
		} else {
			const Type type = opcode_->type;
			// push/pop/jmp/call/jcc defaults to 64-bit even without prefix
			if(type == OP_PUSH || type == OP_POP || type == OP_PUSHF || type == OP_POPF || type == OP_CALL || type == OP_JMP || type == OP_JCC) {
				ret = 64;
			}
		}
	}

	return ret;
}

//------------------------------------------------------------------------------
// Name: address_size
//------------------------------------------------------------------------------
template <class M>
int Instruction<M>::address_size() const {

	if(prefix_ & PREFIX_ADDRESS) {
		if(BITS == 64) {
			return 32;
		} else {
			return 16;
		}
	} else {
		return BITS;
	}
}

}

#endif

