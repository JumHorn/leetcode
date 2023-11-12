#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minOperations(vector<int> &nums1, vector<int> &nums2)
	{
		int res1 = minOps(nums1, nums2);
		swap(nums1.back(), nums2.back());
		int res2 = minOps(nums1, nums2);
		if (res2 >= 0)
			++res2;
		if (res1 == -1 && res2 == -1)
			return -1;
		if (res1 == -1)
			return res2;
		if (res2 == -1)
			return res1;
		return min(res1, res2);
	}

	int minOps(vector<int> nums1, vector<int> nums2)
	{
		int N = nums1.size(), val1 = nums1.back(), val2 = nums2.back();
		int res = 0;
		for (int i = 0; i < N - 1; ++i)
		{
			if (nums1[i] > val1)
			{
				if (nums1[i] > val2 || nums2[i] > val1)
					return -1;
				swap(nums1[i], nums2[i]);
				++res;
			}
			if (nums2[i] > val2)
			{
				if (nums2[i] > val1 || nums1[i] > val2)
					return -1;
				swap(nums1[i], nums2[i]);
				++res;
			}
		}
		return res;
	}
};