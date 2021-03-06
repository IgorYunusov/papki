#include <utki/debug.hpp>
#include "../../src/papki/MemoryFile.hpp"

#include "tests.hpp"




namespace TestBasicMemoryFile{
void Run(){
	papki::MemoryFile f;
	ASSERT_ALWAYS(!f.isDir())
	ASSERT_ALWAYS(!f.isOpened())
	ASSERT_ALWAYS(f.size() == 0)

	{
		std::uint8_t buf[] = {1, 2, 3, 4};
		utki::Buf<std::uint8_t> b(buf, sizeof(buf));
		
		papki::File::Guard fileGuard(f, papki::File::E_Mode::CREATE);
		
		f.write(b);
	}
	
	{
		std::array<std::uint8_t, 4> b;
		
		papki::File::Guard fileGuard(f, papki::File::E_Mode::READ);
		
		f.read(utki::wrapBuf(b));
		
		ASSERT_ALWAYS(b[0] == 1)
		ASSERT_ALWAYS(b[1] == 2)
		ASSERT_ALWAYS(b[2] == 3)
		ASSERT_ALWAYS(b[3] == 4)
	}
}
}//~namespace
