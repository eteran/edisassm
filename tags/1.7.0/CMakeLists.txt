CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(edisassm)
SET(edisassm_SOURCES instruction.cpp edisassm.cpp)
SET(edisassm_HEADERS instruction.h ModRM.h operand.h REX.h SIB.h edisassm_exception.h edisassm_types.h edisassm_util.h)
ADD_EXECUTABLE(edisassm ${edisassm_SOURCES})
ENABLE_TESTING()
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-long-long -Wmissing-field-initializers -ansi -pedantic -W -Wall")


