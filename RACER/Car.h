#pragma once
#include <SFML\Graphics.hpp>
#include "RigidBody.h"

class Car
{
private:
	sf::Vector2f position;
	sf::Sprite sprite;
	float speed;
	float friction;
	float width, height;
	RigidBody rb;

public:
	Car(float x, float y, float w, float h, float s, float f, float Carmass, sf::Sprite SpriteRef);
	void update(sf::RenderWindow* window, float deltaTime);
	bool CheckIfDeath(sf::RenderWindow* window);
	void draw(sf::RenderWindow* window);
	float getCarWidth();
	float getCarHeight();
};