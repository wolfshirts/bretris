#include "GameManager.h"
#include<allegro5/allegro.h>
#include<iostream>

GameManager::GameManager(Paddle* paddle, Ball* ball, bool* gameOver, int screenWidth, int screenHeight)
{
	this->paddle = paddle;
	this->ball = ball;
	this->tile = new Tile((screenWidth/2), 40, 100, 10);
	this->gameOver = gameOver;
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
}

void GameManager::handle_events(ALLEGRO_EVENT ev)
{
	if (ev.keyboard.keycode == ALLEGRO_KEY_LEFT) {
		if(paddle_can_move_left(-paddle->get_paddle_speed()))
		 {
			paddle->add_X(-paddle->get_paddle_speed());
		}
		else {
			return;
		}
	}
	if (ev.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
		if (paddle_can_move_right(paddle->get_paddle_speed())) {
			paddle->add_X(paddle->get_paddle_speed());
		}
		else {
			return;
		}
	}
}

void GameManager::update()
{
	this->detect_collision();
	ball->update();
}

void GameManager::draw()
{
	paddle->draw();
	ball->draw();
	tile->draw();
}

bool GameManager::paddle_can_move_left(int distance)
{
	if (paddle->get_X() + distance <= 0)
		return false;
	return true;
}

bool GameManager::paddle_can_move_right(int distance)
{
	if ((paddle->get_X() + paddle->get_width()) + distance >= screenWidth)
		return false;
	return true;
}

void GameManager::detect_collision()
{
	//Check if ball has collided with tile.
	//if the ball x >= tile top left, and the balls x <= tilesX+width
	//and the ball y <= tile y + height and the ball y 
	if (ball->get_ball_x() >= tile->get_x() && ball->get_ball_x() <= tile->get_x() + tile->get_width() &&
		ball->get_ball_y() <= tile->get_y() + tile->get_height() ) {
		ball->ball_change_y_velocity(abs(ball->get_ball_y_velo()));
		tile->take_hit();
		std::cout << "tile collision" << std::endl;
	}
	//Check if ball has collided with the edge of the screen.
	if (ball->get_ball_x() + ball->get_size() >= screenWidth) {
		int newVelo = -ball->get_ball_x_velo();
		ball->ball_change_x_velocity(newVelo);
	}
	if (ball->get_ball_x() - ball->get_size() <= 0) {
		int newVelo = abs(ball->get_ball_x_velo());
		ball->ball_change_x_velocity(newVelo);
	}
	if (ball->get_ball_y() + ball->get_size() >= screenHeight) {
		int newVelo = -ball->get_ball_y_velo();
		ball->ball_change_y_velocity(newVelo);
	}
	if (ball->get_ball_y() - ball->get_size() <= 0) {
		int newVelo = abs(ball->get_ball_y_velo());
		ball->ball_change_y_velocity(newVelo);
	}

	//Check if ball has collided with paddle.
	if (ball->get_ball_y() + ball->get_size() >= paddle->get_Y() &&
		ball->get_ball_x() + ball->get_size() >= paddle->get_X() &&
		ball->get_ball_x() + ball->get_size() <= (paddle->get_X() + paddle->get_width())) {
		std::cout << "Paddle collision"<<std::endl;
		//Check where on the paddle the ball has collided, send it left or right.
		float paddleFifth = (paddle->get_width()) / 5; //We need to be able to hit ball in center.
		float ballX = ball->get_ball_x();
		
		//If the ball rect is >= 0...paddleFifth and ball <= 0...paddleFifth
		if ( ballX >= paddle->get_X() && ballX <= paddle->get_X() + paddleFifth ) {
			ball->ball_change_x_velocity(-2);
			std::cout << "left fifth" << std::endl;
		}else 
			if (ballX >= paddle->get_X() + paddleFifth && ballX <= paddle->get_X() + (paddleFifth * 2)) {
			ball->ball_change_x_velocity(-1);
			std::cout << "mid left fifth" << std::endl;
		}
		else 
			if(ballX >= paddle->get_X() + (paddleFifth*2) && ballX <= paddle->get_X() + (paddleFifth * 3)){
			//center ball >= X...(paddleFifth *2) and ball <= X...PaddleFifth *3
				ball->ball_change_x_velocity(0);
				std::cout << "mid" << std::endl;
		}else 
			if (ballX >= paddle->get_X() + (paddleFifth * 3) && ballX <= paddle->get_X() + paddleFifth * 4) {
				ball->ball_change_x_velocity(1);
				std::cout << "mid right fifth" << std::endl;
			}
		else {
				ball->ball_change_x_velocity(2);
				std::cout << "right fifth" << std::endl;
			}
				
		
		ball->ball_change_y_velocity(-ball->get_ball_y_velo());
	}

}
