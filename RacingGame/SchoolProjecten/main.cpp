#include <SFML/Graphics.hpp>

int main() {

	sf::RenderWindow* window;
	window = new sf::RenderWindow(sf::VideoMode(200, 200), "BARACK OBAMAAAAAAAAA!");

	while (window->isOpen()) {
		window->clear(sf::Color::White);
		window->display();
	};
}