#include <stdbool.h>

bool canTransform(char *start, char *end)
{
	int l = 0, r = 0;
	for (int i = 0; start[i]; ++i)
	{
		if (start[i] != 'X')
			start[i] == 'R' ? ++r : ++l;
		if (l != 0 && r > 0)
			return false;
		if (end[i] != 'X')
			end[i] == 'R' ? --r : --l;
		if (l > 0 || r < 0 || (l < 0 && r > 0))
			return false;
	}
	return l == 0 && r == 0;
}