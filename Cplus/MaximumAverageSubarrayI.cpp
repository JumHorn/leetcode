#include <vector>
using namespace std;

class Solution
{
public:
	double findMaxAverage(vector<int> &nums, int k)
	{
		double sum = 0, res = 0;
		for (int i = 0; i < k; ++i)
			sum += nums[i];
		res = sum;
		for (int i = k; i < (int)nums.size(); ++i)
		{
			sum += nums[i] - nums[i - k];
			if (sum > res)
				res = sum;
		}
		return res / k;
	}
};