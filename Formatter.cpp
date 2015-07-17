
#include "Formatter.h"
#include <algorithm>

namespace edisassm {

Formatter::Formatter() {
	options_.syntax         = SyntaxIntel;
	options_.capitalization = LowerCase;
	options_.smallNumFormat = SmallNumAsDec;
}

Formatter::Formatter(const Formatter &other) : options_(other.options_) {

}

Formatter::~Formatter() {

}

Formatter::Formatter(const FormatOptions &options) : options_(options) {

}

Formatter &Formatter::operator=(const Formatter &rhs) {
	Formatter(rhs).swap(*this);
	return *this;
}

void Formatter::swap(Formatter &other) {
	using std::swap;
	swap(options_, other.options_);
}

}
