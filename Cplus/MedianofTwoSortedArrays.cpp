#include <vector>
using namespace std;

class Solution
{
public:
	double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
	{
		int i = 0, j = 0, len1 = nums1.size(), len2 = nums2.size();
		int sum = len1 + len2, count = sum / 2, midleft, midright;
		while (count >= 0 && i < len1 && j < len2)
		{
			midright = (nums1[i] < nums2[j] ? nums1[i++] : nums2[j++]);
			if (--count == 0)
				midleft = midright;
		}
		while (count >= 0 && i < len1)
		{
			midright = nums1[i++];
			if (--count == 0)
				midleft = midright;
		}
		while (count >= 0 && j < len2)
		{
			midright = nums2[j++];
			if (--count == 0)
				midleft = midright;
		}
		return sum % 2 == 0 ? (midleft + midright) / 2.0 : midright;
	}
};