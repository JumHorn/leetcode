#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	int fillCups(vector<int> &amount)
	{
		int maxval = *max_element(amount.begin(), amount.end());
		int sum = accumulate(amount.begin(), amount.end(), 0);
		if (maxval >= sum - maxval)
			return maxval;
		return (sum + 1) / 2;
	}
};