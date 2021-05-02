#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int getMinDistance(vector<int> &nums, int target, int start)
	{
		int N = nums.size(), res = INT_MAX;
		for (int i = 0; i < N; ++i)
		{
			if (nums[i] == target)
				res = min(res, abs(i - start));
		}
		return res;
	}
};