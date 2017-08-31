#include "Rocket.h"



Rocket::Rocket(float w, float h)
{
	//Set width and height of the rocket
	W = w;
	H = h;
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
	_X += VelX;
	_Y += VelY;
	
	_Rot += VelRot;
	if (VelRot > 0) {
		VelRot -= 0.00001;
	}

	if (VelRot < 0) {
		VelRot += 0.00001;
	}
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
