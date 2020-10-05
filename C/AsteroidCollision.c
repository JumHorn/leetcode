#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize)
{
	int stack[asteroidsSize], top = -1, index = 0;
	for (int i = 0; i < asteroidsSize; ++i)
	{
		if (asteroids[i] > 0)
			stack[++top] = asteroids[i];
		else
		{
			while (top != -1 && stack[top] < -asteroids[i])
				--top;
			if (top != -1 && stack[top] == -asteroids[i])
				--top;
			else if (top == -1)
				asteroids[index++] = asteroids[i];
		}
	}
	*returnSize = index + top + 1;
	int* res = (int*)malloc(sizeof(int) * (*returnSize));
	memcpy(res, asteroids, sizeof(int) * index);
	memcpy(&res[index], stack, sizeof(int) * (top + 1));
	return res;
}
