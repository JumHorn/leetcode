#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int reductionOperations(vector<int> &nums)
	{
		sort(nums.begin(), nums.end(), greater<int>());
		int N = nums.size(), res = 0;
		for (int i = 0; i < N - 1; ++i)
		{
			while (nums[i] == nums[i + 1])
				++i;
			if (i != N - 1)
				res += i + 1;
		}
		return res;
	}
};