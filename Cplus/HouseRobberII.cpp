/*
A(m)=max{A(m-1),A(m-2)+x}
*/
#include<vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
		if(nums.empty())
			return 0;
		if(nums.size()==1)
			return nums[0];
		if(nums.size()==2)
			return nums[0]>nums[1]?nums[0]:nums[1];
		vector<bool> flag(nums.size(),true);
		if(nums[0]>nums[1])
			nums[1]=nums[0];
		else
			flag[1]=false;
		int i;
		for(i=2;i<nums.size()-1;i++)
		{
			if(nums[i-1]==nums[i-2]+nums[i])
			{
				nums[i]=nums[i-1];
				flag[i]=flag[i-1]&&flag[i-2];
			}
			else if(nums[i-1]>nums[i-2]+nums[i])
			{
				nums[i]=nums[i-1];
				flag[i]=flag[i-1];
			}
			else
			{
				nums[i]=nums[i-2]+nums[i];
				flag[i]=flag[i-2];
			}
		}
		if(!flag[i-2])
			nums[i]=nums[i-1]>nums[i-2]+nums[i]?nums[i-1]:(nums[i-2]+nums[i]);
		else
			nums[i]=nums[i-1];
		return nums[i];
    }
};
