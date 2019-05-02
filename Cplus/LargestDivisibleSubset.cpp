#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
		vector<int> res;
		if(nums.empty())
			return res;
		sort(nums.begin(),nums.end());
        int (*dp)[2] = new int[nums.size()][2];
        for(int i=0;i<(int)nums.size();i++)
            dp[i][0]=1;
		int maxnum=1,maxindex=0;
		for(int i=1;i<(int)nums.size();i++)
		{
			for(int j=0;j<i;j++)
				if(nums[i]%nums[j]==0&&dp[i][0]<dp[j][0]+1)
				{
					dp[i][1]=j;
				 	dp[i][0]=dp[j][0]+1;
					if(dp[i][0]>maxnum)
					{
						maxindex=i;
						maxnum=dp[i][0];
					}
				}
		}
        if(maxnum==1)
            res.push_back(nums[maxindex]);
		while(maxnum!=1)
		{
			res.push_back(nums[maxindex]);
			maxnum=dp[maxindex][0];
			maxindex=dp[maxindex][1];
		}

		return res;
    }
};
