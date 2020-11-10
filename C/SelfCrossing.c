#include <stdbool.h>

// math period problem
// same problem
// Count The Repetitions

/*               i-2
    case 1 : i-1┌─┐
                └─┼─>i
                 i-3

                    i-2
    case 2 : i-1 ┌────┐
                 └─══>┘i-3
                 i  i-4      (i overlapped i-4)

    case 3 :    i-4
               ┌──┐
               │i<┼─┐
            i-3│ i-5│i-1
               └────┘
                i-2

*/

bool isSelfCrossing(int *x, int xSize)
{
	if (xSize < 4)
		return false;
	for (int i = 3; i < xSize; ++i)
	{
		if (x[i] >= x[i - 2] && x[i - 1] <= x[i - 3])
			return true;
		if (i > 3 && x[i - 1] == x[i - 3] && x[i] + x[i - 4] >= x[i - 2])
			return true;
		if (i > 4 && x[i - 2] >= x[i - 4] && x[i - 1] <= x[i - 3] &&
			x[i - 1] >= x[i - 3] - x[i - 5] && x[i] >= x[i - 2] - x[i - 4])
			return true;
	}
	return false;
}