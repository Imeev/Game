#include "Map.h"
#include <iostream>
#include <fstream>

using namespace std;

Map::Map()
{
	height = 0;
	width = 0;
}


Map::~Map()
{
}

int Map::create(int N1, int N2) {
	TileMap = new sf::String[N1];
	height = N1;
	width = N2;

	return 1;
}

int Map::destroy() {
	delete TileMap;
	return 1;
}

int Map::Loadfromfile(const char *filename) {

	ifstream fp(filename);

	char a;

	for (auto i = 0; i < height; i++)
		for (auto j = 0; j < width; j++) {
			fp >> a;
			TileMap[i] += a;
		}

	return 1;
}

int Map::dump() {
	for (auto i = 0; i < height; i++) {
		for (auto j = 0; j < width; j++)
			printf("%d ", TileMap[i][j]);
		printf("\n");
	}

	printf("\nHeight: %d\nWidth: %d", height, width);

	return 1;
}