#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int waysToPartition(vector<int> &nums, int k)
	{
		int N = nums.size();
		vector<long long> prefix(N);

		prefix[0] = nums[0];
		for (int i = 1; i < N; ++i)
			prefix[i] = prefix[i - 1] + nums[i];
		int res = patition(prefix);
		res = max(res, partition(nums, prefix, k));
		return res;
	}

	int partition(vector<int> &nums, vector<long long> &sum, int k)
	{
		int N = sum.size(), res = 0;
		unordered_map<long long, int> left, right; //{diff,cout}
		for (int i = 1; i < N; ++i)
		{
			long long diff = sum[N - 1] - sum[i - 1] - sum[i - 1];
			++right[diff];
		}
		for (int i = 0; i < N; ++i)
		{
			int d = k - nums[i];
			int count = 0;
			if (right.count(d) != 0)
				count += right[d];
			if (left.count(-d) != 0)
				count += left[-d];
			res = max(res, count);

			// swap
			long long diff = sum[N - 1] - sum[i] - sum[i];
			++left[diff];
			if (--right[diff] == 0)
				right.erase(diff);
		}
		return res;
	}

	int patition(vector<long long> &nums)
	{
		int N = nums.size(), res = 0;
		for (int i = 1; i < N; ++i)
		{
			if (nums[i - 1] == nums[N - 1] - nums[i - 1])
				++res;
		}
		return res;
	}
};