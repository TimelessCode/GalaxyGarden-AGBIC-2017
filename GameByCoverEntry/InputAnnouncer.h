#pragma once
#include "EventLeader.h"
#include <SFML\Window\Keyboard.hpp>
/*
This is an Announcer, meaning it gets the EventLeader passed in and Massnotifies when 
the thing this specific announcer is listening for happens.
In this case key presses


*/
class InputAnnouncer
{
public:
	InputAnnouncer();
	~InputAnnouncer();
	void ListenForInput(EventLeader el);
};

