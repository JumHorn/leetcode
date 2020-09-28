#include <vector>
using namespace std;

class Solution
{
public:
	int totalHammingDistance(vector<int> &nums)
	{
		int res = 0, N = nums.size();
		for (int i = 0; i < 31; ++i)
		{
			int ones = 0;
			for (auto n : nums)
				ones += ((n >> i) & 1);
			res += ones * (N - ones);
		}
		return res;
	}
};