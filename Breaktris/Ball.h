#pragma once
class Ball
{
public:
	Ball(int size, int startingX, int startingY);
	void ball_change_x_velocity(int velo);
	void ball_change_y_velocity(int velo);
	int get_ball_x_velo();
	int get_ball_y_velo();
	float get_ball_x();
	float get_ball_y();
	void draw();
	void update();
	int get_size();
private:
	int ballSpeed = 3;
	int ballXVelocity = 0;
	int ballYVelocity = 3;
	float ballX;
	float ballY;
	int size;
};

