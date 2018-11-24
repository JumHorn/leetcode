#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
		sort(nums.begin(),nums.end());
		vector<int> mem(target+1,-1);
		return combinationSum(mem,nums,target);
    }

	int combinationSum(vector<int>& mem,vector<int>& nums,int target)
	{
		if(target==0)
			return 1;
		int sum=0;
		for(int i=0;i<nums.size();i++)
		{
			if(target-nums[i]<0)
				break;
			if(mem[target-nums[i]]==-1)
			{
				int tmp=combinationSum(mem,nums,target-nums[i]);
				mem[target-nums[i]]=tmp;
				sum+=tmp;
			}
			else
			{
				sum+=mem[target-nums[i]];
			}
		}
		return sum;
	}
};
