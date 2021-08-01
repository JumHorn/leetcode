#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	long long numberOfWeeks(vector<int> &milestones)
	{
		long long sum = accumulate(milestones.begin(), milestones.end(), 0L);
		int maxval = *max_element(milestones.begin(), milestones.end());
		if (maxval > sum - maxval)
			return (sum - maxval) * 2 + 1;
		return sum;
	}
};