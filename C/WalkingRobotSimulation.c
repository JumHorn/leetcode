#include <stdbool.h>
#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	int *l = *(int **)lhs, *r = *(int **)rhs;
	if (l[0] != r[0])
		return l[0] < r[0] ? -1 : 1;
	return l[1] - r[1];
}

bool binarySearch(int **arr, int arrSize, int x, int y)
{
	if (arrSize == 0)
		return 0;
	int lo = 0, hi = arrSize - 1;
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (arr[mi][0] == x)
		{
			if (arr[mi][1] < y)
				lo = mi + 1;
			else
				hi = mi;
		}
		else if (arr[mi][0] < x)
			lo = mi + 1;
		else
			hi = mi;
	}
	return arr[lo][0] == x && arr[lo][1] == y;
}

int robotSim(int *commands, int commandsSize, int **obstacles, int obstaclesSize, int *obstaclesColSize)
{
	int degree = 0, x = 0, y = 0, res = 0;
	int path[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	qsort(obstacles, obstaclesSize, sizeof(int *), cmp);
	for (int i = 0; i < commandsSize; ++i)
	{
		if (commands[i] < 0)
		{
			commands[i] == -1 ? ++degree : --degree;
			degree = (degree + 4) % 4;
		}
		else
		{
			for (int j = 1; j <= commands[i]; ++j)
			{
				if (binarySearch(obstacles, obstaclesSize, x + path[degree][0], y + path[degree][1]))
					break;
				x += path[degree][0];
				y += path[degree][1];
				res = max(res, x * x + y * y);
			}
		}
	}
	return res;
}