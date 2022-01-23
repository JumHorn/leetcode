#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int countElements(vector<int> &nums)
	{
		int N = nums.size();
		sort(nums.begin(), nums.end());
		if (nums[0] == nums[N - 1])
			return 0;
		int res = N - 2, i = 1, j = N - 2;
		for (; i <= j && nums[i] == nums[0]; ++i)
			--res;
		for (; i <= j && nums[j] == nums[N - 1]; --j)
			--res;
		return res;
	}
};