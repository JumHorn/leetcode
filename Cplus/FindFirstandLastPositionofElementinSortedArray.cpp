#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> res={-1,-1};
		if(nums.empty())
			return res;
		if(target<nums.front()||target>nums.back())
			return res;	
		int low=0,high=nums.size()-1,mid;
		while(low<=high)
		{
			mid=(high-low)/2+low;
			if(target==nums[mid])
				break;
			if(target<nums[mid])
				high=mid-1;
			else
				low=mid+1;
		}
		if(low>high)
			return res;
		res[1]=mid;
		low=0,high=mid;
		while(low<high)
		{
			mid=(high-low)/2+low;
			if(nums[mid]==target)
				high=mid;
			else
				low=mid+1;
		}
		res[0]=high;
		low=res[1]+1;
		high=nums.size()-1;
		while(low<=high)
		{
			mid=(high-low)/2+low;
			if(nums[mid]==target)
            {
                res[1]=mid;
				low=mid+1;
            }
			else
				high=mid-1;
		}
		return res;
    }
};