#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumDifference(vector<int> &nums, int k)
	{
		int N = nums.size();
		int res = abs(k - nums[0]);
		vector<int> v = {nums[0]};
		for (int i = 1; i < N; ++i)
		{
			vector<int> v1 = {nums[i]};
			res = min(res, abs(k - nums[i]));
			for (auto n : v)
			{
				if (v1.back() != (n & nums[i]))
				{
					v1.push_back(n & nums[i]);
					res = min(res, abs(k - (n & nums[i])));
				}
			}
			v.swap(v1);
		}
		return res;
	}
};