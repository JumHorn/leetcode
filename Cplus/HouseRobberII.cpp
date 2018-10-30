/*
A(m)=max{A(m-1),A(m-2)+x}
*/
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
		if(nums.empty())
			return 0;
		if(nums.size()==1)
			return nums[0];
		if(nums.size()==2)
			return max(nums[0],nums[1]);
		if(nums.size()==3)
			return max(nums[0],max(nums[1],nums[2]));
		vector<int> dp0_n_1(nums.size()-1);
		dp0_n_1[0]=nums[0];
		dp0_n_1[1]=max(nums[0],nums[1]);
		for(int i=2;i<dp0_n_1.size();i++)
		{
			dp0_n_1[i]=max(dp0_n_1[i-1],dp0_n_1[i-2]+nums[i]);
		}
		vector<int> dp1_n(nums.size()-1);
		dp1_n[0]=nums[1];
		dp1_n[1]=max(nums[1],nums[2]);
		for(int i=2;i<dp1_n.size();i++)
		{
			dp1_n[i]=max(dp1_n[i-1],dp1_n[i-2]+nums[i+1]);
		}
		return max(dp1_n[dp1_n.size()-1],dp0_n_1[dp0_n_1.size()-1]);
	}
};
