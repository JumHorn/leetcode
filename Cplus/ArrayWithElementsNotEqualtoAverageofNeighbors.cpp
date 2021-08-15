#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> rearrangeArray(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());
		int N = nums.size();
		vector<int> res;
		for (int i = 0; i < N / 2; ++i)
		{
			res.push_back(nums[i]);
			if (i + (N + 1) / 2 < N)
				res.push_back(nums[i + (N + 1) / 2]);
		}
		if (N % 2 == 1)
			res.push_back(nums[N / 2]);
		return res;
	}
};