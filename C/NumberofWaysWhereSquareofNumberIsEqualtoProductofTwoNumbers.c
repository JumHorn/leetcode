#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void* lhs, const void* rhs)
{
	return *(int*)lhs - *(int*)rhs;
}

int count(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
	int res = 0;
	for (int k = 0; k < nums1Size; ++k)
	{
		for (int i = 0, j = nums2Size - 1; i < j;)
		{
			if ((long)nums2[i] * nums2[j] == (long)nums1[k] * nums1[k])
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
			else if ((long)nums2[i] * nums2[j] < (long)nums1[k] * nums1[k])
				++i;
			else
				--j;
		}
	}
	return res;
}

int numTriplets(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
	qsort(nums1, nums1Size, sizeof(int), cmp);
	qsort(nums2, nums2Size, sizeof(int), cmp);
	return count(nums1, nums1Size, nums2, nums2Size) + count(nums2, nums2Size, nums1, nums1Size);
}
