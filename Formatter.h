
#ifndef FORMATTER_H_
#define FORMATTER_H_

#include <string>

namespace edisassm {

template <class M>
class Instruction;

template <class M>
class Operand;

enum Syntax {
	SyntaxIntel,
//	SyntexATT
};

enum Capitalization {
	UpperCase,
	LowerCase
};

enum SmallNumberFormat {
	SmallNumAsHex,
	SmallNumAsDec
};

struct FormatOptions {
	Syntax            syntax;
	Capitalization    capitalization;
	SmallNumberFormat smallNumFormat;
};

class Formatter {
public:
	Formatter();
	Formatter(const Formatter &other);
	~Formatter();
	explicit Formatter(const FormatOptions &options);
	Formatter &operator=(const Formatter &rhs);
	
public:
	template <class M>
	std::string to_string(const Instruction<M> &inst);
	
	template <class M>
	std::string to_string(const Operand<M> &op);
	
	template <class M>
	std::string to_byte_string(const Instruction<M> &inst);
	
	template <class M>
	std::string register_name(typename Operand<M>::Register reg);
	
private:
	template <class M>
	std::string format_expression(const Operand<M> &op);

	template <class M>
	std::string format_register(const Operand<M> &op);
	
public:
	void swap(Formatter &other);
	
private:
	FormatOptions options_;
};

}

#include "Formatter.tcc"

#endif
