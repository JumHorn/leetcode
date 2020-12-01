#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
	int threeSumClosest(vector<int> &nums, int target)
	{
		sort(nums.begin(), nums.end());
		int res = 0, diff = INT_MAX, N = nums.size();
		for (int i = 0; i < N - 2; ++i)
		{
			//twoSum
			int j = i + 1, k = N - 1;
			while (j < k)
			{
				int sum = nums[i] + nums[j] + nums[k];
				int val = abs(sum - target);
				if (val < diff)
				{
					diff = val;
					res = sum;
				}
				if (sum <= target)
					++j;
				else
					--k;
			}
		}
		return res;
	}
};