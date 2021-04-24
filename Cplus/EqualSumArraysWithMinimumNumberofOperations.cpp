#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minOperations(vector<int> &nums1, vector<int> &nums2)
	{
		int sum1 = 0, sum2 = 0;
		vector<int> count1(7), count2(7);
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
		int N1 = nums1.size(), N2 = nums2.size();
		if (sum1 > sum2)
		{
			swap(sum1, sum2);
			swap(N1, N2);
			count1.swap(count2);
		}
		int diff = sum2 - sum1, res = 0;
		if (diff > 6 * N1 - sum1 + sum2 - N2)
			return -1;
		for (int i = 1; i < 7 && diff > 0; ++i)
		{
			if (diff >= (6 - i) * (count1[i] + count2[7 - i]))
				res += count1[i] + count2[7 - i];
			else
				res += (diff - 1) / (6 - i) + 1;
			diff -= (6 - i) * (count1[i] + count2[7 - i]);
		}
		return res;
	}
};