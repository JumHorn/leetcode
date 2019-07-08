#include<vector>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
		vector<vector<int>> dp(nums.size(),vector<int>(2,1));        
		int res=0,maxlen=1;
		for(int i=0;i<(int)nums.size();i++)
			for(int j=0;j<i;j++)
			{
				if(nums[i]>nums[j])
				{
					if(dp[i][0]==dp[j][0]+1)
						dp[i][1]+=dp[j][1];
					if(dp[i][0]<dp[j][0]+1)
					{
						dp[i][0]=dp[j][0]+1;
						dp[i][1]=dp[j][1];
					}
				}
			}
		for(int i=0;i<(int)dp.size();i++)
			if(dp[i][0]>maxlen)
				maxlen=dp[i][0];
		for(int i=0;i<(int)dp.size();i++)
			if(dp[i][0]==maxlen)
				res+=dp[i][1];
		return res;
    }
};