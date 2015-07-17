/*
Copyright (C) 2006 - 2015 Evan Teran
                          evan.teran@gmail.com

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

#ifndef EDISASSM_OPS_20110816_H_
#define EDISASSM_OPS_20110816_H_

namespace edisassm {

//------------------------------------------------------------------------------
// Name: operator==
//------------------------------------------------------------------------------
template <class M>
bool operator==(const Instruction<M> &lhs, const Instruction<M> &rhs) {
	// invalid ops match nothing
	if(!lhs.valid() || !rhs.valid()) {
		return false;
	}

	// do the types match?
	if(lhs.type() != rhs.type()) {
		return false;
	}

	const unsigned int lhs_operand_count = lhs.operand_count();
	const unsigned int rhs_operand_count = rhs.operand_count();

	// do the number of operands match?
	if(lhs_operand_count != rhs_operand_count) {
		return false;
	}

	// compare the type and value of each operand
	for(unsigned int i = 0; i < lhs_operand_count; ++i) {

		const typename Instruction<M>::operand_type &lhs_operand = lhs.operands_[i];
		const typename Instruction<M>::operand_type &rhs_operand = rhs.operands_[i];

		typename Instruction<M>::operand_type::Type lhs_operand_type = lhs_operand.general_type();
		typename Instruction<M>::operand_type::Type rhs_operand_type = rhs_operand.general_type();

		if(lhs_operand_type != rhs_operand_type) {
			return false;
		}

		// TODO(eteran): support generics
		switch(lhs_operand_type) {
		case Operand<M>::TYPE_REGISTER:
			if(lhs_operand.reg() != rhs_operand.reg()) {
				return false;
			}
			break;
		case Operand<M>::TYPE_IMMEDIATE:
			if(lhs_operand.immediate() != rhs_operand.immediate()) {
				return false;
			}
			break;
		case Operand<M>::TYPE_REL:
			if(lhs_operand.relative_target() != rhs_operand.relative_target()) {
				return false;
			}
			break;
		case Operand<M>::TYPE_ABSOLUTE:
			if(lhs_operand.absolute().offset != rhs_operand.absolute().offset) {
				return false;
			}

			if(lhs_operand.absolute().seg != rhs_operand.absolute().seg) {
				return false;
			}
			break;
		default:
		case Operand<M>::TYPE_EXPRESSION:
			{
				// This is a bit more complex, because there are mathematical
				// equivalencies
				typename Operand<M>::expression_t lhs_expression = lhs_operand.expression();
				typename Operand<M>::expression_t rhs_expression = rhs_operand.expression();


				if(lhs_operand.displacement() !=  rhs_operand.displacement()) {
					return false;
				}

				// the simple case
				if( lhs_expression.base  == rhs_expression.base &&
					lhs_expression.index == rhs_expression.index &&
					lhs_expression.scale == rhs_expression.scale) {

					return true;
				}

				// Inst1 [index * 1] == Inst2 [base]
				if( lhs_expression.base  == Operand<M>::REG_NULL &&
					lhs_expression.scale == 1 &&
					lhs_expression.index == rhs_expression.base) {


					return true;
				}

				// Inst2 [index * 1] == Inst1 [base]
				if( rhs_expression.base  == Operand<M>::REG_NULL &&
					rhs_expression.scale == 1 &&
					rhs_expression.index == lhs_expression.base) {


					return true;
				}

				if(lhs_expression.index == Operand<M>::REG_NULL || rhs_expression.index == Operand<M>::REG_NULL) {
					if(lhs_expression.base  == rhs_expression.base) {
						return true;
					}
				}

				return false;
			}
			break;
		}
	}

	return true;
}

//------------------------------------------------------------------------------
// Name: operator!=
//------------------------------------------------------------------------------
template <class M>
bool operator!=(const Instruction<M> &lhs, const Instruction<M> &rhs) {
	return !(lhs == rhs);
}

}

#endif
