#include<string>
using namespace std;

class Solution {
	static const int mod = 1000000007;
public:
    int countPalindromicSubsequences(string S) {
        int res=0;
        static int dp[1000][1000][4];
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<4;i++)
			res=(res+recursion(dp,S,0,S.size()-1,i))%mod;
		return res;
    }

	int recursion(int (*dp)[1000][4],const string& s,int l,int r,int alpha)
	{
		if(l>r)
			return 0;
		if(l==r)
        {
            if(s[l]==(alpha+'a'))
                return 1;
			return 0;
        }
		if(dp[l][r][alpha]!=-1)
			return dp[l][r][alpha];
		int res=0;
		if(s[l]==s[r]&&s[l]==(alpha+'a'))
		{
			for(int i=0;i<4;i++)
				res=(res+recursion(dp,s,l+1,r-1,i))%mod;
			res+=2;
		}
		else
			res=(recursion(dp,s,l+1,r,alpha)%mod+recursion(dp,s,l,r-1,alpha)%mod-recursion(dp,s,l+1,r-1,alpha)%mod)%mod;
		dp[l][r][alpha]=res;
		return res%mod;
	}
};
