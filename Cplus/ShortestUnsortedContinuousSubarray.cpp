#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int findUnsortedSubarray(vector<int> &nums)
	{
		vector<int> sorted = nums;
		sort(sorted.begin(), sorted.end());
		int i = 0, j = nums.size() - 1;
		while (i < j && sorted[i] == nums[i])
			++i;
		while (j >= i && sorted[j] == nums[j])
			--j;
		return j - i + 1;
	}
};