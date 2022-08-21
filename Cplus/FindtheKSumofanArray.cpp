#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	long long kSum(vector<int> &nums, int k)
	{
		long long positivesum = 0, N = nums.size();
		for (auto &n : nums)
		{
			if (n > 0)
				positivesum += n;
			else
				n = -n;
		}
		sort(nums.begin(), nums.end());
		//{sum,index}
		priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
		q.push({0, 0});
		while (--k > 0)
		{
			auto [sum, i] = q.top();
			q.pop();
			if (i < N)
			{
				q.push({sum + nums[i], i + 1});
				if (i > 0)
					q.push({sum + nums[i] - nums[i - 1], i + 1});
			}
		}
		return positivesum - q.top().first;
	}
};