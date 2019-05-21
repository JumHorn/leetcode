#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
		int M=t.length(),N=s.length();
		vector<vector<unsigned int> > dp(M+1,vector<unsigned int>(N+1));
		for(int i=0;i<N;i++)
			dp[0][i]=1;
		for(int i=1;i<=M;i++)
			for(int j=1;j<=N;j++)
			{
				if(t[i-1]==s[j-1])
					dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
				else
					dp[i][j]=dp[i][j-1];
			}
		return dp.back().back();
    }
};
