#pragma once
#include<allegro5/allegro.h>
#include<vector>
class Tile
{
public:
	Tile(int topLeftX, int topLeftY, int width, int height);
	void take_hit();
	void draw();
	int get_x();
	int get_y();
	int get_width();
	int get_height();
	bool isDestroyed = false; //let the game manager know this tile is destroyed so it can remove it.
private:
	
	ALLEGRO_COLOR red = al_map_rgb(255, 0, 0);
	ALLEGRO_COLOR blue = al_map_rgb(0, 0, 255);
	ALLEGRO_COLOR orange = al_map_rgb(255, 69, 0);
	
	int topLeftX;
	int topLeftY;
	int width;
	int height;
	int hitCounter = 0;
	ALLEGRO_COLOR blockColor; //Set at random on instantiation.
	std::vector<ALLEGRO_COLOR> colorVector = { red, blue, orange };
	int elementNumber = 0;
};

