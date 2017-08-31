#pragma once
#include "EventReader.h"
#include <vector>
class EventLeader
{
public:
	EventLeader();
	~EventLeader();
	std::vector<EventReader*> _Readers;
	void MassNotify(EventType _e);
};

