#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
		int len=nums.size();
		nums.insert(nums.begin(),1);
		nums.push_back(1);
		vector<vector<int> > dp(nums.size(),vector<int>(nums.size()));
		for(int n=1;n<=len;n++)
			for(int i=1;i<=len-n+1;i++)
			{
				int j=i+n-1;
				for(int k=i;k<=j;k++)
				{
					dp[i][j]=max(dp[i][j],nums[i-1]*nums[k]*nums[j+1]+dp[i][k-1]+dp[k+1][j]);
				}
			}
		return dp[1][len];
    }
};
