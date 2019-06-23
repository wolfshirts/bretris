#include "Paddle.h"
#include<allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include<iostream>

Paddle::Paddle(int screenWidth, int screenHeight, int width, int height)
{
	topLeftX = (screenWidth / 2) - (width / 2);
	topLeftY = screenHeight - 20;
	this->width = width;
	this->height = height;
}

float Paddle::get_X()
{
	return topLeftX;
}

float Paddle::get_Y()
{
	return topLeftY;
}

int Paddle::get_width()
{
	return width;
}

int Paddle::get_height()
{
	return height;
}

void Paddle::add_X(int amount)
{
	topLeftX += amount;
}

void Paddle::add_Y(int amount)
{
	topLeftY += amount;
}

void Paddle::draw()
{
	al_draw_filled_rectangle(topLeftX, topLeftY, topLeftX + width, topLeftY + height,
		al_map_rgb(255, 0, 100));
}

int Paddle::get_paddle_speed()
{
	return paddleSpeed;
}

int Paddle::add_paddle_speed(int speed)
{
	return paddleSpeed += speed;
}
