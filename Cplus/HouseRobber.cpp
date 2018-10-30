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
		if(nums[0]>nums[1])
			nums[1]=nums[0];
		int i;
		for(i=2;i<nums.size();i++)
			nums[i]=nums[i-1]>nums[i-2]+nums[i]?nums[i-1]:(nums[i-2]+nums[i]);
		return nums[i-1];
    }
};
