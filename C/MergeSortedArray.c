
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	for (--m, --n; n >= 0;)
	{
		if (m >= 0 && nums1[m] > nums2[n])
			nums1[--nums1Size] = nums1[m--];
		else
			nums1[--nums1Size] = nums2[n--];
	}
}
