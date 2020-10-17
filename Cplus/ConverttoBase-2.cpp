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
		string res;
		while (N != 0)
		{
			int remainder = N % -2;
			N /= -2;
			if (remainder < 0)
			{
				remainder += 2;
				++N;
			}
			res = to_string(remainder) + res;
		}
		return res.empty() ? "0" : res;
	}
};