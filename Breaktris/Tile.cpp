#include "Tile.h"
#include<ctime>
#include<allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>

Tile::Tile(int topLeftX, int topLeftY, int width, int height)
{
	
	this->topLeftX = topLeftX;
	this->topLeftY = topLeftY;
	this->width = width;
	this->height = height;
	srand(time(NULL));
	int element = rand() % colorVector.size();
	this->elementNumber = element;
	this->blockColor = colorVector[element];
}

void Tile::take_hit()
{
	if (this->hitCounter > 2) {
		this->isDestroyed = true;
	}
	this->hitCounter += 1;
	if(this->elementNumber + 1 == colorVector.size()){
		elementNumber = 0;
	}
	else {
		this->elementNumber += 1;
	}
	this->blockColor = colorVector[elementNumber];
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
