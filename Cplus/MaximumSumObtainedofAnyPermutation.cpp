#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxSumRangeQuery(vector<int> &nums, vector<vector<int>> &requests)
	{
		int N = nums.size();
		vector<int> count(N + 1);
		for (auto &r : requests)
		{
			++count[r[0]];
			--count[r[1] + 1];
		}
		sort(nums.begin(), nums.end());
		for (int i = 1; i < N; ++i)
			count[i] += count[i - 1];
		sort(count.begin(), count.begin() + N);
		long res = 0;
		for (int i = 0; i < N; ++i)
			res = (res + (long)count[i] * nums[i]) % MOD;
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};