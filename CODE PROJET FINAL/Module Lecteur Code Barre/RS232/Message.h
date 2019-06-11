#pragma once
#include <vector>

class Message
{
	std::vector<char> data;

public:
	Message(std::vector<char> & msg);
	~Message();

	inline std::vector<char> & getData() {
		return data;
	}
};

