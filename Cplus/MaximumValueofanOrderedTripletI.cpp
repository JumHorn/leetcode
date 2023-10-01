#include <vector>
using namespace std;

class Solution
{
public:
	long long maximumTripletValue(vector<int> &nums)
	{
		long long res = 0, N = nums.size();
		for (int i = 0; i < N - 2; ++i)
		{
			for (int j = i + 1; j < N - 1; ++j)
			{
				for (int k = j + 1; k < N; ++k)
					res = max(res, (long long)(nums[i] - nums[j]) * nums[k]);
			}
		}
		return res;
	}
};