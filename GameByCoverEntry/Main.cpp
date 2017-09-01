#include <SFML/Graphics.hpp>
#include "Rocket.h"
#include "EventLeader.h"
#include "InputAnnouncer.h"
#include <iostream>
int main()
{
	sf::RenderWindow window(sf::VideoMode(720, 680), "Garden Galaxy",sf::Style::Close);
	
	
	InputAnnouncer iA;
	sf::Texture texture;
	if (!
		texture.loadFromFile("Sword.png")
	) {
		std::cout << "Failed to load file";
	}


	sf::Sprite shape(texture);
	shape.setPosition(400, 400);
	shape.setScale(2, 2);
	shape.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);

	EventLeader el;

	// /* DEBUG CODE
	sf::RectangleShape line(sf::Vector2f(100, 5));
	line.setPosition(100, 420);
    // */ DEBUG CODE - draw line in movement direction


	Rocket * r = new Rocket(100, 100,shape);
	r->move(0, 0);

	el._Readers.push_back(r);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//sf::Vector2f v = sf::Vector2f((float)std::cos((shape.getRotation() - 90) *3.141592653589793 / 180.0), (float)std::sin((shape.getRotation() - 90) *3.141592653589793 / 180.0));
		iA.ListenForInput(el);

		line.setRotation((std::atan2(r->getY(),r->getY())) * 180 / 3.14159265358979323);
	
		r->update();
		shape.setPosition(r->getX(),r->getY());
	//	std::cout << shape.getRotation() << std::endl;
		shape.setRotation(r->getRot());
		
		
		
		window.clear(sf::Color(47, 18, 44));
		window.draw(shape);
		window.draw(line);
		window.display();
	}
	delete r;
	return 0;
}