#include <stdlib.h>
#include <string.h>

char* multiply(char* num1, char* num2)
{
	int N1 = strlen(num1), N2 = strlen(num2);
	char mul[N1 + N2 + 1];
	mul[N1 + N2] = '\0';
	for (int i = 0; i < N1 + N2; ++i)
		mul[i] = '0';
	for (int i = N1 - 1; i >= 0; --i)
	{
		for (int j = N2 - 1; j >= 0; --j)
		{
			int sum = (num1[i] - '0') * (num2[j] - '0') + (mul[i + j + 1] - '0');
			mul[i + j + 1] = sum % 10 + '0';
			mul[i + j] += sum / 10;
		}
	}
	for (int i = 0; i < N1 + N2; ++i)
	{
		if (mul[i] != '0')
		{
			char* res = (char*)malloc(sizeof(char) * (N1 + N2 - i + 1));
			strcpy(res, &mul[i]);
			return res;
		}
	}
	return "0";
}
