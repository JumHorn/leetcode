#include <string.h>

int bestRotation(int *A, int ASize)
{
	int score[ASize];
	memset(score, 0, sizeof(score));
	for (int i = 0; i < ASize; ++i) //for every A[i] where to lost point
		--score[(i - A[i] + 1 + ASize) % ASize];
	for (int i = 1; i < ASize; ++i)
		score[i] += score[i - 1] + 1;
	int index = 0;
	for (int i = 1; i < ASize; ++i)
	{
		if (score[i] > score[index])
			index = i;
	}
	return index;
}