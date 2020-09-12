#include <climits>
#include <cmath>
using namespace std;

class Solution
{
public:
	int divide(int dividend, int divisor)
	{
		if ((dividend == INT_MIN && divisor == -1) || (divisor == 0))  //overflow
			return INT_MAX;
		long res = 0, d = labs(dividend), dv = labs(divisor);
		while (d >= dv)
		{
			int i = 1;
			while (d - (dv << i) >= 0)
				++i;
			res += 1 << (i - 1);
			d -= dv << (i - 1);
		}
		return (dividend > 0) == (divisor > 0) ? res : -res;
	}
};
