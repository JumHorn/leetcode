#include <vector>
using namespace std;

class Solution
{
public:
	int countMatchingSubarrays(vector<int> &nums, vector<int> &pattern)
	{
		int N = nums.size(), M = pattern.size() + 1, res = 0;
		for (int i = 0; i <= N - M; ++i)
		{
			int j = i + 1;
			for (int k = 0; j < M + i; ++j, ++k)
			{
				if (pattern[k] == 0 && nums[j - 1] != nums[j])
					break;
				if (pattern[k] == -1 && nums[j - 1] <= nums[j])
					break;
				if (pattern[k] == 1 && nums[j - 1] >= nums[j])
					break;
			}
			if (j == M + i)
				++res;
		}
		return res;
	}
};