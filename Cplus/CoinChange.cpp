#include<vector>
#include<algorithm>
#include<functional>
#include<climits>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int,int> dp;
		return coinChange(coins,amount,dp);
    }

	int coinChange(vector<int>& coins,int amount,unordered_map<int,int>& dp)
	{
        if(dp.find(amount)!=dp.end())
            return dp[amount];
		if(amount<0)
			return -1;
		if(amount==0)
			return 0;
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