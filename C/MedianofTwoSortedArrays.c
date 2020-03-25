
//merge
//count the number of smaller half part
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
	int i = 0, j = 0, sum = nums1Size + nums2Size, count = sum / 2, midleft, midright;
	while (count != -1 && i < nums1Size && j < nums2Size)
	{
		midright = (nums1[i] <= nums2[j] ? nums1[i++] : nums2[j++]);
		if (--count == 0)
			midleft = midright;
	}
	while (count != -1 && i < nums1Size)
	{
		midright = nums1[i++];
		if (--count == 0)
			midleft = midright;
	}
	while (count != -1 && j < nums2Size)
	{
		midright = nums2[j++];
		if (--count == 0)
			midleft = midright;
	}
	return sum % 2 == 1 ? midright : (midleft + midright) / 2.0;
}