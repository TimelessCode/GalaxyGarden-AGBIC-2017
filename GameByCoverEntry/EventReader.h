#pragma once
#include <iostream>

/*
Contains info about the eventtype and has a notify function.
Reason the eventype is in here instead of in the eventleader is incase I want to make derive a new type of eventreader
which only listens to certain events

*/
enum EventType
{
	W_Pressed,
	S_Pressed,
	A_Pressed,
	D_Pressed
};
class EventReader
{
public:
	EventReader();
	~EventReader();
	virtual void notify(EventType e);
};

