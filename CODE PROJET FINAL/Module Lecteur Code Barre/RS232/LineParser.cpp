#include "LineParser.h"
#include <iostream>
#include "Message.h"


LineParser::LineParser()
{
}


LineParser::~LineParser()
{
}

void LineParser::parse(char * buf, int len)
{
	for (int i = 0; i < len; i++)
		buffer.push_back(buf[i]);

	bool receivedLine;

	do
	{
		receivedLine = false;

		for (int i = 0; i < buffer.size(); i++)
		{
			if (buffer[i] == '\n')
			{
				std::vector<char> message;
				for (int j = 0; j < i; j++)
				{
					message.push_back(buffer.front());
					buffer.erase(buffer.begin());
				}

				// ----------------------------------
				// Notification du message : 
				Message * msg = new Message(message);
				notifyMessage(msg);
				//-----------------------------------

				receivedLine = true;
				buffer.erase(buffer.begin());
			}
		}

	} while (receivedLine);
}
