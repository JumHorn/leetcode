#include <stdio.h>
#include <stdlib.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

char* getHint(char* secret, char* guess)
{
	int hash_secret[10] = {0}, hash_guess[10] = {0};
	int bulls = 0, cows = 0;
	for (int i = 0; secret[i]; ++i)
	{
		if (secret[i] == guess[i])
			++bulls;
		else
		{
			++hash_secret[secret[i] - '0'];
			++hash_guess[guess[i] - '0'];
		}
	}
	for (int i = 0; i < 10; ++i)
		cows += min(hash_guess[i], hash_secret[i]);
	char* res = (char*)malloc(sizeof(char) * 10);
	sprintf(res, "%dA%dB", bulls, cows);
	return res;
}
