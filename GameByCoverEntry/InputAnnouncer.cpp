#include "InputAnnouncer.h"



InputAnnouncer::InputAnnouncer()
{
}


InputAnnouncer::~InputAnnouncer()
{
}

void InputAnnouncer::ListenForInput(EventLeader el)
{
	//When a the W key is pressed, massnotify with the eventtype W_Pressed
	//same for all other keys
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		el.MassNotify(EventType::W_Pressed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		el.MassNotify(EventType::S_Pressed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		el.MassNotify(EventType::A_Pressed);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		el.MassNotify(EventType::D_Pressed);
	}
}
