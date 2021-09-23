#include <climits>
#include <cmath>
using namespace std;

/*
abs(INT_MIN) overflow depend on compilers
*/

class Solution
{
public:
	int divide(int dividend, int divisor)
	{
		if ((dividend == INT_MIN && divisor == -1) || (divisor == 0)) //overflow
			return INT_MAX;
		int res = 0, i = 31;
		for (unsigned int d = abs(dividend), dv = abs(divisor); d >= dv;)
		{
			while ((d >> i) < dv)
				--i;
			res |= 1u << i;
			d -= dv << i;
		}
		return (dividend ^ divisor) >= 0 ? res : -res;
	}
};