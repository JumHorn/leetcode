#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return search(nums,target,0,nums.size()-1);
    }

    bool search(vector<int>& nums, int target,int low,int high) 
    {
		while(low<=high)
		{
			int mid=(high-low)/2+low;
			if(target==nums[mid])
				return true;
			if(target>nums[mid])
			{
                if(nums[mid]==nums[high])
                    return search(nums,target,low,mid-1)||search(nums,target,mid+1,high);
				else if(nums[mid]<nums[high])
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
                if(nums[mid]==nums[low])
                    return search(nums,target,low,mid-1)||search(nums,target,mid+1,high);
				else if(nums[mid]>nums[low])
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
		return false;
    }

	bool binarySearch(vector<int>& nums,int target,int low,int high)
	{
		while(low<=high)
		{
			int mid=(high-low)/2+low;
			if(target==nums[mid])
				return true;
			if(target>nums[mid])
				low=mid+1;
			else
				high=mid-1;
		}
		return false;
	}
};