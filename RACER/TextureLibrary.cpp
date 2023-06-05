#include "TextureLibrary.h"

TextureLibrary::TextureLibrary()
{
	
}

void TextureLibrary::LoadFromFile()
{
	PlayerTexture.loadFromFile("textures/PlayerCar.png");
	CarTexture.loadFromFile("textures/Car.png");
}

void TextureLibrary::SetSprite()
{
	PlayerSprite = sf::Sprite(PlayerTexture);
	CarSprite = sf::Sprite(CarTexture);
}