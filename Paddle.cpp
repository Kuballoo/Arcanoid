#include "Paddle.h"

Paddle::Paddle(float t_x, float t_y) {
	this->shape.setPosition(t_x, t_y);
	this->shape.setSize({ this->paddleWidth, this->paddleHeight });
	this->shape.setFillColor(Color::Green);
	this->shape.setOrigin({ this->paddleWidth / 2, this->paddleHeight / 2 });
}

void Paddle::draw(RenderTarget& target, RenderStates state) const {
	target.draw(this->shape, state);
}

void Paddle::update() {
	this->shape.move(velocity);
	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && this->left() > 0) velocity.x = -paddleVelocity;
	else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && this->right() < 800) velocity.x = paddleVelocity;
	else velocity.x = 0;
}

float Paddle::left() {
	return this->shape.getPosition().x - this->shape.getSize().x/ 2.0f;
}

float Paddle::right() {
	return this->shape.getPosition().x + this->shape.getSize().x / 2.0f;
}

float Paddle::top() {
	return this->shape.getPosition().y - this->shape.getSize().y / 2.0f;
}

float Paddle::bottom() {
	return this->shape.getPosition().y + this->shape.getSize().y / 2.0f;
}

Vector2f Paddle::getPosition() {
	return shape.getPosition();
}