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
		return count(nums1, nums2) + count(nums2, nums1);
	}

	int count(vector<int> &nums1, vector<int> &nums2)
	{
		int N = nums2.size(), res = 0;
		for (auto n : nums1)
		{
			for (int i = 0, j = N - 1; i < j;)
			{
				if ((long)nums2[i] * nums2[j] == (long)n * n)
				{
					int l = i + 1, r = j - 1;
					while (l <= r && nums2[l] == nums2[i])
						++l;
					while (l <= r && nums2[r] == nums2[j])
						--r;
					if (nums2[i] != nums2[j] || l <= r)
						res += (l - i) * (j - r);
					else
						res += (j - i + 1) * (j - i) / 2;
					i = l;
					j = r;
				}
				else if ((long)nums2[i] * nums2[j] < (long)n * n)
					++i;
				else
					--j;
			}
		}
		return res;
	}
};