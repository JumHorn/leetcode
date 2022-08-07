#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	long long countBadPairs(vector<int> &nums)
	{
		long long res = 0, N = nums.size();
		unordered_map<int, int> m; //{val-index,count}
		for (int i = 0; i < N; ++i)
		{
			int diff = nums[i] - i;
			res += m[diff]++;
		}
		return N * (N - 1) / 2 - res;
	}
};