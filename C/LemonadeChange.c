#include <stdbool.h>

bool lemonadeChange(int* bills, int billsSize)
{
	int five = 0, ten = 0;
	for (int i = 0; i < billsSize && five >= 0; ++i)
	{
		if (bills[i] == 5)
			++five;
		else if (bills[i] == 10)
		{
			--five;
			++ten;
		}
		else  //bills[i]==20
		{
			if (ten > 0)
			{
				--ten;
				--five;
			}
			else
				five -= 3;
		}
	}
	return five >= 0;
}
