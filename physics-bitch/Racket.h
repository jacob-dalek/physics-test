#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"

class Racket {
public:
	Racket(float width, float height);
	void update(float delta_time);
	void render(sf::RenderWindow& window);
	bool detect_colision(Ball* ball);

private:
	sf::RectangleShape shape;
	const float y_velocity = 25.0f;
	float y = 0;
	float width = 10.0f;

};