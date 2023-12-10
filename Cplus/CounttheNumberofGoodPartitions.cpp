#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int numberOfGoodPartitions(vector<int> &nums)
	{
		int res = 1, N = nums.size();
		unordered_map<int, int> last;
		for (int i = 0; i < N; ++i)
			last[nums[i]] = i;
		for (int i = 0, j = 0; i < N; ++i)
		{
			if (i > j)
				res = res * 2 % MOD;
			j = max(j, last[nums[i]]);
		}
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};