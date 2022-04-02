#include <vector>
using namespace std;

class Solution
{
public:
	int triangularSum(vector<int> &nums)
	{
		int N = nums.size();
		for (int i = 0; i < N - 1; ++i)
		{
			for (int j = 0; j < N - i - 1; ++j)
			{
				nums[j] = (nums[j] + nums[j + 1]) % 10;
			}
		}
		return nums[0];
	}
};