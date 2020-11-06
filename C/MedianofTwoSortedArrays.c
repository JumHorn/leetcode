
//merge
//count the number of smaller half part

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
	int sum = nums1Size + nums2Size, count = sum / 2, midleft, midright;
	for (int i = 0, j = 0; count >= 0 && (i < nums1Size || j < nums2Size);)
	{
		if (i == nums1Size)
			midright = nums2[j++];
		else if (j == nums2Size)
			midright = nums1[i++];
		else
			midright = (nums1[i] < nums2[j] ? nums1[i++] : nums2[j++]);
		if (--count == 0)
			midleft = midright;
	}
	return sum % 2 == 0 ? (midleft + midright) / 2.0 : midright;
}