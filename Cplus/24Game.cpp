#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
	bool judgePoint24(vector<int> &nums)
	{
		vector<double> doublenums(nums.begin(), nums.end());
		return backTracking(doublenums);
	}

	bool backTracking(vector<double> &nums)
	{
		int N = nums.size();
		if (N == 1 && abs(nums[0] - 24) < 0.000001)
			return true;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (i == j)
					continue;
				vector<double> next_nums;
				for (int k = 0; k < N; ++k) // add not choosed nums to next_nums
				{
					if (k != i && k != j)
						next_nums.push_back(nums[k]);
				}
				for (int k = 0; k < 4; ++k)
				{
					double val;
					if (k == 0)
						val = nums[i] + nums[j];
					else if (k == 1)
						val = nums[i] - nums[j];
					else if (k == 2)
						val = nums[i] * nums[j];
					else if (nums[j] != 0)
						val = nums[i] / nums[j];

					next_nums.push_back(val);
					if (backTracking(next_nums))
						return true;
					next_nums.pop_back();
				}
			}
		}
		return false;
	}
};