#include<vector>
#include<algorithm>
#include<functional>
#include<climits>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1);
		return coinChange(coins,amount,dp);
    }

	int coinChange(vector<int>& coins,int amount,vector<int>& dp)
	{
        if(amount<0)
			return -1;
        if(amount==0)
			return 0;
        if(dp[amount]!=0)
            return dp[amount];
        int res=INT_MAX;
		for(int i=0;i<(int)coins.size();i++)
		{
			int tmp=coinChange(coins,amount-coins[i],dp);
			if(tmp>=0)
				res=min(res,tmp+1);
		}
        if(res==INT_MAX)
            res=-1;
        dp[amount]=res;
		return res;
	}
};