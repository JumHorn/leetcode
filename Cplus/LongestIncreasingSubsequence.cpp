#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		if(nums.empty())
			return 0;
		vector<int> dp(nums.size(),1);
		dp[0]=1;
		for(int i=1;i<(int)nums.size();i++)
		{
			for(int j=0;j<i;j++)
				if(nums[i]>nums[j])
					dp[i]=max(dp[i],dp[j]+1);
		}		
		return *max_element(dp.begin(),dp.end());
    }
};
