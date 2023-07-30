#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int countCompleteSubarrays(vector<int> &nums)
	{
		unordered_set<int> s(nums.begin(), nums.end());
		int unique = s.size(), res = 0, N = nums.size();
		unordered_map<int, int> m; //{val,count}
		for (int i = 0, j = 0; i < N; ++i)
		{
			++m[nums[i]];
			while (m.size() == unique)
			{
				if (--m[nums[j]] == 0)
					m.erase(nums[j]);
				++j;
			}
			res += j;
		}
		return res;
	}
};