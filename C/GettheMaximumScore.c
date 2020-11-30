#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxSum(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
	static const int MOD = 1e9 + 7;
	long sum1 = 0, sum2 = 0;
	for (int i = 0, j = 0; i < nums1Size || j < nums2Size;)
	{
		if (i < nums1Size && (j == nums2Size || nums1[i] < nums2[j]))
			sum1 += nums1[i++];
		else if (j < nums2Size && (i == nums1Size || nums2[j] < nums1[i]))
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