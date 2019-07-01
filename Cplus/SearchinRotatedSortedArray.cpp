#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
		int low=0,high=nums.size()-1;
		while(low<=high)
		{
			int mid=(high-low)/2+low;
			if(target==nums[mid])
				return mid;
			if(target>nums[mid])
			{
				if(nums[mid]<=nums[high])
                {
                    if(target<=nums[high])
					    return binarySearch(nums,target,mid+1,high);
                    else
                        high=mid-1;
                }
                else
                    low=mid+1;
			}
			else
			{
				if(nums[mid]>=nums[low])
                {
                    if(target>=nums[low])
					    return binarySearch(nums,target,low,mid-1);
                    else
                        low=mid+1;
                }
                else
                    high=mid-1;
			}
		}
		return -1;
    }

	int binarySearch(vector<int>& nums,int target,int low,int high)
	{
		while(low<=high)
		{
			int mid=(high-low)/2+low;
			if(target==nums[mid])
				return mid;
			if(target>nums[mid])
				low=mid+1;
			else
				high=mid-1;
		}
		return -1;
	}
};