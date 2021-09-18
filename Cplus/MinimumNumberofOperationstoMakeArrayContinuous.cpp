#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int minOperations(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());
		int N = nums.size(), res = N;
		unordered_map<int, int> m; //{val,count}
		for (int i = 0, j = 0; i < N;)
		{
			int range = nums[j] + N - 1;
			for (; i < N && nums[i] <= range; ++i)
				++m[nums[i]];
			res = min(res, N - (int)m.size());
			if (j < N)
			{
				if (--m[nums[j]] == 0)
					m.erase(nums[j]);
				++j;
			}
		}
		return res;
	}
};