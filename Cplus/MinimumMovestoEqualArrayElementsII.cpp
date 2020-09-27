#include <algorithm>
#include <vector>
using namespace std;

/*
image whatever value you choose between the max and min value
the moves will for max and min value will not change
so pair these max min values,I choose median as final value
*/

class Solution
{
public:
	int minMoves2(vector<int> &nums)
	{
		vector<int>::iterator mid = nums.begin() + nums.size() / 2;
		nth_element(nums.begin(), mid, nums.end());
		int res = 0;
		for (auto n : nums)
			res += abs(n - *mid);
		return res;
	}
};