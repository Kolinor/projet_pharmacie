#pragma once
#include "SerialEventListener.h"
#include "SharedData.h"

class SynchroEventListener : public SerialEventListener
{
	SharedData<Message*> messages;
public:
	SynchroEventListener();
	~SynchroEventListener();

	virtual void onMessageReceived(Message * msg);
	inline SharedData<Message*> & getMessages() {
		return messages;
	}
};

