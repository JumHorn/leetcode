#include <unordered_set>
#include <vector>
using namespace std;

/*
rolling Hash without collision check
*/

class Solution
{
public:
	int countDistinct(vector<int> &nums, int k, int p)
	{
		int N = nums.size(), res = 0;
		vector<int> count(N), hash(N); //each index's hash
		for (int len = 1; len <= N; ++len)
		{
			unordered_set<int> s;
			for (int i = 0; i + len <= N; ++i)
			{
				count[i] += (nums[i + len - 1] % p == 0 ? 1 : 0);
				if (count[i] <= k)
				{
					hash[i] = ((long long)hash[i] * 199 + nums[i + len - 1]) % MOD;
					if (s.insert(hash[i]).second)
						++res;
				}
			}
		}
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
	static const int PRIMER = 199;
};