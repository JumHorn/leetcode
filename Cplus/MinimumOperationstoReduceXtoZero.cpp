#include <vector>
using namespace std;

class Solution
{
public:
	int minOperations(vector<int> &nums, int x)
	{
		int N = nums.size(), res = N + 1;
		for (int i = 1; i < N; ++i)
			nums[i] += nums[i - 1];
		if (nums.back() < x)
			return -1;
		if (nums.back() == x)
			return N;
		int j = N - 1;
		while (j > 0 && nums[N - 1] - nums[j - 1] <= x)
			--j;
		if (nums[N - 1] - nums[j] == x)
			res = N - j - 1;
		for (int i = 0; nums[i] <= x; ++i)
		{
			while (j < N && nums[i] + nums[N - 1] - nums[j] > x)
				++j;
			if (nums[i] + nums[N - 1] - nums[j] == x)
				res = min(res, i + N - j);
		}
		return res > N ? -1 : res;
	}
};