#include <stdbool.h>

bool isRobotBounded(char *instructions)
{
	int direction[4] = {0}, d = 0;
	for (int i = 0; i < 4; ++i)
	{
		char *p = instructions;
		while (*p)
		{
			if (*p == 'G')
				++direction[d];
			else if (*p == 'L')
				d = (d - 1 + 4) % 4;
			else
				d = (d + 1) % 4;
			++p;
		}
	}
	return direction[0] == direction[2] && direction[1] == direction[3];
}