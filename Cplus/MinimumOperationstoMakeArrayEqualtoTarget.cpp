#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
	long long minimumOperations(vector<int> &nums, vector<int> &target)
	{
		long long res = 0, res1 = 0, N = nums.size(), pre = 0;
		vector<long long> diff;
		for (int i = 0; i < N; ++i)
		{
			diff.push_back(nums[i] - target[i]);
			res1 += abs(diff.back());
		}
		for (int i = 0, j = 1; j <= N; ++j)
		{
			if (j == N || diff[j - 1] * diff[j] < 0 || abs(diff[j - 1]) < abs(diff[j]))
			{
				res += abs(diff[i]) - pre;
				if (j == N || diff[j - 1] * diff[j] < 0)
					pre = 0;
				else
					pre = abs(diff[j - 1]);
				i = j;
			}
		}
		return min(res, res1);
	}
};