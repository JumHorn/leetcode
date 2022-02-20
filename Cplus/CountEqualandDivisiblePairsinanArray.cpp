#include <vector>
using namespace std;

class Solution
{
public:
	int countPairs(vector<int> &nums, int k)
	{
		int N = nums.size(), res = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = i + 1; j < N; ++j)
			{
				if (nums[i] == nums[j] && i * j % k == 0)
					++res;
			}
		}
		return res;
	}
};