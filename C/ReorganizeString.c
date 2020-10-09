#include <string.h>

char* reorganizeString(char* S)
{
	int hash[26] = {0};
	for (int i = 0; S[i]; ++i)
		++hash[S[i] - 'a'];
	int N = strlen(S);
	int mostletter = 0;
	for (int i = 0; i < 26; ++i)
	{
		if (hash[mostletter] < hash[i])
			mostletter = i;
	}
	if (hash[mostletter] > (N + 1) / 2)
		return "";
	int index = 0;
	while (--hash[mostletter] >= 0)
	{
		S[index] = 'a' + mostletter;
		index += 2;
	}
	for (int i = 0; i < 26; ++i)
	{
		while (--hash[i] >= 0)
		{
			if (index >= N)
				index = 1;
			S[index] = 'a' + i;
			index += 2;
		}
	}
	return S;
}
