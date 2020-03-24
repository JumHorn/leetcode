
//merge
//count the number of smaller half part
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
	int i = 0, j = 0, sum = nums1Size + nums2Size, count = sum / 2, last0, last1;
	while (count != -1 && i < nums1Size && j < nums2Size)
	{
		last1 = (nums1[i] <= nums2[j] ? nums1[i++] : nums2[j++]);
		if (--count == 0)
			last0 = last1;
	}
	while (count != -1 && i < nums1Size)
	{
		last1 = nums1[i++];
		if (--count == 0)
			last0 = last1;
	}
	while (count != -1 && j < nums2Size)
	{
		last1 = nums2[j++];
		if (--count == 0)
			last0 = last1;
	}
	if (sum % 2 == 1)
		return last1;
	return (last0 + last1) / 2.0;
}

