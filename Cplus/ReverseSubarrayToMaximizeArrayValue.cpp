#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>
using namespace std;

/*
abs(x - y) = max(x - y, y - x)
using the formula to simplify(a meres the nums array)
abs(a[R] - a[L-1]) + abs(a[L] - a[R+1]) - abs(a[L] - a[L-1]) - abs(a[R] - a[R+1])

divide into 4 case
1. a[L - 1] <= a[R] and a[L] <= a[R + 1]:
(-abs(a[L] - a[L - 1]) - a[L] - a[L - 1]) + (-abs(a[R] - a[R + 1]) + a[R] + a[R + 1])

2. a[L - 1] <= a[R] and a[L] > a[R + 1]:
(-abs(a[L] - a[L - 1]) + a[L] - a[L - 1]) + (-abs(a[R] - a[R + 1]) + a[R] - a[R + 1])

3. a[L - 1] > a[R] and a[L] <= a[R + 1]:
(-abs(a[L] - a[L - 1]) + a[L - 1] - a[L]) + (-abs(a[R] - a[R + 1]) + a[R + 1] - a[R])

4. a[L - 1] > a[R] and a[L] > a[R + 1]:
(-abs(a[L] - a[L - 1]) + a[L] + a[L - 1]) + (-abs(a[R] - a[R + 1]) - a[R] - a[R + 1])
*/

class Solution
{
public:
	int maxValueAfterReverse(vector<int> &nums)
	{
		int sum = 0, n = nums.size();
		for (int i = 1; i < n; ++i)
			sum += abs(nums[i] - nums[i - 1]);
		int res = sum;
		for (int i = 1; i < n - 1; ++i)
		{
			res = max(res, sum + abs(nums[i + 1] - nums[0]) - abs(nums[i + 1] - nums[i]));
			res = max(res, sum + abs(nums[n - 2 - i] - nums[n - 1]) - abs(nums[n - 2 - i] - nums[n - 1 - i]));
		}
		int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN, max4 = INT_MIN;
		int max5 = INT_MIN, max6 = INT_MIN, max7 = INT_MIN, max8 = INT_MIN;
		for (int i = 1; i < n - 1; ++i)
		{
			max1 = max(max1, -abs(nums[i] - nums[i - 1]) - nums[i - 1] - nums[i]);
			max2 = max(max2, -abs(nums[i] - nums[i + 1]) + nums[i] + nums[i + 1]);
			max3 = max(max3, -abs(nums[i] - nums[i - 1]) + nums[i] - nums[i - 1]);
			max4 = max(max4, -abs(nums[i] - nums[i + 1]) + nums[i] - nums[i + 1]);
			max5 = max(max5, -abs(nums[i] - nums[i - 1]) + nums[i - 1] - nums[i]);
			max6 = max(max6, -abs(nums[i] - nums[i + 1]) + nums[i + 1] - nums[i]);
			max7 = max(max7, -abs(nums[i] - nums[i - 1]) + nums[i] + nums[i - 1]);
			max8 = max(max8, -abs(nums[i] - nums[i + 1]) - nums[i] - nums[i + 1]);
		}
		res = max(res, sum + max1 + max2);
		res = max(res, sum + max3 + max4);
		res = max(res, sum + max5 + max6);
		res = max(res, sum + max7 + max8);
		return res;
	}
};