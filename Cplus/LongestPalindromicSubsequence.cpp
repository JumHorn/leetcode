#include<string>
#include<sstream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
		int res=0;
		vector<vector<int> > dp(s.length(),vector<int>(s.length()));
		for(int i=0;i<(int)s.length();i++)
		{
			res=max(res,longestPalindromeSubseq(s,i-1,i+1,dp)+1);
			res=max(res,longestPalindromeSubseq(s,i-1,i,dp));
			res=max(res,longestPalindromeSubseq(s,i,i+1,dp));
		}
		return res;
    }

	int longestPalindromeSubseq(const string& s,int i,int j,vector<vector<int> >& dp)
	{
		if(i<0||j>=(int)s.length())
			return 0;
		if(dp[i][j]>0)
			return dp[i][j];
		int res;
		if(s[i]==s[j])
			res=longestPalindromeSubseq(s,i-1,j+1,dp)+2;
		else
			res=max(longestPalindromeSubseq(s,i-1,j,dp),longestPalindromeSubseq(s,i,j+1,dp));
		dp[i][j]=res;
		return res;
	}
};
