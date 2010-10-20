
#include "Instruction.h"
#include "Instruction32.h"
#include "Instruction64.h"

// explicitly instantiate these two
// to make sure everything links ok
template class Instruction<edisassm::x86>;
template class Instruction<edisassm::x86_64>;
