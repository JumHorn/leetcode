#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	int missingNumber(vector<int> &nums)
	{
		int N = nums.size();
		int res = accumulate(nums.begin(), nums.end(), 0, [](int a, int b) { return a ^ b; });
		for (int i = 0; i <= N; ++i)
			res ^= i;
		return res;
	}
};