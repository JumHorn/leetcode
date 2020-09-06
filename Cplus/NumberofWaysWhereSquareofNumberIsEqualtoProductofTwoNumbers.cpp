#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int numTriplets(vector<int> &nums1, vector<int> &nums2)
	{
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		int n1 = nums1.size(), n2 = nums2.size(), res = 0;
		for (int i = 0; i < n1; ++i)
		{
			int j = 0, k = n2 - 1;
			while (j < k)
			{
				long val = long(nums2[j]) * nums2[k], square = long(nums1[i]) * nums1[i];
				if (val == square)
				{
					int m = j + 1;
					while (m < k && nums2[m] == nums2[j])
						++m;
					int n = k - 1;
					while (n > j && nums2[n] == nums2[k])
						--n;
					if (n >= m)
					{
						res += (m - j) * (k - n);
						j = m - 1;
						k = n + 1;
					}
					else
					{
						if (nums2[j] == nums2[k])
							res += (k - j + 1) * (k - j) / 2;
						else
							res += (m - j) * (k - n);
						break;
					}
				}
				if (val < square)
					++j;
				else
					--k;
			}
		}

		for (int i = 0; i < n2; ++i)
		{
			int j = 0, k = n1 - 1;
			while (j < k)
			{
				long val = long(nums1[j]) * nums1[k], square = long(nums2[i]) * nums2[i];
				if (val == square)
				{
					int m = j + 1;
					while (m < k && nums1[m] == nums1[j])
						++m;
					int n = k - 1;
					while (n > j && nums1[n] == nums1[k])
						--n;
					if (n >= m)
					{
						res += (m - j) * (k - n);
						j = m - 1;
						k = n + 1;
					}
					else
					{
						if (nums1[j] == nums1[k])
							res += (k - j + 1) * (k - j) / 2;
						else
							res += (m - j) * (k - n);
						break;
					}
				}
				if (val < square)
					++j;
				else
					--k;
			}
		}
		return res;
	}
};