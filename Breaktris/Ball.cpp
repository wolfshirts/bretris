#include "Ball.h"
#include<allegro5/allegro_primitives.h>

Ball::Ball(int size, int startingX, int startingY)
{
	this->size = size;
	this->ballX = startingX;
	this->ballY = startingY;
}

void Ball::ball_change_x_velocity(int velo)
{
	ballXVelocity = velo;
}

void Ball::ball_change_y_velocity(int velo)
{
	ballYVelocity = velo;
}

int Ball::get_ball_x_velo()
{
	return ballXVelocity;
}

int Ball::get_ball_y_velo()
{
	return ballYVelocity;
}

float Ball::get_ball_x()
{
	return ballX;
}

float Ball::get_ball_y()
{
	return ballY;
}



void Ball::draw()
{
	al_draw_filled_circle(ballX, ballY, size, al_map_rgb(0, 255, 0));
}

void Ball::update()
{
	ballX += ballXVelocity;
	ballY += ballYVelocity;
}

int Ball::get_size()
{
	return size;
}
