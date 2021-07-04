#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> buildArray(vector<int> &nums)
	{
		vector<int> res;
		int N = nums.size();
		for (int i = 0; i < N; ++i)
			res.push_back(nums[nums[i]]);
		return res;
	}
};