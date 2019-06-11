#include "Message.h"



Message::Message(std::vector<char> & msg)
{
	for (int i = 0; i < msg.size(); i++)
		data.push_back(msg[i]);
}


Message::~Message()
{
}
