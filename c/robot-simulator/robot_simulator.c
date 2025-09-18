#include "robot_simulator.h"

robot_status_t robot_create(robot_direction_t direction, int x, int y)
{
	robot_status_t result;
	robot_position_t position;

	position = (robot_position_t) { x, y };
	result = (robot_status_t) { direction, position };
	return (result);
}

void robot_move(robot_status_t *robot, const char *commands)
{
	static const robot_position_t steps[] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 }, };
	int i;

	i = 0;
	while (commands[i])
	{
		switch (commands[i])
		{
			case 'L':
				robot->direction = (robot->direction - 1) % DIRECTION_MAX;
				break;
			case 'R':
				robot->direction = (robot->direction + 1) % DIRECTION_MAX;
				break;
			case 'A':
				robot->position.x += steps[robot->direction].x;
				robot->position.y += steps[robot->direction].y;
				break;
		}
		i++;
	}
}
