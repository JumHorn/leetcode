#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> targetIndices(vector<int> &nums, int target)
	{
		sort(nums.begin(), nums.end());
		int N = nums.size();
		vector<int> res;
		for (int i = 0; i < N; ++i)
		{
			if (nums[i] == target)
				res.push_back(i);
		}
		return res;
	}
};