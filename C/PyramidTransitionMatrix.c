#include <stdbool.h>
#include <string.h>

bool backTracking(char* bottom, int bottomSize, int index, char* nextbottom, int nextbottomSize, int (*triangle)[7][7])
{
	if (bottomSize == 1)
		return true;
	if (nextbottomSize == bottomSize - 1)
	{
		char next[8] = {0}, newbottom[8] = {0};
		strcpy(newbottom, nextbottom);
		return backTracking(newbottom, nextbottomSize, 0, next, 0, triangle);
	}
	for (int i = 0; i < 7; ++i)
	{
		if (triangle[bottom[index] - 'A'][bottom[index + 1] - 'A'][i] == 1)
		{
			nextbottom[nextbottomSize] = 'A' + i;
			if (backTracking(bottom, bottomSize, index + 1, nextbottom, nextbottomSize + 1, triangle))
				return true;
		}
	}
	return false;
}

bool pyramidTransition(char* bottom, char** allowed, int allowedSize)
{
	int triangle[7][7][7] = {{{0}}};
	for (int i = 0; i < allowedSize; ++i)
		triangle[allowed[i][0] - 'A'][allowed[i][1] - 'A'][allowed[i][2] - 'A'] = 1;
	char nextbottom[8];
	return backTracking(bottom, strlen(bottom), 0, nextbottom, 0, triangle);
}
