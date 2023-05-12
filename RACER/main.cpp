#include <SFML/Graphics.hpp>

int main() {

	sf::RenderWindow* window;
	window = new sf::RenderWindow(sf::VideoMode(500, 500), "SFML");

	while (window->isOpen()) {
		window->clear(sf::Color::Blue);
		window->display();
	};
}