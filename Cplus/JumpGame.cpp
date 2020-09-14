#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	bool canJump(vector<int> &nums)
	{
		int N = nums.size(), jump = 0;
		for (int i = 0; i <= jump && jump < N - 1; ++i)
			jump = max(jump, i + nums[i]);
		return jump >= N - 1;
	}
};