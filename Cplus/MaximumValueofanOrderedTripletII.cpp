#include <vector>
using namespace std;

class Solution
{
public:
	long long maximumTripletValue(vector<int> &nums)
	{
		long long res = 0, N = nums.size();
		vector<int> suffix(N + 1);
		for (int i = N - 1; i >= 0; --i)
			suffix[i] = max(suffix[i + 1], nums[i]);
		int maxval = nums[0];
		for (int j = 1; j < N - 1; ++j)
		{
			maxval = max(maxval, nums[j - 1]);
			res = max(res, (long long)(maxval - nums[j]) * suffix[j + 1]);
		}
		return res;
	}
};