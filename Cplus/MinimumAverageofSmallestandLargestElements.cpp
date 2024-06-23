#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	double minimumAverage(vector<int> &nums)
	{
		double avg = INT_MAX;
		sort(nums.begin(), nums.end());
		int N = nums.size();
		for (int i = 0; i < N / 2; ++i)
		{
			double a = (nums[i] + nums[N - i - 1]) / 2.0;
			if (a < avg)
				avg = a;
		}
		return avg;
	}
};