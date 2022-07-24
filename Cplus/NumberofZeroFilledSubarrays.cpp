#include <vector>
using namespace std;

class Solution
{
public:
	long long zeroFilledSubarray(vector<int> &nums)
	{
		long long res = 0, N = nums.size();
		for (int i = 0, j = 0; i < N;)
		{
			while (i < N && nums[i] != 0)
				++i;
			j = i;
			while (i < N && nums[i] == 0)
				++i;
			long long k = i - j;
			res += k * (k + 1) / 2;
		}
		return res;
	}
};