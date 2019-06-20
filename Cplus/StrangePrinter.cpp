#include<string>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
        if(s.empty())
            return 0;
		vector<vector<int>> dp(s.length(),vector<int>(s.length(),-1));
		return strangePrinter(s,0,s.length()-1,dp);
    }

	int strangePrinter(const string& s,int i,int j,vector<vector<int>>& dp)
	{
		if(dp[i][j]!=-1)
			return dp[i][j];
		if(i==j)
		{
			dp[i][j]=1;
			return 1;
		}
		if(j-i==1)
		{
			if(s[i]==s[j])
				dp[i][j]=1;
			else
				dp[i][j]=2;
			return dp[i][j];
		}
		int res=INT_MAX;
		for(int k=i;k<j;k++)
		{
			if(s[k]==s[j])
				res=min(res,strangePrinter(s,i,k,dp)+strangePrinter(s,k+1,j,dp)-1);
			else
				res=min(res,strangePrinter(s,i,k,dp)+strangePrinter(s,k+1,j,dp));
		}
		dp[i][j]=res;
		return res;
	}
};

