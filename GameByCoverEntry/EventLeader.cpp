#include "EventLeader.h"



EventLeader::EventLeader()
{
}


EventLeader::~EventLeader()
{
}

void EventLeader::MassNotify(EventType _e)
{
	for (int i = 0; i < _Readers.size-1; i++)
	{
		_Readers[i].notify(_e);
	}
}
