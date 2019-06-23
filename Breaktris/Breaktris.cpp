// Breaktris.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include"Paddle.h"
#include"Ball.h"
#include"GameManager.h"

int main()
{
	//No magic numbers.
	int WIDTH = 600;
	int HEIGHT = 800;
	int FPS = 60;
	
	//Init allegro
	al_init();
	al_init_primitives_addon();
	al_install_keyboard();


	ALLEGRO_DISPLAY* theDisplay = al_create_display(WIDTH, HEIGHT);
	ALLEGRO_TIMER* timer = al_create_timer(1.0/FPS);
	ALLEGRO_EVENT_QUEUE* eventQueue = al_create_event_queue();
	al_register_event_source(eventQueue, al_get_display_event_source(theDisplay));
	al_register_event_source(eventQueue, al_get_timer_event_source(timer));
	al_start_timer(timer);
	al_register_event_source(eventQueue, al_get_keyboard_event_source());

	bool gameOver = false;
	bool* passableGameOver = &gameOver;

	Paddle* paddle = new Paddle(WIDTH, HEIGHT, 70, 10);
	Ball* ball = new Ball(7, WIDTH / 2, HEIGHT / 2);
	
	GameManager manager = GameManager(paddle, ball, passableGameOver, WIDTH, HEIGHT);
	while (!gameOver) {
		ALLEGRO_EVENT e;
		al_wait_for_event(eventQueue, &e);
		if (e.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			gameOver = true;
		}
		else if(e.type == ALLEGRO_EVENT_TIMER){
			al_clear_to_color(al_map_rgb(0, 0, 0));
			manager.update();
			manager.draw();
			al_flip_display();
		}
		else
		{
			manager.handle_events(e);
		}
	}


	//Clear resources.
	delete paddle;
	al_destroy_timer(timer);
	al_destroy_display(theDisplay);
	al_destroy_event_queue(eventQueue);

	return 0;
}
