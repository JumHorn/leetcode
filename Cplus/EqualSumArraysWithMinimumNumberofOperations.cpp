#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minOperations(vector<int> &nums1, vector<int> &nums2)
	{
		vector<int> count1(7), count2(7);
		int res = INT_MAX, sum1 = 0, sum2 = 0, N1 = nums1.size(), N2 = nums2.size();
		if (N1 > N2 * 6 || N2 > N1 * 6)
			return -1;
		for (auto n : nums1)
		{
			sum1 += n;
			++count1[n];
		}
		for (auto n : nums2)
		{
			sum2 += n;
			++count2[n];
		}
		if (sum1 == sum2)
			return 0;
		if (sum1 > sum2)
		{
			swap(sum1, sum2);
			swap(N1, N2);
			count1.swap(count2);
		}
		for (int sum = max(sum1, N2); sum <= min(sum2, N1 * 6); ++sum)
			res = min(res, add(count1, sum - sum1) + substract(count2, sum2 - sum));
		return res;
	}

	int add(vector<int> &count, int sum)
	{
		int res = 0;
		for (int i = 1; i < (int)count.size() && sum > 0; ++i)
		{
			if (sum <= count[i] * (6 - i))
			{
				res += (sum - 1) / (6 - i) + 1;
				break;
			}
			res += count[i];
			sum -= count[i] * (6 - i);
		}
		return res;
	}

	int substract(vector<int> &count, int sum)
	{
		int res = 0;
		for (int i = (int)count.size() - 1; i >= 1 && sum > 0; --i)
		{
			if (sum <= count[i] * (i - 1))
			{
				res += (sum - 1) / (i - 1) + 1;
				break;
			}
			res += count[i];
			sum -= count[i] * (i - 1);
		}
		return res;
	}
};