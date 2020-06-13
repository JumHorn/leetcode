#include <vector>
#include <cmath>
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
		int n = nums.size();
		if (n == 1 && abs(nums[0] - 24) < 0.000001)
			return true;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j)
					continue;
				vector<double> v;
				for (int k = 0; k < n; k++) // add leftover nums to v
				{
					if (k != i && k != j)
						v.push_back(nums[k]);
				}
				for (int k = 0; k < 4; k++)
				{
					double tmp;
					if (k == 0)
						tmp = nums[i] + nums[j];
					else if (k == 1)
						tmp = nums[i] - nums[j];
					else if (k == 2)
						tmp = nums[i] * nums[j];
					else if (nums[j] != 0)
						tmp = nums[i] / nums[j];

					v.push_back(tmp);
					if (backTracking(v))
						return true;
					v.pop_back();
				}
			}
		}
		return false;
	}
};