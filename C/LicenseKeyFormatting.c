#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char *licenseKeyFormatting(char *S, int K)
{
	int N = 0;
	for (int i = 0; S[i]; ++i)
	{
		if (S[i] != '-')
			S[N++] = toupper(S[i]);
	}
	char *res = (char *)malloc(sizeof(char) * (N + N / K - (N % K == 0 ? 1 : 0) + 1));
	int resSize = 0;
	memcpy(res, S, sizeof(char) * (N % K));
	resSize += N % K;
	for (int i = 0; i < N / K; ++i)
	{
		if (resSize != 0)
			res[resSize++] = '-';
		memcpy(&res[resSize], &S[N % K + K * i], sizeof(char) * K);
		resSize += K;
	}
	res[resSize] = '\0';
	return res;
}