#pragma once
#include <iostream>


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

