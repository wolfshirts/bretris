#pragma once
#include<allegro5/allegro.h>
class Paddle
{
public:
	Paddle(int screenWidth, int screenHeight, int width, int height); //paddle always starts center screen.
	float get_X();
	float get_Y();
	int get_width();
	int get_height();
	void add_X(int amount);
	void add_Y(int amount);
	void draw();
	int get_paddle_speed();
	int add_paddle_speed(int speed);

private:
	float topLeftX = 0;
	float topLeftY = 0;
	int width = 0;
	int height = 0;
	int paddleSpeed = 5;
};

