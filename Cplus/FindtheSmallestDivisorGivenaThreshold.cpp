#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	int smallestDivisor(vector<int> &nums, int threshold)
	{
		int lo = 1, hi = *max_element(nums.begin(), nums.end());
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			int val = accumulate(nums.begin(), nums.end(), 0, [&](int a, int b) { return a + b / mi + (b % mi ? 1 : 0); });
			if (val > threshold)
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo;
	}
};