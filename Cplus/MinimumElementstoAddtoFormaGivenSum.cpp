#include <cmath>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	int minElements(vector<int> &nums, int limit, int goal)
	{
		long sum = accumulate(nums.begin(), nums.end(), 0L);
		long diff = abs(sum - goal);
		if (diff == 0)
			return 0;
		return (diff - 1) / limit + 1;
	}
};