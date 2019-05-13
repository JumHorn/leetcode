#include<vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int i=0,j=0,len1=nums1.size(),len2=nums2.size(),tmp=(len1+len2)/2+1,t1,t2;
		bool even=((len1+len2)%2==0);
		while(i<len1&&j<len2)
		{
			if(nums1[i]<nums2[j])
			{
				t1=t2;
				t2=nums1[i];
				i++;
			}
			else
			{
				t1=t2;
				t2=nums2[j];
				j++;
			}

			if(i+j==tmp)
			{
				return even?(t1+t2)/2.0:t2;
			}
		}
		while(i<len1)
		{
			t1=t2;
			t2=nums1[i++];
			if(i+j==tmp)
				return even?(t1+t2)/2.0:t2;
		}
		while(j<len2)
		{
			t1=t2;
			t2=nums2[j++];
			if(i+j==tmp)
				return even?(t1+t2)/2.0:t2;
		}
		return 0;
    }
};
