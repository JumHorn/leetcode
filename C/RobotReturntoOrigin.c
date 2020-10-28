#include <stdbool.h>

bool judgeCircle(char* moves)
{
	int h = 0, v = 0;  //horizantal and vertical
	for (int i = 0; moves[i]; ++i)
	{
		if (moves[i] == 'R')
			++h;
		else if (moves[i] == 'L')
			--h;
		else if (moves[i] == 'U')
			++v;
		else
			--v;
	}
	return h == 0 && v == 0;
}
