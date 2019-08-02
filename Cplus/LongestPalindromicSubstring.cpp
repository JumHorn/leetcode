#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
	    vector<vector<int>> dp(n,vector<int>(n,-1));
		string res;
		for(int i=0;i<n;i++)
			for(int j=i;j<n;j++)
			{
				if(dp[i][j]==-1)
					palindrome(dp,i,j,s);
				if(dp[i][j]!=0&&j-i+1>(int)res.size())
					res=s.substr(i,j-i+1);
			}
		return res;
    }

	bool palindrome(vector<vector<int>>& dp,int i,int j,const string& s)
	{
		if(i>=j)
		{
			dp[i][j]=1;
			return true;
		}
		if(dp[i][j]!=-1)
			return dp[i][j]==1;
		if(s[i]!=s[j])
		{
			dp[i][j]=0;
			return false;
		}
		bool res=palindrome(dp,i+1,j-1,s);
		dp[i][j]=res?1:0;
		return res;
	}
};