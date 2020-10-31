#include <vector>
using namespace std;

class Solution
{
public:
	int findNumbers(vector<int> &nums)
	{
		int res = 0;
		for (auto n : nums)
			res += countEvenDigits(n);
		return res;
	}

	int countEvenDigits(int n)
	{
		if (n == 0)
			return 0;
		int res = 0;
		while (n != 0)
		{
			++res;
			n /= 10;
		}
		return res % 2 == 0 ? 1 : 0;
	}
};