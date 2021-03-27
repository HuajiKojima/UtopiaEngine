#include "System.h"
#include <iostream>
#include <cstdarg>

namespace Utopia 
{
	UTOPIA_API void ConsolePrint(const char* _fmt, ...)
	{
		va_list _vl;
		char _buffer[256] = { 0 };
		va_start(_vl, _fmt);
		vsnprintf(_buffer, sizeof(_buffer), _fmt, _vl);
		va_end(_vl);
		std::cout << _buffer;
	}
}