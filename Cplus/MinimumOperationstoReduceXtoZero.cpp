#include <vector>
using namespace std;

class Solution
{
public:
	int minOperations(vector<int> &nums, int x)
	{
		int N = nums.size(), res = N + 1, i;
		for (i = 0; i < N && x > 0; ++i)
			x -= nums[i];
		if (x == 0)
			res = min(res, i);
		for (int j = N - 1; j >= i; --j)
		{
			x -= nums[j];
			for (; x < 0 && i > 0; --i)
				x += nums[i - 1];
			if (x == 0)
				res = min(res, i + N - j);
		}
		return res > N ? -1 : res;
	}
};