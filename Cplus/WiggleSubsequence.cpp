#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.empty())
            return 0;
		vector<vector<int> > dp(nums.size(),vector<int>(2,1));
		for(int i=1;i<(int)nums.size();i++)
			for(int j=0;j<i;j++)
			{
				if(nums[i]-nums[j]==0)
					continue;
				if(nums[i]-nums[j]>0)
				{
					dp[i][0]=max(dp[i][0],dp[j][1]+1);
				}
				else
				{
					dp[i][1]=max(dp[i][1],dp[j][0]+1);
				}
			}
		return max(dp.back()[0],dp.back()[1]);
    }
};
