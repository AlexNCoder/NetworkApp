#include "parser.h"
#include <iostream>
#include <algorithm>

bool Parser::isAllASCII(std::string s)
{
	return std::all_of(
		s.begin(),
		s.end(),
		[](const unsigned char& c)
		{
			return c <= 127;
		});
}
