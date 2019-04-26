#include<string>
#include<sstream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
		vector<vector<int> > dp(s.length(),vector<int>(s.length()));
		return longestPalindromeSubseq(s,0,s.length()-1,dp);
    }

	int longestPalindromeSubseq(const string& s,int l,int r,vector<vector<int> >& dp)
	{
		if(l>r)
			return 0;
		if(l==r)
			return 1;
		if(dp[l][r]>0)
			return dp[l][r];
		int res;
		if(s[l]==s[r])
			res=longestPalindromeSubseq(s,l+1,r-1,dp)+2;
		else
			res=max(longestPalindromeSubseq(s,l+1,r,dp),longestPalindromeSubseq(s,l,r-1,dp));
		dp[l][r]=res;
		return res;
	}
};
