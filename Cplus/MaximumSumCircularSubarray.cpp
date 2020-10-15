#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

/*
Algorithm
Kadane's (Max Variant)
Kadane's (Min Variant)
*/

class Solution
{
public:
	int maxSubarraySumCircular(vector<int> &A)
	{
		int minSum = INT_MAX, curMin = 0, maxSum = INT_MIN, curMax = 0, sum = 0;
		for (auto n : A)
		{
			sum += n;
			curMax = max(curMax, 0) + n;
			maxSum = max(maxSum, curMax);
			curMin = min(curMin, 0) + n;
			minSum = min(minSum, curMin);
		}
		return maxSum > 0 ? max(maxSum, sum - minSum) : maxSum;
	}
};