#pragma once

#include <utki/debug.hpp>

#include "tests.hpp"


inline void TestTingMemoryFile(){
	TestBasicMemoryFile::Run();

	TRACE_ALWAYS(<< "[PASSED]" << std::endl)
}
