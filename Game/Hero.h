#pragma once

#include "object_.h"
#include "SFML/Graphics.hpp"
#include "Global_variables.h"
#include "Global_functions.h"

class Hero : object_
{
public:
	Hero();
	~Hero();

	int pose = 0;

	double x = 32;
	double y = 96;

	double v = 50;

	double goal_x = 32;
	double goal_y = 96;

	sf::Sprite sprite_;
	sf::Image image_;
	sf::Texture texture_;

	void draw();

	void control();

	void getRect(double *x1, double *x2, double *y1, double *y2);

	void doPhysics();

};

