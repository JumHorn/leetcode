#include <string.h>

int romanToInt(char *s)
{
	int map[26];
	map['I' - 'A'] = 1;
	map['V' - 'A'] = 5;
	map['X' - 'A'] = 10;
	map['L' - 'A'] = 50;
	map['C' - 'A'] = 100;
	map['D' - 'A'] = 500;
	map['M' - 'A'] = 1000;
	int N = strlen(s), res = map[s[N - 1] - 'A'];
	for (int i = N - 2; i >= 0; --i)
		res += (map[s[i] - 'A'] < map[s[i + 1] - 'A'] ? -map[s[i] - 'A'] : map[s[i] - 'A']);
	return res;
}