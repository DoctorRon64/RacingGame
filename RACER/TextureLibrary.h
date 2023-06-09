#pragma once
#include <SFML/Graphics.hpp>

class TextureLibrary
{
public:
	sf::Texture PlayerTexture;
	sf::Texture CarTexture;
	sf::Texture BgTexture;
	sf::Texture LoseTexture;
	sf::Texture WinTexture;

	TextureLibrary();
	void LoadFromFile();
};

