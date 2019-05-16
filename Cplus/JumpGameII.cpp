#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
		vector<int> dp(nums.size(),INT_MAX);        
		dp[0]=0;
		for(int i=0;i<(int)dp.size();i++)
		{
			int tmp=min(nums[i],(int)nums.size()-i-1);
			for(int j=1;j<=tmp;j++)
			{
				dp[i+j]=min(dp[i+j],dp[i]+1);
				if(i+j==(int)nums.size()-1)
					return dp[i+j];
			}
		}
		return dp.back();
    }
};
