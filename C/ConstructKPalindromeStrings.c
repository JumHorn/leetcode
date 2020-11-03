#include <stdbool.h>
#include <string.h>

bool canConstruct(char* s, int k)
{
	int count[26] = {0}, single = 0, N = strlen(s);
	if (k > N)
		return false;
	for (int i = 0; i < N; ++i)
		++count[s[i] - 'a'];
	for (int i = 0; i < 26; ++i)
		single += count[i] % 2;
	return k >= single;
}
