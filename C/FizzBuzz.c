#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **fizzBuzz(int n, int *returnSize)
{
	*returnSize = n;
	char **res = (char **)malloc(sizeof(char *) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
		res[i] = (char *)malloc(sizeof("FizzBuzz")); //sizeof("FizzBuzz") == 9 bytes
	for (int i = 0; i < n; ++i)
	{
		int j = i + 1;
		if (j % 3 == 0 && j % 5 == 0)
			strcpy(res[i], "FizzBuzz");
		else if (j % 3 == 0)
			strcpy(res[i], "Fizz");
		else if (j % 5 == 0)
			strcpy(res[i], "Buzz");
		else
			sprintf(res[i], "%d", j);
	}
	return res;
}