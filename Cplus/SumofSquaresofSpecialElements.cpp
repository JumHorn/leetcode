#include <vector>
using namespace std;

class Solution
{
public:
	int sumOfSquares(vector<int> &nums)
	{
		int N = nums.size(), res = 0;
		for (int i = 0; i < N; ++i)
		{
			if (N % (i + 1) == 0)
				res += nums[i] * nums[i];
		}
		return res;
	}
};