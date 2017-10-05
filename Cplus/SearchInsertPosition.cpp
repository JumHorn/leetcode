#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        return BinarySearch(nums,target,0,nums.size()-1);    
    }
    int BinarySearch(vector<int>& nums,int target,int l,int r)
    {
        int m = (l+r)/2;
        if(nums[m]==target)
        {
            return m;
        }
        if(l==r)
        {
            return nums[l]>target?l:l+1;
        }
        if(nums[m]>target)
        {
            return BinarySearch(nums,target,l,m);
        }
        else
        {
            return BinarySearch(nums,target,m+1,r);
        }
    }
};

class Solution0 {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int i;
        for(i=0;i<nums.size();i++)
        {
            if(target<nums[i])
            {
                break;
            }
        }  
        return i; 
    }
};