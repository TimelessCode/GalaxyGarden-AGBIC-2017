#pragma once
class Rocket
{
	/*
	This is the logic and physics part of a rocket class.
	Something that can move , rotate , and has a position
	Uses the velocity model for movement and rotation
	
	*/

	//here is a struct which can contain all data needed to do stuff.
	struct RocketData
	{

	};
public:
	//Velocity is public to aid the physics handler.
	float VelX;
	float VelY;
	float VelRot;
	
	float W;
	float H;
	Rocket(float w, float h);
	~Rocket();
	//Adds the x and y to our x and y
	void move(float x , float y);
	//Adds the rotation to our rotation
	void rotate(float rot);
    //Update
	void update();
	//Getters - express visual studio doesn't auto do it sadly
	float getX();
	float getY();
	float getRot();
private:
	float _X;
	float _Y;
	float _Rot;

	
	
	
};

