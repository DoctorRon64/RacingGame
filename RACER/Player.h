#pragma once
#include <SFML/Graphics.hpp>

class Player
{
private:
	sf::Vector2f velocity, acceleration, position;
	sf::Texture texture;
	sf::Sprite sprite;
	float friction;
	float speed;
	float width, height;
	static float clamp(float value, float min, float max);

public:
	Player(float x, float y, float w, float h, float s, float f);
	void setSpeed(float s);
	void Input();
	void update(float deltatime, sf::RenderWindow* window);
	void draw(sf::RenderWindow* window);
};

