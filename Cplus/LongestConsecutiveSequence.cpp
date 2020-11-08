#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int longestConsecutive(vector<int> &nums)
	{
		unordered_set<int> seen(nums.begin(), nums.end());
		int res = 0;
		for (auto n : nums)
		{
			if (seen.find(n - 1) == seen.end())
			{
				int i = n + 1;
				while (seen.find(i) != seen.end())
					++i;
				res = max(res, i - n);
			}
		}
		return res;
	}
};