#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

// Ball class is inhierit to abstract Drawable class, with this class we can use our object as argument RenderTarget.draw()
class Ball : public sf::Drawable {
private:
	// Ball look parameters 
	CircleShape shape;
	const float ballRadius{ 10.0f };

	// Ball movement parameters
	const float ballVelocity{ 4.0f };
	Vector2f velocity{ ballVelocity, ballVelocity };

	// Override virtual function in abstract class Drawable, with this function we can draw our Ball on targer display with some states
	void draw(RenderTarget& target, RenderStates state) const override;
public:
	Ball(float t_x, float t_y);
	~Ball() = default;

	void update();

	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();

	Vector2f getPosition();

	float left();
	float right();
	float bottom();
	float top();
};

