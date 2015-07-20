CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
set(CMAKE_CXX_STANDARD 11)
PROJECT(edisassm)
INCLUDE_DIRECTORIES(include)
SET(edisassm_SOURCES Instruction.cpp edisassm.cpp Formatter.cpp)
SET(edisassm_HEADERS Instruction.h ModRM.h Operand.h REX.h SIB.h edisassm_exception.h edisassm_util.h Formatter.h)
ADD_EXECUTABLE(edisassm ${edisassm_SOURCES})
ENABLE_TESTING()
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-long-long -Wmissing-field-initializers -ansi -pedantic -W -Wall")


