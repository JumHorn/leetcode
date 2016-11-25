public class MedianofTwoSortedArrays
{
	public double findMedianSortedArrays(int[] nums1,int[] nums2)
	{
		int i=0,j=0,k=(nums1.length+nums2.length)/2;
		int q=(nums1.length+nums2.length)%2;
		int n=0;
		while(true)
		{
			if(nums1[i]>nums2[j])
			{
				if(j<nums2.length)
					j++;
				else
				{
					i++;
					j++;
				}

				if(n==k)
					break;
				else
					n++;
			}
			else
			{
				if(i<nums1.length)
					i++;
				else
				{
					j++;
					i++;
				}
				if(n==k)
					break;
				else
					n++;
			}
		}
		if(q==1)
		{
			if(i>=nums1.length)
				return (double)nums2[j];
			else if(j>=nums2.length)
				return (double)nums1[i];
			else
				return nums1[i]>nums2[j]?(double)nums1[i]:(double)nums2[j];

		}
		if(q==0)
		{
			if(i>=nums1.length)
			{
				return (double)(nums2[j]+nums2[j-1])/2;
			}
			else if(j>=nums2.length)
			{
				return (double)(nums1[i]+nums2[i-1])/2;
			}
			else
			{
				return (nums1[i]+nums2[j])/2;
			}
		}
                return 0;
	}
}
