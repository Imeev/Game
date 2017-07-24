#pragma once

#include <SFML/Graphics.hpp>

class object_
{
public:
	object_();
	~object_();
	
	double x, y;
	double vx, vy;
	double size;

	sf::Image image_;

	sf::Texture texture_;

	sf::Sprite sprite_;

	void move(double target_x, double target_y);
	void draw();
	bool doPhysics();
	void control();
	void getRect(double *x1, double *x2, double *y1, double *y2);
};

