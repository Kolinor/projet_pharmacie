#pragma once

#include "Parser.h"
#include <vector>

class LineParser : public Parser
{
	std::vector<char> buffer;

public:
	LineParser();
	~LineParser();

	virtual void parse(char * buf, int len);
};

