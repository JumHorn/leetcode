#include<vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0)
            return 0;
		vector<vector<int> > dp(nums.size()+1,vector<int>(2));
        dp[0][0]=-1;
        dp[0][1]=1;
		int res=0,presum=1;
		for(int i=0;i<(int)nums.size();i++)
		{
			presum*=nums[i];
			dp[i+1][0]=presum;
            if(presum<k)
            {
                dp[i+1][1]=i+1;
                continue;
            }
			int tmp=presum/k;
			for(int j=i+1;j>=0;j--)
				if(dp[j][0]<tmp)
                {
					dp[i+1][1]=i-j;
                    break;
                }
		}
        for(int i=1;i<(int)dp.size();i++)
            res+=dp[i][1];
		return res;
    }
};
