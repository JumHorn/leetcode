#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount==0)
            return 1;
		vector<vector<int> > dp(coins.size()+1,vector<int>(amount+1));
		for(int j=1;j<=amount;j++)
			for(int i=1;i<=(int)coins.size();i++)
			{
				if(j==coins[i-1])
					dp[i][j]=1+dp[i-1][j];
				else if(j<coins[i-1])
					dp[i][j]=dp[i-1][j];
				else
					dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];
			}
		return dp.back().back();
    }
};
