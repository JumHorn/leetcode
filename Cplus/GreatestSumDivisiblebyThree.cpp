#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxSumDivThree(vector<int> &nums)
	{
		int res = 0, one = 0, two = 0;
		vector<int> v1(3, INT_MAX), v2(3, INT_MAX);
		for (int i = 0; i < (int)nums.size(); i++)
		{
			res += nums[i];
			int r = nums[i] % 3;
			if (r == 1)
			{
				pop_heap(v1.begin(), v1.end());
				if (*v1.rbegin() > nums[i])
					*v1.rbegin() = nums[i];
				push_heap(v1.begin(), v1.end());
				one++;
			}
			else if (r == 2)
			{
				pop_heap(v2.begin(), v2.end());
				if (*v2.rbegin() > nums[i])
					*v2.rbegin() = nums[i];
				push_heap(v2.begin(), v2.end());
				two++;
			}
		}
		int tmp = abs(one - two);
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		if (tmp % 3 == 1)
		{
			if (one < two)
			{
				if (two >= 3 && one >= 2)
					res -= min(v2[0], v1[0] + v1[1]);
				else
					res -= v2[0];
			}
			else
			{
				if (two >= 2 && one >= 3)
					res -= min(v1[0], v2[0] + v2[1]);
				else
					res -= v1[0];
			}
		}
		else if (tmp % 3 == 2)
		{
			if (one < two)
				res -= min(v1[0], v2[0] + v2[1]);
			else
				res -= min(v2[0], v1[0] + v1[1]);
		}
		return res;
	}
};