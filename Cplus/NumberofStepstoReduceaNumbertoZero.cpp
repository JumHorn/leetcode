#include <iostream>
using namespace std;

class Solution
{
public:
	int numberOfSteps(int num)
	{
		int res = (num == 0 ? 1 : 0);
		while (num != 0)
		{
			res += 1 + (num & 1);
			num >>= 1;
		}
		return res - 1;
	}
};