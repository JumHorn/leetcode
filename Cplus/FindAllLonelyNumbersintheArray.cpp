#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> findLonely(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());
		int N = nums.size();
		vector<int> res;
		for (int i = 0; i < N; ++i)
		{
			if ((i == 0 || nums[i] != nums[i - 1] + 1) && (i + 1 >= N || nums[i] != nums[i + 1] - 1))
			{
				if ((i == 0 || nums[i] != nums[i - 1]) && (i + 1 >= N || nums[i] != nums[i + 1]))
					res.push_back(nums[i]);
			}
		}
		return res;
	}
};