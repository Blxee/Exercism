#include "triangle.h"

bool is_triangle(const triangle_t sides)
{
	double sum = sides.a + sides.b + sides.c;
	int i = 0;
	double side;

	while (i < 3)
	{
		side = ((double *)&sides)[i++];
		if (side == 0 || side > sum - side)
			return (false);
	}
	return (true);
}

bool is_equilateral(const triangle_t sides)
{
	return (is_triangle(sides) && sides.a == sides.b && sides.b == sides.c);
}

bool is_isosceles(const triangle_t sides)
{
	return (is_triangle(sides) && (sides.a == sides.b || sides.b == sides.c || sides.c == sides.a));
}

bool is_scalene(const triangle_t sides)
{
	return (is_triangle(sides) && sides.a != sides.b && sides.b != sides.c && sides.c != sides.a);
}
