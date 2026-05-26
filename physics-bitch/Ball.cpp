#include <iostream>
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Racket.h"

Ball::Ball(float x, float y, float radius)
	: body{ radius }
{
	this->x = x;
	this->y = y;
	this->radius = radius;
	body.setPosition({ this->x, this->y });
	
	this->y_speed = 10.0f;
	this->x_speed = 4.224344340f;
}

void Ball::game_over(sf::RenderWindow &window) {
	if (this->x > 800 ) {
		window.close();
		return;
	}

}

void Ball::update(float delta_time) {
	x += x_speed;
	y += y_speed;


	if (x <= 0 || x >= 800 - body.getRadius())
		x_speed *= -1;
	if (y <= 0 || y >= 800 - body.getRadius())
		y_speed *= -1;
	

	std::cout << "("  << x << "," << y << ")" << '\n';

	body.move({ x_speed, y_speed });
}

void Ball::set_y(float y) { this->y_speed = y; };
void Ball::set_x(float x) { this->x_speed = x; };

void Ball::render(sf::RenderWindow& window) {
	window.draw(body);
}


