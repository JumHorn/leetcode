#include <cmath>
using namespace std;

/*
If an optimal product contains a factor f >= 4,
then you can replace it with factors 2 and f-2 without losing optimality,
as 2*(f-2) = 2f-4 >= f. So you never need a factor greater than or equal to 4,
meaning you only need factors 1, 2 and 3
and 1 is of course wasteful and you'd only use it for n=2 and n=3
*/

class Solution
{
public:
	int integerBreak(int n)
	{
		if (n < 3)
			return 1;
		if (n == 3)
			return 2;
		int res = 1;
		while (n > 4)
		{
			res *= 3;
			n -= 3;
		}
		res *= n;
		return res;
	}
};