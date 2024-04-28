#include <algorithm>
#include <climits>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumAddedInteger(vector<int> &nums1, vector<int> &nums2)
	{
		int N = nums1.size(), res = INT_MAX;
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		for (int i = 0; i < N; ++i)
		{
			for (int j = i + 1; j < N; ++j)
				res = min(res, check(nums1, i, j, nums2));
		}
		return res;
	}

	int check(vector<int> &nums1, int index1, int index2, vector<int> &nums2)
	{
		int N = nums2.size(), i = 0, j = 0;
		if (i == index1)
			++i;
		if (i == index2)
			++i;
		int diff = nums2[j] - nums1[i];
		for (; j < N; ++j, ++i)
		{
			if (i == index1)
				++i;
			if (i == index2)
				++i;
			if (nums2[j] - nums1[i] != diff)
				return INT_MAX;
		}
		return diff;
	}
};