#include "Global_functions.h"

int move_next_position(double *x, double *y, double goal_x, double goal_y, double v) 
{
	double cosa = 0;
	double sina = 0;

	if ((*x == goal_x) && (*y == goal_y))
		return 1;

	cosa = (goal_x - *x) / sqrt((goal_x - *x) * (goal_x - *x) + (goal_y - *y) * (goal_y - *y));

	sina = (goal_y - *y) / sqrt((goal_x - *x) * (goal_x - *x) + (goal_y - *y) * (goal_y - *y));

/*	if (((*x < goal_x) && (*x > goal_x - v * cosa)) || ((*x > goal_x) && (*x < goal_x + v * cosa)))
		*x = goal_x;
	else
		*x = *x + v * cosa;

	if (((*y < goal_y) && (*y > goal_y + v * sina)) || ((*y > goal_y) && (*y < goal_y - v * sina)))
		*y = goal_y;
	else
		*y = *y + v * sina;*/

	if (sqrt((goal_x - *x) * (goal_x - *x) + (goal_y - *y) * (goal_y - *y)) < v)
	{
		*x = goal_x;
		*y = goal_y;

		return 2;
	}

	*x = *x + v * cosa;
	*y = *y + v * sina;

	return 0;
}