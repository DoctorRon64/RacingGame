#pragma once
#include <SFML/Graphics.hpp>

class TextureLibrary
{
public:
	sf::Texture PlayerTexture;
	sf::Texture CarTexture;

	sf::Sprite PlayerSprite;
	sf::Sprite CarSprite;

	TextureLibrary();
	void LoadFromFile();
	void SetSprite();
};

