#include "EventLeader.h"



EventLeader::EventLeader()
{
}


EventLeader::~EventLeader()
{
}

void EventLeader::MassNotify(EventType e)
{
	
	for (int i = 0; i < _Readers.size(); i++)
	{
		//std::cout << "Massnotified biatch";
		_Readers[i]->notify(e);
	}
}
