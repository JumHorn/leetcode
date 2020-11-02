#include <stdbool.h>

bool canFormArray(int* arr, int arrSize, int** pieces, int piecesSize, int* piecesColSize)
{
	int hash[101] = {0};  //{value of first pieces,index}
	for (int i = 0; i < piecesSize; ++i)
		hash[pieces[i][0]] = i + 1;
	for (int i = 0; i < arrSize;)
	{
		if (hash[arr[i]] == 0)
			return false;
		int index = hash[arr[i]] - 1;
		++i;
		for (int j = 1; j < piecesColSize[index]; ++j)
		{
			if (pieces[index][j] != arr[i])
				return false;
			++i;
		}
	}
	return true;
}
