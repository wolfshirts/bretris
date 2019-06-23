#pragma once
#include"Paddle.h"
#include"Ball.h"
#include"Tile.h"
#include<allegro5/allegro.h>
class GameManager
{
public:
	GameManager(Paddle* paddle, Ball* ball, bool *gameOver, int screenWidth, int screenHeight);
	void handle_events(ALLEGRO_EVENT ev);
	void update();
	void draw();
	bool paddle_can_move_left(int distance);
	bool paddle_can_move_right(int distance);
	void detect_collision();

private:
	Paddle* paddle;
	Ball* ball;
	Tile* tile; //We have one tile for now.
	bool *gameOver;
	int screenWidth;
	int screenHeight;
	struct Rect {
		float topLeftX;
		float topLeftY;
		float bottomLeftX;
		float bottomLeftY;
	};
};

