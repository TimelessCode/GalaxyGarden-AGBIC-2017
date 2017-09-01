#include "Rocket.h"



Rocket::Rocket(float w, float h,sf::Sprite sh)
{

	_V = sf::Vector2f(0, 0);
	//Set width and height of the rocket
	W = w;
	H = h;
	//Shapes like tha most important thang
	_Shape = sh;
	//Set all values to zero, else they will default to some awful value
	_X = 0;
	_Y = 0;
	_Rot = 0;
	VelX = 0;
	VelY = 0;
	VelRot = 0;
}


Rocket::~Rocket()
{
}


void Rocket::move(float x, float y)
{
	VelX += x;
	VelY += y;
}

void Rocket::rotate(float rot)
{
	VelRot += rot;
}

void Rocket::update()
{

	_V = sf::Vector2f((float)std::cos((getRot() - 90) *3.141592653589793 / 180.0), (float)std::sin((getRot() - 90) *3.141592653589793 / 180.0));

	//1000 is a magic number to slow down crap
	_X += VelX / 10000;
	_Y += VelY / 10000;
	
	_Rot += VelRot;
	if (_Rot >= 360) {
		_Rot = 0;
	}

	if (_Rot < 0) {
		_Rot = 360;
	}

	/*if (VelRot > 1) {
		VelRot = 1;
	}*/

	//Bring velocities closer to zero every frame ( friction )
	VelRot > 0 ? VelRot -= 0.00005 : VelRot += 0.00005;

	if (VelX > 0.0f) {
		VelX -= 0.15f;
	}
	else if (VelX < 0.0f) {
		VelX += 0.15f;
	}

	if (VelY > 0.0f) {
		VelY -= 0.15f;
	}
	else if (VelY < 0.0f) {
		VelY += 0.15f;
	}


	/*

	
	
	*/
}

float Rocket::getX()
{
	return _X;
}

float Rocket::getY()
{
	return _Y;
}

float Rocket::getRot()
{
	return _Rot;
							
}

void Rocket::notify(EventType e)
{
	switch (e)
	{
	case EventType::W_Pressed:
		move(_V.x / 1 , _V.y / 1);
		break;

	case EventType::A_Pressed:
		rotate(-0.001f);
		break;

	case EventType::D_Pressed:
		rotate(0.001f);
		break;

	

	default:
		break;
	}
}
