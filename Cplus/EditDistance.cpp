#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
		int M=word1.size(),N=word2.size();
		vector<vector<int> > dp(M+1,vector<int>(N+1));        
		for(int i=0;i<M;i++)
			dp[i+1][0]=i+1;
		for(int i=0;i<N;i++)
			dp[0][i+1]=i+1;
		for(int i=0;i<M;i++)
			for(int j=0;j<N;j++)
			{
				if(word1[i]==word2[j])
					dp[i+1][j+1]=dp[i][j];
				else
					dp[i+1][j+1]=min(dp[i][j],min(dp[i][j+1],dp[i+1][j]))+1;
			}
		return dp[M][N];
    }
};
