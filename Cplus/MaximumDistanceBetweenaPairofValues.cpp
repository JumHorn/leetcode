#include <vector>
using namespace std;

class Solution
{
public:
	int maxDistance(vector<int> &nums1, vector<int> &nums2)
	{
		int i = 0, j = 0, N1 = nums1.size(), N2 = nums2.size();
		for (; i < N1 && j < N2; ++j)
		{
			if (nums1[i] > nums2[j])
				++i;
		}
		return max(j - i - 1, 0);
	}
};