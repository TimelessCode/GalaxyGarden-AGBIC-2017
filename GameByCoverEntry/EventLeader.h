#pragma once
#include <iostream>
#include "EventReader.h"
#include <vector>
class EventLeader
{
	/*
	This is a class that holds a list of readers ( AKA observers )
	It's job is to alert all the readers when an Announcer announces an event.
	Events include something as low level as W_key_pressed, up to something as high level as PowerUp Gained
	
	*/
public:
	EventLeader();
	~EventLeader();
	std::vector<EventReader*> _Readers;
	//This runs through all the readers and calls their notify function with the event that was announced
	void MassNotify(EventType e);
};

