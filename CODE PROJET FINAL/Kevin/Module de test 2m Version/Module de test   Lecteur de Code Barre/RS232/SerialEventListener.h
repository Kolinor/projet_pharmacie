#pragma once
#include "Message.h"
class SerialEventListener
{
public:
	SerialEventListener();
	~SerialEventListener();

	virtual void onMessageReceived(Message * msg) = 0;
};

