#include "Racket.h"
#include <iostream>
#include "Ball.h"


Racket::Racket(float height, float width) : shape{ {width, height} } {};



void Racket::update(float delta_time) {

	float current_position = shape.getPosition().y;

	if (current_position > (800 - this->width)) {
		shape.setPosition({ 0.0f,0.0f });
	}

	if (current_position < -200 ) {
		shape.setPosition({ 0.0f, 800.0f });
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{ 
		this->y += this->y_velocity;
		this->shape.move({ 0.0f, this->y });
		this->y -= this->y_velocity;

	};
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) 
	{ 

		this->y += this->y_velocity;
		this->shape.move({ 0.0f, -this->y });
		this->y -= this->y_velocity;

		
	};
}

bool Racket::detect_colision(Ball* ball) {
	if (this->shape.getGlobalBounds().findIntersection(ball->body.getGlobalBounds())) {
		ball->body.setFillColor(sf::Color::Blue);
		ball->set_x(25.0f);
		return true;
	}

	ball->body.setFillColor(sf::Color::White);
	return false;
	

}

void Racket::render(sf::RenderWindow &window) {

	shape.setFillColor(sf::Color::Cyan);
	window.draw(shape);

}
