#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.empty())
            return 0;
		int (*dp)[2]=new int[nums.size()][2];
        dp[0][0]=dp[0][1]=1;
		for(int i=1;i<(int)nums.size();i++)
        {
            if(nums[i]-nums[i-1]==0)
            {
                dp[i][0]=dp[i-1][0];
                dp[i][1]=dp[i-1][1];
                continue;
            }
            if(nums[i]-nums[i-1]>0)
            {
                dp[i][0]=max(dp[i-1][0],dp[i-1][1]+1);
                dp[i][1]=dp[i-1][1];
            }
            else
            {
                dp[i][1]=max(dp[i][1],dp[i-1][0]+1);
                dp[i][0]=dp[i-1][0];
            }
        }
		return max(dp[nums.size()-1][0],dp[nums.size()-1][1]);
    }
};
