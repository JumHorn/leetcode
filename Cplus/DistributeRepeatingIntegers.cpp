#include <algorithm>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	bool canDistribute(vector<int> &nums, vector<int> &quantity)
	{
		unordered_map<int, int> m; //{value,count}
		for (auto n : nums)
			++m[n];
		vector<int> count;
		for (auto &n : m)
			count.push_back(n.second);

		int N = quantity.size();
		vector<int> quantity_mask_count(1 << N);
		for (int mask = 0; mask < 1 << N; ++mask)
		{
			for (int bit = 0; bit < N; ++bit)
			{
				if ((mask >> bit) & 1)
					quantity_mask_count[mask] += quantity[bit];
			}
		}

		vector<bool> dp(1 << N);
		dp[0] = true;
		for (auto n : count)
		{
			for (int i = (1 << N) - 1; i >= 0; --i)
			{
				if (!dp[i])
					continue;
				int mask = i ^ ((1 << N) - 1);
				for (int j = mask; j > 0; j = (j - 1) & mask)
				{
					if (n >= quantity_mask_count[j])
						dp[i | j] = true;
				}
			}
		}
		return dp[(1 << N) - 1];
	}
};