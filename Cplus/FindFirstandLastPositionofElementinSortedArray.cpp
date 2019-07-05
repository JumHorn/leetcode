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
		while(low<high)
		{
			mid=(high-low)/2+low;
			if(target<=nums[mid])
				high=mid;
			else
				low=mid+1;
		}
		if(nums[low]!=target)
			return res;
        res[0]=low;
		high=nums.size()-1;
		while(low<high)
		{
			mid=(high-low)/2+low+1;
			if(nums[mid]<=target)
				low=mid;
			else
				high=mid-1;
		}
        res[1]=high;
		return res;
    }
};