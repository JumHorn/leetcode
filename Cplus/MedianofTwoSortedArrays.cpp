#include <vector>
using namespace std;

class Solution
{
public:
	double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
	{
		int N1 = nums1.size(), N2 = nums2.size();
		int sum = N1 + N2, count = sum / 2, midleft, midright;
		for (int i = 0, j = 0; count >= 0 && (i < N1 || j < N2);)
		{
			if (i == N1)
				midright = nums2[j++];
			else if (j == N2)
				midright = nums1[i++];
			else
				midright = (nums1[i] < nums2[j] ? nums1[i++] : nums2[j++]);
			if (--count == 0)
				midleft = midright;
		}
		return sum % 2 == 0 ? (midleft + midright) / 2.0 : midright;
	}
};