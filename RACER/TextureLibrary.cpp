#include "TextureLibrary.h"
#include <SFML/Graphics.hpp>

TextureLibrary::TextureLibrary()
{
	
}

void TextureLibrary::LoadFromFile()
{
	PlayerTexture.loadFromFile("textures/PlayerCar.png");
	CarTexture.loadFromFile("textures/Car.png");
	BgTexture.loadFromFile("textures/Background.png");
	LoseTexture.loadFromFile("textures/Lose.png");
	WinTexture.loadFromFile("textures/Win.png");
}

void TextureLibrary::SetSprite()
{
	PlayerSprite = sf::Sprite(PlayerTexture);
	CarSprite = sf::Sprite(CarTexture);
}