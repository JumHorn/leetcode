#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.length();
	    vector<vector<int>> dp(len,vector<int>(len,-1));
		int m=0,n=0;
		for(int i=0;i<len;i++)
			for(int j=i;j<len;j++)
			{
				if(dp[i][j]==-1)
					palindrome(dp,i,j,s);
				if(dp[i][j]!=0&&j-i>n-m)
				{
					m=i;
					n=j;
				}
			}
		return s.substr(m,n-m+1);
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
