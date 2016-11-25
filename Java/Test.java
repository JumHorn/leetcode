public class Test
{
	public static void main(String[] args)
	{
               int[] nums2={2,3,4};
               int[] nums1={1};
               System.out.println(new Test().findMedianSortedArrays(nums1,nums2));
	}
        double findMedianSortedArrays(int[] nums1, int[] nums2) {
                int i=0,j=0,k=(nums1.length+nums2.length)/2;
		int q=(nums1.length+nums2.length)%2;
		int n=0;
		if((nums1.length==0||nums2.length==0)||(nums1.length==1&&nums2.length==1))
		{
		    if(nums1.length==0)
		    {
		    if(q==1)
		    return (double)nums2[k];
		    else
		    return (double)(nums2[k]+nums2[k-1])/2;
		    }
		    else if(nums2.length==0)
		    {
		
		    if(q==1)
		    return (double)nums1[k];
		    else
		    return (double)(nums1[k]+nums1[k-1])/2;
		
		    }
		    else
		    {
        
            return (double)(nums1[0]+nums2[0])/2;
        
		    }
		}
		while(true)
		{
			if(i<nums1.length&&j<nums2.length&&nums1[i]>nums2[j])
			{
				if(j<nums2.length)
					j++;
				else
				{
					i++;
				}
				n++;
				if(n==k)
					break;
			}
			else
			{
				if(i<nums1.length)
					i++;
				else
				{
					j++;
				}
				n++;
				if(n==k)
					break;
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
			if(i>=nums1.length&&j>1)
			{
				return (double)(nums2[j]+nums2[j-1])/2;
			}
			else if(j>=nums2.length&&i>1)
			{
				return (double)(nums1[i]+nums1[i-1])/2;
			}
			else
			{   
			    if(i>=nums1.length||j>=nums2.length)
			    {
			        if(i>=nums1.length)
			        {System.out.println(i+"sss"+j);
			            return (double)(nums1[i-1]+nums2[j])/2;
			        }
			        else
			        {
			            return (double)(nums1[i]+nums2[j-1])/2;
			        }
			        
			    }
			    else
				return (double)(nums1[i-1]+nums2[j-1])/2;
			}
		}
                return 0;
    }
}
