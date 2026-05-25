#pragma once
#include <SFML/Graphics.hpp>

class Ball {
public:
	Ball(float x, float y, float radius);

	void update(float delta_time);
	void render(sf::RenderWindow &window, sf::Color &color);

private:
	sf::CircleShape body;
	float x;
	float y;
	float radius;

	float x_speed;
	float y_speed;

};