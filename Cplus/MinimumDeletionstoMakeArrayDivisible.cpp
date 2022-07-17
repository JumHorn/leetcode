#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minOperations(vector<int> &nums, vector<int> &numsDivide)
	{
		int g = numsDivide[0];
		for (auto n : numsDivide)
			g = gcd(n, g);
		sort(nums.begin(), nums.end());
		int res = 0, N = nums.size();
		for (auto n : nums)
		{
			if (g % n == 0)
				break;
			++res;
		}
		return res == N ? -1 : res;
	}

	int gcd(int x, int y)
	{
		return x == 0 ? y : gcd(y % x, x);
	}
};