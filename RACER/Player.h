#pragma once
#include <SFML/Graphics.hpp>

class Player
{
private:
	float speed;
	sf::Vector2f velocity, acceleration;
	float xPos, yPos;
	float width, height;

public:
	Player(float x, float y, float s, float w, float h);
	void setSpeed(float s);
	void Input();
	void applyForce(sf::Vector2f force);
	void update(float deltatime);
	void draw(sf::RenderWindow* window);
};

