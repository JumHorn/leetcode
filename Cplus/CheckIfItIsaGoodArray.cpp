#include <vector>
using namespace std;

class Solution
{
public:
	bool isGoodArray(vector<int> &nums)
	{
		int n = nums.size();
		int res = nums[0];
		for (int i = 0; i < n; i++)
		{
			res = gcd(nums[i], res);
			if (res == 1)
				return true;
		}
		return false;
	}

	int gcd(int a, int b)
	{
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}
};
