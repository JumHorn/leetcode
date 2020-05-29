#include <vector>
using namespace std;

class Solution
{
public:
	int maxDotProduct(vector<int>& nums1, vector<int>& nums2)
	{
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		int n1 = nums1.size(), n2 = nums2.size(), n = min(n1, n2);
		int i = 0, j = 0, res = 0;
		while (n > 0)
		{
			int tmp = nums1[i] * nums2[j];
			if (tmp < 0)
				break;
			res += tmp;
			++i;
			++j;
			--n;
		}
		i = n1 - 1;
		j = n2 - 1;
		while (n > 0)
		{
			int tmp = nums1[i] * nums2[j];
			if (tmp < 0)
				break;
			res += tmp;
			--i;
			--j;
			--n;
		}
		if (min(n1, n2) != n)
			return res;
		return max(nums1[0] * nums2[0], nums1[n1 - 1] * nums2[n2 - 1]);
	}
};
