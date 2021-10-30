#include <string>
using namespace std;

/*
Convert a number into negative base representation
https://www.geeksforgeeks.org/convert-number-negative-base-representation/
any negative number can be a base
I should use math fomular to solve this problem
most important thing to remember is, remainder will always be positive
*/

class Solution
{
public:
	string baseNeg2(int N)
	{
		return toNegativeBase(N, -2);
	}

	string toNegativeBase(int n, int negBase)
	{
		string res;
		while (n != 0)
		{
			int remainder = n % negBase;
			n /= negBase;
			if (remainder < 0)
			{
				remainder -= negBase;
				++n;
			}
			res = to_string(remainder) + res;
		}
		return res.empty() ? "0" : res;
	}
};