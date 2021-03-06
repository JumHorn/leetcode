#include <stdbool.h>

bool checkValidString(char *s)
{
	int low = 0, high = 0; //the number of left bracket in range [low,high]
	for (; *s; ++s)
	{
		if (*s == '(')
			++low;
		else if (low > 0)
			--low;

		if (*s == ')')
			--high;
		else
			++high;
		if (high < 0)
			return false;
	}
	return low == 0;
}