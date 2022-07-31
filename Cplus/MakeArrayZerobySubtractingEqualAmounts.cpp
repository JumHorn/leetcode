#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumOperations(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());
		int res = 0, diff = 0;
		for (auto n : nums)
		{
			if (n - diff > 0)
			{
				diff += n - diff;
				++res;
			}
		}
		return res;
	}
};