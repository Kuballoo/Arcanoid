#include "Ball.h"

using namespace sf;

Ball::Ball(float t_x, float t_y) {
	this->shape.setPosition(t_x, t_y);
	this->shape.setRadius(this->ballRadius);
	this->shape.setFillColor(Color::White);
	this->shape.setOrigin(this->ballRadius, this->ballRadius);
}

void Ball::draw(RenderTarget& target, RenderStates state) const {
	target.draw(this->shape, state);
}

void Ball::update() {
	shape.move(this->velocity);
	if (this->left() < 0) velocity.x = ballVelocity;
	else if (this->right() > 800) velocity.x = -ballVelocity;
	if (this->top() < 0) velocity.y = ballVelocity;
	else if (this->bottom() > 600) velocity.y = -ballVelocity;
}

float Ball::left() {
	return this->shape.getPosition().x - this->shape.getRadius();
}

float Ball::right() {
	return this->shape.getPosition().x + this->shape.getRadius();
}

float Ball::top() {
	return this->shape.getPosition().y - this->shape.getRadius();
}

float Ball::bottom() {
	return this->shape.getPosition().y + this->shape.getRadius();
}

void Ball::moveDown() {
	this->velocity.y = ballVelocity;
}

void Ball::moveUp() {
	this->velocity.y = -ballVelocity;
}

void Ball::moveRight() {
	this->velocity.x = ballVelocity;
}

void Ball::moveLeft() {
	this->velocity.x = -ballVelocity;
}

Vector2f Ball::getPosition() {
	return shape.getPosition();
}