#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
		sort(nums.begin(),nums.end());        
		return combinationSum(nums,target);
    }

	int combinationSum(vector<int>& nums,int target)
	{
		if(target==0)
			return 1;
		if(target<0)
			return 0;
		int sum=0;
		for(int i=0;i<nums.size();i++)
		{
			sum+=combinationSum(nums,target-nums[i]);
		}
		return sum;
	}
};
