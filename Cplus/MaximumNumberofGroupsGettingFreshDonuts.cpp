#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxHappyGroups(int batchSize, vector<int> &groups)
	{
		int res = 0;
		vector<int> freq(batchSize);
		for (auto n : groups)
		{
			if (n % batchSize == 0)
			{
				++res;
				continue;
			}
			if (freq[batchSize - n % batchSize] > 0)
			{
				--freq[batchSize - n % batchSize];
				++res;
			}
			else
				++freq[n % batchSize];
		}
		map<vector<int>, int> dp;
		return memdp(freq, 0, dp) + freq[0] + res;
	}

	// remainder can be deduced from freq so there is no need to cache remainder parameter
	int memdp(vector<int> &freq, int remainder, map<vector<int>, int> &dp)
	{
		auto iter = dp.find(freq);
		if (iter != dp.end())
			return iter->second;
		int res = 0, N = freq.size();
		for (int i = 1; i < N; ++i)
		{
			if (freq[i] == 0)
				continue;
			--freq[i];
			res = max(res, (remainder == 0 ? 1 : 0) + memdp(freq, (N + remainder - i) % N, dp));
			++freq[i];
		}
		return dp[freq] = res;
	}
};