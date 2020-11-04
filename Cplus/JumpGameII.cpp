#include <algorithm>
#include <vector>
using namespace std;

/*
O(n) only need to check the range between max right jump and next max right jump
*/

class Solution
{
public:
	int jump(vector<int> &nums)
	{
		int n = nums.size();
		if (n <= 1)
			return 0;
		int res = 1, maxright = nums[0], i = 0;
		while (maxright < n - 1)
		{
			++res;
			int right = maxright;
			for (int j = i + 1; j <= maxright; ++j)
				if (right < nums[j] + j)
					right = nums[j] + j;
			i = maxright;
			maxright = right;
		}
		return res;
	}
};
