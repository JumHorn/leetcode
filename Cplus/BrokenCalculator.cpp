#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int brokenCalc(int X, int Y)
	{
		if (X >= Y)
			return X - Y;
		int res = 0;
		while (Y > X)
		{
			if (Y % 2 == 0)
				Y /= 2;
			else
				Y++;
			res++;
		}
		return res + X - Y;
	}
};
