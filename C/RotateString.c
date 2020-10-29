#include <stdbool.h>
#include <string.h>

bool rotateString(char* A, char* B)
{
	int N = strlen(A);
	if (N != strlen(B))
		return false;
	if (strcmp(A, B) == 0)
		return true;
	for (int i = 0; i < N; ++i)
	{
		if (strncmp(A + i, B, N - i) == 0 && strncmp(A, B + N - i, i) == 0)
			return true;
	}
	return false;
}
