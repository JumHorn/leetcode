#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxSum(vector<int> &nums1, vector<int> &nums2)
	{
		long sum1 = 0, sum2 = 0;
		int N1 = nums1.size(), N2 = nums2.size();
		for (int i = 0, j = 0; i < N1 || j < N2;)
		{
			if (i < N1 && (j == N2 || nums1[i] < nums2[j]))
				sum1 += nums1[i++];
			else if (j < N2 && (i == N1 || nums2[j] < nums1[i]))
				sum2 += nums2[j++];
			else
			{
				sum1 = sum2 = max(sum1, sum2) + nums1[i];
				++i;
				++j;
			}
		}
		return max(sum1, sum2) % MOD;
	}

private:
	static const int MOD = 1e9 + 7;
};