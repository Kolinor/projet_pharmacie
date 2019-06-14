#pragma once

#include "SerialEventListener.h"
#include <algorithm>

class Parser
{
private:
	std::vector<SerialEventListener*> listeners;

protected:
	void notifyMessage(Message * msg)
	{
		for (int i = 0; i < listeners.size(); i++)
		{
			SerialEventListener * l = listeners[i];
			l->onMessageReceived(msg);
		}
	}

public:
	Parser();
	~Parser();

	inline void addSerialEventListener(SerialEventListener * listener)
	{
		listeners.push_back(listener);
	}

	inline void removeSerialEventListener(SerialEventListener * listener)
	{
		std::vector<SerialEventListener*>::iterator it;
		it = std::find(listeners.begin(), listeners.end(), listener);
		if (it != listeners.end())
		{
			listeners.erase(it);
		}
	}

	virtual void parse(char * buf, int len) = 0;
};

