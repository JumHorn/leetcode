#include <vector>
using namespace std;

class Solution
{
public:
	int smallestEqual(vector<int> &nums)
	{
		int N = nums.size();
		for (int i = 0; i < N; ++i)
		{
			if (i % 10 == nums[i])
				return i;
		}
		return -1;
	}
};