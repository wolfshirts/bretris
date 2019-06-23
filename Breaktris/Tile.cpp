#include "Tile.h"
#include<ctime>
#include<allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>

Tile::Tile(int topLeftX, int topLeftY, int width, int height)
{
	colors myColors;
	this->topLeftX = topLeftX;
	this->topLeftY = topLeftY;
	this->width = width;
	this->height = height;
	srand(time(NULL));
	switch (rand() % 3)
	{
	case 0:
		this->blockColor = myColors.blue;
		break;
	case 1:
		this->blockColor = myColors.orange;
		break;
	case 2:
		this->blockColor = myColors.red;
	default:
		this->blockColor = al_map_rgb(255, 255, 255);
		break;
	}
}

void Tile::take_hit()
{
	colors potential;
	if (this->hitCounter > 2) {
		this->topLeftX = -300; //We're just moving these offscreen if they're gone.
		this->topLeftY = -300; //They need to be properly deleted! This is for testing only!!!!
	}
	this->hitCounter += 1;
	switch (rand() % 3 )
	{
	case 0:
		this->blockColor = potential.red;
		break;
	case 1:
		this->blockColor = potential.blue;
		break;
	case 2:
		this->blockColor = potential.orange;
	default:
		this->blockColor = al_map_rgb(255, 255, 255);
		break;
	}
}

void Tile::draw()
{
	al_draw_filled_rectangle(topLeftX, topLeftY, topLeftX + width, topLeftY + height, this->blockColor);
}

int Tile::get_x()
{
	return this->topLeftX;
}

int Tile::get_y()
{
	return this->topLeftY;
}

int Tile::get_width()
{
	return this->width;
}

int Tile::get_height()
{
	return this->height;
}
