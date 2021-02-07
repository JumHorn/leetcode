#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minAbsDifference(vector<int> &nums, int goal)
	{
		int N = nums.size();
		long res = abs(goal);
		vector<long> sum1, sum2;
		combinationSum(nums, 0, N / 2, 0, sum1);
		combinationSum(nums, N / 2, N, 0, sum2);
		for (auto n : sum1)
			res = min(res, abs(goal - n));
		for (auto n : sum2)
			res = min(res, abs(goal - n));

		sort(sum1.begin(), sum1.end());
		for (auto n : sum2)
		{
			long remain = goal - n;
			auto iter = lower_bound(sum1.begin(), sum1.end(), remain);
			if (iter != sum1.end())
				res = min(res, abs(remain - *iter));
			if (iter != sum1.begin())
				res = min(res, abs(remain - (*--iter)));
		}
		return res;
	}

	void combinationSum(vector<int> &nums, int index, int last, long val, vector<long> &sum)
	{
		if (index >= last)
		{
			sum.push_back(val);
			return;
		}
		combinationSum(nums, index + 1, last, val, sum);
		combinationSum(nums, index + 1, last, val + nums[index], sum);
	}
};