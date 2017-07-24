#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <SFML/Audio.hpp>

#include "Global_variables.h"
#include "Hero.h"
#include "Map.h"

sf::RenderWindow* Window;

void rungame();

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 800), __FILE__, sf::Style::Default & sf::Style::Resize);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(25);

	Window = &window;

	rungame();

	return 1;
}

void rungame() {

	sf::Image map_image;
	map_image.loadFromFile("images/map_tiles.png");
	sf::Texture t_map;
	t_map.loadFromImage(map_image);
	sf::Sprite s_map;
	s_map.setTexture(t_map);
	Map map;
	map.create(25, 40);
	map.Loadfromfile("tiles_for_map.txt");

	Hero hero;

	sf::Clock clock;

	float time_start, time_end;

	for (;;) {

		time_start = clock.restart().asMilliseconds();

		while (Window->pollEvent(event_)) if (event_.type == sf::Event::Closed) break;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) break;

		if (!Window->isOpen()) break;

		Window->clear();

		for (auto i = 0; i < map.height; i++)
			for (auto j = 0; j < map.width; j++) {
				if (map.TileMap[i][j] == 49) s_map.setTextureRect(sf::IntRect(32, 0, 32, 32));
				if (map.TileMap[i][j] == 50) s_map.setTextureRect(sf::IntRect(0, 0, 32, 32));
				if (map.TileMap[i][j] == 51) s_map.setTextureRect(sf::IntRect(64, 0, 32, 32));

				s_map.setPosition(j * 32, i * 32);

				Window->draw(s_map);
			}

		hero.control();
		hero.draw();
		Window->draw(hero.sprite_);
		Window->display();

		time_end = clock.getElapsedTime().asMilliseconds();

		while (time_end < time_start + 0.05)
		{
			Sleep(1);
			time_end = clock.getElapsedTime().asMilliseconds();
		}
	}

	map.destroy();
}