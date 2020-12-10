#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

typedef struct string
{
	char data[350];
} string;

string greedy(int a, int b, int c, char aa, char bb, char cc)
{
	string res;
	if (a < b)
		return greedy(b, a, c, bb, aa, cc);
	if (b < c)
		return greedy(a, c, b, aa, cc, bb);
	if (b == 0)
	{
		memset(res.data, aa, min(2, a));
		res.data[min(2, a)] = '\0';
		return res;
	}
	int use_a = min(2, a), use_b = a - use_a >= b ? 1 : 0;
	string data = greedy(a - use_a, b - use_b, c, aa, bb, cc);
	memset(res.data, aa, use_a);
	memset(&res.data[use_a], bb, use_b);
	strcpy(&res.data[use_a + use_b], data.data);
	return res;
}

char *longestDiverseString(int a, int b, int c)
{
	return greedy(a, b, c, 'a', 'b', 'c').data;
}