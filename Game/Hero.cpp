#include "Hero.h"


Hero::Hero()
{
}

Hero::~Hero()
{
}

void Hero::draw()
{

	image_.loadFromFile("images/hero/hero.png");

	image_.createMaskFromColor(sf::Color(255, 255, 255), 0);

	texture_.loadFromImage(image_);

	sprite_.setTexture(texture_);

	switch (pose)
	{
	case 0:
		sprite_.setTextureRect(sf::IntRect(0, 0, 64, 96));
		break;
	case 1:
		sprite_.setTextureRect(sf::IntRect(64, 0, 64, 96));
		break;
	case 2:
		sprite_.setTextureRect(sf::IntRect(128, 0, 64, 96));
		break;
	case 3:
		sprite_.setTextureRect(sf::IntRect(192, 0, 64, 96));
		break;
	case 4:
		sprite_.setTextureRect(sf::IntRect(0, 96, 64, 96));
		break;
	case 5:
		sprite_.setTextureRect(sf::IntRect(64, 96, 64, 96));
		break;
	case 6:
		sprite_.setTextureRect(sf::IntRect(128, 96, 64, 96));
		break;
	}

	sprite_.setPosition(sf::Vector2f(x - 32, y - 96));
}

void Hero::control()
{
	if (event_.type == sf::Event::MouseButtonPressed)
	{
		if (event_.mouseButton.button == sf::Mouse::Left)
		{
			goal_x = event_.mouseButton.x;
			goal_y = event_.mouseButton.y;
		}
	}
	else if (event_.type == sf::Event::KeyPressed)
	{
		if (event_.key.code == sf::Keyboard::Right)
		{
			printf("!!!!!!!");
			goal_x += 10;
		}
		if (event_.key.code == sf::Keyboard::Left)
			goal_x -= 10;
		if (event_.key.code == sf::Keyboard::Up)
			goal_y += 10;
		if (event_.key.code == sf::Keyboard::Down)
			goal_y -= 10;
	}

	if (move_next_position(&x, &y, goal_x, goal_y, v) == 1)
		pose = 0;
	else
	{
		switch (pose)
		{
		case 0:
			if (goal_x >= x)
				pose = 1;
			else
				pose = 4;
			break;
		case 1:
		case 2:
		case 3:
			if (goal_x >= x)
				pose = 1 + pose % 3;
			else
				pose = 4;
			break;
		case 4:
		case 5:
		case 6:
			if (goal_x < x)
				pose = 4 + pose % 3;
			else
				pose = 1;
			break;
		}
	}

}

void Hero::getRect(double *x1, double *x2, double *y1, double *y2)
{
	*x1 = x - 32;
	*x2 = x + 32;
	*y1 = y;
	*y2 = y - 96;
}

void Hero::doPhysics()
{

}