#include <stdbool.h>

bool isUgly(int num)
{
	if (num <= 0)
		return false;
	for (int d = 2; d <= 5; ++d)
	{
		while (num % d == 0)
			num /= d;
	}
	return num == 1;
}