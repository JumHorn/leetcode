#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> runningSum(vector<int> &nums)
	{
		partial_sum(nums.begin(), nums.end(), nums.begin());
		return nums;
	}
};