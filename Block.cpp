#include "Block.h"

Block::Block(float t_x, float t_y, float t_width, float t_heigt) {
	this->shape.setPosition(t_x, t_y);
	this->shape.setSize({t_width, t_heigt});
	this->shape.setFillColor(Color::Yellow);
	this->shape.setOrigin(t_width / 2.f, t_heigt / 2.f);
}

void Block::draw(RenderTarget& target, RenderStates state) const {
	target.draw(this->shape, state);
}

float Block::left() {
	return this->shape.getPosition().x - this->shape.getSize().x / 2.0f;
}

float Block::right() {
	return this->shape.getPosition().x + this->shape.getSize().x / 2.0f;
}

float Block::top() {
	return this->shape.getPosition().y - this->shape.getSize().y / 2.0f;
}

float Block::bottom() {
	return this->shape.getPosition().y + this->shape.getSize().y / 2.0f;
}

Vector2f Block::getPosition() {
	return shape.getPosition();
}

bool Block::isDestroyed() {
	return this->destroyed;
}

void Block::destroy() {
	this->destroyed = true;
}

Vector2f Block::getSize() {
	return shape.getSize();
}

void Block::update() {

}