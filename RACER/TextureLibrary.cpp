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
	fontBold.loadFromFile("fonts/Gilroy-ExtraBold.otf");
	font.loadFromFile("fonts/Gilroy-Light.otf");
}