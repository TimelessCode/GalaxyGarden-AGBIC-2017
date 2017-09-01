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

	sf::Texture animtest;
	if (!
		animtest.loadFromFile("samurai-color-anim.png")
		) {
		std::cout << "Failed to load file";
	}


	sf::Sprite test(animtest);
	test.setTextureRect(sf::IntRect(0, 0, 64, 64));
	test.setPosition(-10, 200);
	test.setScale(2, 2);


	sf::Sprite shape(texture);
	
	shape.setScale(2, 2);

	shape.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
	shape.setPosition(400, 400);

	int z = 0;
	EventLeader el;

	// /* DEBUG CODE
	sf::RectangleShape line(sf::Vector2f(100, 5));
	line.setPosition(100, 420);
    // */ DEBUG CODE - draw line in movement direction


	Rocket * r = new Rocket(100, 100,shape);
	r->move(0, 0);

	
	
	el._Readers.push_back(r);

	sf::View view(sf::FloatRect(0, 0, 720, 680));
	
	


	sf::Clock clock;
	shape.setPosition(400, 400);
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
		
		test.setTextureRect(sf::IntRect(z, 0, 64, 64));
		//std::cout << clock.getElapsedTime().asMilliseconds() << std::endl;
		if (clock.getElapsedTime().asMilliseconds() >= 250) {
			if (!((z + 64) >= 256)) {
				z += 64;
			}
			else {
				z = 0;

			}
			clock.restart();
		}
		test.setPosition(test.getPosition().x + 0.1, test.getPosition().y );
		line.setRotation((std::atan2(r->getY(),r->getY())) * 180 / 3.14159265358979323);
		
		//Get the x coordinate of the sword, if it is past a certain border and still moving, scroll the camer
		//NOTE - Due to coding neatness limits, nothing can be 100 percent still on the y axis in the game world
		if (r->getX() > window.mapPixelToCoords(sf::Vector2i(680,0)).x && r->VelX != 0.0f) {

			view.move(0.5f, 0);
			std::cout << r->VelX << std::endl;
					   }


		r->update();
		shape.setPosition(r->getX(),r->getY());
	//	std::cout << shape.getRotation() << std::endl;
		shape.setRotation(r->getRot());
		
		
		window.setView(view);
		window.clear(sf::Color(47, 18, 44));
		window.draw(shape);
		window.draw(test);
		window.display();
	}
	delete r;
	return 0;
}