#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
		if(s1.size()+s2.size()!=s3.size())
			return false;
		if(s1.empty())
			return s2==s3;
		if(s2.empty())
			return s1==s3;
		int M=s1.size(),N=s2.size(),i=0,j=0;
		vector<vector<bool> > dp(M+1,vector<bool>(N+1));
		dp[0][0]=true;
		for(i=1;i<=M;i++)
		{
			if(s1[i-1]==s3[i-1])
				dp[i][0]=true;
			else
				break;
		}
		while(i<=M)
			dp[i++][0]=false;
		for(i=1;i<=N;i++)
		{
			if(s2[i-1]==s3[i-1])
				dp[0][i]=true;
			else
				break;
		}
		while(i<=N)
			dp[0][i++]=false;

		for(i=1;i<=M;i++)
			for(j=1;j<=N;j++)
				dp[i][j]=(s1[i-1]==s3[i+j-1]&&dp[i-1][j])||(s2[j-1]==s3[i+j-1]&&dp[i][j-1]);

		return dp.back().back();
    }
};
