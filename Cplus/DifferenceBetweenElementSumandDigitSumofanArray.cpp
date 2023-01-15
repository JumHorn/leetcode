#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	int differenceOfSum(vector<int> &nums)
	{
		int elesum = accumulate(nums.begin(), nums.end(), 0);
		int digsum = accumulate(nums.begin(), nums.end(), 0, [&](int a, int b)
								{ return a + digitsum(b); });
		return abs(elesum - digsum);
	}

	int digitsum(int b)
	{
		int res = 0;
		for (; b > 0; b /= 10)
			res += b % 10;
		return res;
	}
};