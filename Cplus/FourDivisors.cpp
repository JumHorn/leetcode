#include <vector>
using namespace std;

class Solution
{
public:
	int sumFourDivisors(vector<int> &nums)
	{
		int res = 0;
		for (auto n : nums)
		{
			int divisor, count = 0;
			for (int i = 2; i * i <= n && count <= 1; ++i)
			{
				if (n % i == 0)
				{
					divisor = i;
					++count;
				}
			}
			if (count == 1 && divisor * divisor != n)
				res += 1 + n + divisor + n / divisor;
		}
		return res;
	}
};