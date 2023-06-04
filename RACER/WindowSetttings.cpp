#include "WindowSetttings.h"

WindowSetttings::WindowSetttings(sf::RenderWindow* window)
{
	sf::Image windowIcon;
	windowIcon.loadFromFile("textures/icon.png");
	window->setIcon(windowIcon.getSize().x, windowIcon.getSize().y, windowIcon.getPixelsPtr());
	window->setTitle("SUPER ULTRA OMEGA ULTIMATE MEGA RACERRRRRRR!!!!!!!");
}