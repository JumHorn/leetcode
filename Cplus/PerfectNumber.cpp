#include <iostream>
using namespace std;

class Solution
{
public:
	bool checkPerfectNumber(int num)
	{
		if (num < 6)
			return false;
		int res = 0, i = 2;
		for (; i * i < num; ++i)
		{
			if (num % i == 0)
				res += i + num / i;
		}
		if (i * i == num)
			res += i;
		return res + 1 == num;
	}
};