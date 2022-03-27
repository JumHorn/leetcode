#include <vector>
using namespace std;

class Solution
{
public:
	int minDeletion(vector<int> &nums)
	{
		int res = 0, N = nums.size();
		int pre = -1;
		for (int i = 0; i < N; ++i)
		{
			if (pre == -1)
				pre = nums[i];
			else if (nums[i] == pre)
				++res;
			else
				pre = -1;
		}
		if (pre != -1)
			++res;
		return res;
	}
};