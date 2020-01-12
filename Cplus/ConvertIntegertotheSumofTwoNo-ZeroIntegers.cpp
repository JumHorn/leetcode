#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> getNoZeroIntegers(int n)
	{
		for (int i = 1; i <= n / 2; i++)
		{
			if (noZero(i) && noZero(n - i))
				return {i, n - i};
		}
		return {0, 0};
	}

	bool noZero(int n)
	{
		while (n != 0)
		{
			if (n % 10 == 0)
				return false;
			n /= 10;
		}
		return true;
	}
};