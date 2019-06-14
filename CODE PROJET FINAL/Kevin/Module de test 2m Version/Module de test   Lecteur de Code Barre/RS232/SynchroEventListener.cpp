#include "SynchroEventListener.h"



SynchroEventListener::SynchroEventListener()
{
}


SynchroEventListener::~SynchroEventListener()
{
}

void SynchroEventListener::onMessageReceived(Message * msg)
{
	messages.Add(msg);
}
