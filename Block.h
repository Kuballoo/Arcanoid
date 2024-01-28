#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Block : public Drawable {
private:
	RectangleShape shape;
	bool destroyed{ false };

	void draw(RenderTarget& target, RenderStates state) const override;
public:
	Block(float t_x, float t_y, float t_width, float t_height);
	~Block() = default;
	
	void update();
	Vector2f getPosition();
	float left();
	float right();
	float top();
	float bottom();

	bool isDestroyed();
	void destroy();
	Vector2f getSize();
};

