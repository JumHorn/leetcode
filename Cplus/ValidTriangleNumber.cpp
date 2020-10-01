#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int triangleNumber(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());
		int res = 0, N = nums.size();
		for (int i = 0; i < N - 2; ++i)
		{
			int k = i + 2;
			for (int j = i + 1; j < N - 1 && nums[i] != 0; ++j)
			{
				while (k < N && nums[i] + nums[j] > nums[k])
					++k;
				res += k - j - 1;
			}
		}
		return res;
	}
};