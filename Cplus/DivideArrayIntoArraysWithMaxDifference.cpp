#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> divideArray(vector<int> &nums, int k)
	{
		int N = nums.size();
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		for (int i = 0; i < N; i += 3)
		{
			if (nums[i + 2] - nums[i] > k)
				return {};
			res.push_back({nums[i], nums[i + 1], nums[i + 2]});
		}
		return res;
	}
};