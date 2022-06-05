#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int partitionArray(vector<int> &nums, int k)
	{
		sort(nums.begin(), nums.end());
		int res = 0, N = nums.size();
		for (int i = 0, j = 0; i <= N; ++i)
		{
			if (i == N || nums[i] - nums[j] > k)
			{
				++res;
				j = i;
			}
		}
		return res;
	}
};