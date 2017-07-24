#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/String.hpp>

class Map
{
public:
	Map();
	~Map();

	int height;
	int width;

	sf::String *TileMap;

	int create(int N1, int N2);
	int destroy();

	int Loadfromfile(const char * filename);

	int dump();

};