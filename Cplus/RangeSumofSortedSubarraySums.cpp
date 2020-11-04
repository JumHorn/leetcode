#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int rangeSum(vector<int> &nums, int n, int left, int right)
	{
		vector<int> v;
		for (int i = 0; i < n; ++i)
		{
			int sum = 0;
			for (int j = i; j < n; ++j)
			{
				sum += nums[j];
				v.push_back(sum);
			}
		}
		sort(v.begin(), v.end());
		int res = 0;
		for (int i = left - 1; i < right; ++i)
			res += v[i];
		return res;
	}
};
