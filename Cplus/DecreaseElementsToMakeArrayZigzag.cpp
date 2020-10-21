#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	int movesToMakeZigzag(vector<int> &nums)
	{
		int N = nums.size();
		vector<int> res(2);
		for (int i = 0; i < N; ++i)
		{
			int left = i > 0 ? nums[i - 1] : INT_MAX;
			int right = i + 1 < N ? nums[i + 1] : INT_MAX;
			res[i % 2] += max(0, nums[i] - min(left, right) + 1);
		}
		return min(res[0], res[1]);
	}
};