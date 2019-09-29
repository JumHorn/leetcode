#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
		int M=str1.length(),N=str2.length();
		vector<vector<string>> dp(M+1,vector<string>(N+1));
		for(int i=1;i<=M;i++)
			for(int j=1;j<=N;j++)
			{
				if(str1[i-1]==str2[j-1])
					dp[i][j]=dp[i-1][j-1]+str1[i-1];
				else
					dp[i][j]=dp[i-1][j].length()>dp[i][j-1].length()?dp[i-1][j]:dp[i][j-1];
			}
		string lcs(dp[M][N]);
		string res(M+N-lcs.length(),' ');
		int i=0,j=0,k=0,s=0;
		while(s<(int)lcs.length())
		{
			while(str1[i]!=lcs[s])
				res[k++]=str1[i++];
			while(str2[j]!=lcs[s])
				res[k++]=str2[j++];
			res[k++]=lcs[s++];
			i++;
			j++;
		}
		while(i<M)
			res[k++]=str1[i++];
		while(j<N)
			res[k++]=str2[j++];
		return res;
    }
};
