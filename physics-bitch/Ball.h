#pragma once
#include <SFML/Graphics.hpp>

class Ball {
public:
	Ball(float x, float y, float radius);

	void update(float delta_time);
	void set_y(float y);
	void set_x(float x);
	void render(sf::RenderWindow& window);
	void game_over(sf::RenderWindow& window);
	sf::CircleShape body;

private:
	float x;
	float y;
	float radius;
	float x_speed;
	float y_speed;

};