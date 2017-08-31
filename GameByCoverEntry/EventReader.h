#pragma once


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
	void notify();
};

