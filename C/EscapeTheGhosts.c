#include <stdbool.h>
#include <stdlib.h>

bool escapeGhosts(int** ghosts, int ghostsSize, int* ghostsColSize, int* target, int targetSize)
{
	int minstep = abs(target[0]) + abs(target[1]);
	for (int i = 0; i < ghostsSize; ++i)
	{
		int ghoststep = abs(ghosts[i][0] - target[0]) + abs(ghosts[i][1] - target[1]);
		if (ghoststep <= minstep)
			return false;
	}
	return true;
}
