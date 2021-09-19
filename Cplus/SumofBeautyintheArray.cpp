#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int sumOfBeauties(vector<int> &nums)
	{
		int pre = 0, res = 0, N = nums.size();
		vector<int> prefix(N), suffix(N);
		// prefix
		prefix[0] = nums[0];
		for (int i = 1; i < N; ++i)
			prefix[i] = max(prefix[i - 1], nums[i]);

		// suffix
		suffix[N - 1] = nums[N - 1];
		for (int i = N - 2; i >= 0; --i)
			suffix[i] = min(suffix[i + 1], nums[i]);

		for (int i = 1; i < N - 1; ++i)
		{
			if (nums[i] > prefix[i - 1] && nums[i] < suffix[i + 1])
				res += 2;
			else if (nums[i] > nums[i - 1] && nums[i] < nums[i + 1])
				++res;
		}
		return res;
	}
};