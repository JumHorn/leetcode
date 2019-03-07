#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=accumulate(nums.begin(),nums.end(),0);
		if(sum%k!=0)
			return false;
		sum/=k;
		sort(nums.begin(),nums.end());
		if(nums.back()>sum)
			return false;
		return canPartitionKSubsets(nums,sum,sum,nums.size(),0);
    }

	bool canPartitionKSubsets(vector<int>& nums,int k,int sum,int left,int start)
	{
		if(left==0&&k==0)
			return true;
		if(left==0||k<0)
			return false;
		if(k==0)
			return canPartitionKSubsets(nums,sum,sum,left,0);
		for(int i=start;i<(int)nums.size();i++)
		{
			if(nums[i]==-1)
				continue;
			int tmp=nums[i];
			nums[i]=-1;
			if(canPartitionKSubsets(nums,k-tmp,sum,left-1,i+1))
				return true;
			nums[i]=tmp;
		}
		return false;
	}
};
