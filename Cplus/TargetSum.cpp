#include<vector>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
		if(nums.empty())
			return 0;
        return targetSum(nums,0,S);
    }

	int targetSum(vector<int>& nums,int index,int S)
	{
		if(index==nums.size()-1)
		{
			int res=0;
			if(S==nums[index])
				res++;
			if(S==-nums[index])
				res++;
			return res;
		}
		return targetSum(nums,index+1,S+nums[index])+targetSum(nums,index+1,S-nums[index]);
	}
};
