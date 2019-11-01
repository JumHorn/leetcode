#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(desiredTotal<=0)
            return true;
		if(maxChoosableInteger*(maxChoosableInteger+1)/2<desiredTotal)
			return false;
		vector<unordered_map<int,int>> dp(desiredTotal+1);
		return canIWin(0,maxChoosableInteger,desiredTotal,dp);
    }

	bool canIWin(int n,int m,int t,vector<unordered_map<int,int>>& dp)
	{
		if(t<=0)
			return false;
		if(dp[t].find(n)!=dp[t].end())
			return dp[t][n];
		for(int i=0;i<m;i++)
		{
			if((n&(1<<i))==0)
			{
				if(!canIWin(n|(1<<i),m,t-i-1,dp))
				{
					dp[t][n]=true;
					return true;
				}
			}
		}
		dp[t][n]=false;
		return false;
	}
};