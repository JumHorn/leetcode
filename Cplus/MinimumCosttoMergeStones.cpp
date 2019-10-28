#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
		int N=stones.size();
		if((N-1)%(K-1)!=0)
			return -1;
		vector<int> sum(N+1);        
		for(int i=1;i<=N;i++)
			sum[i]=sum[i-1]+stones[i-1];
		vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(N+1,vector<int>(K+1)));
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
				for(int k=1;k<=K;k++)
					dp[i][j][k]=100000000;
		for(int i=1;i<=N;i++)
			dp[i][i][1]=0;
		for(int l=2;l<=N;l++)
			for(int i=1;i<=N-l+1;i++)
			{
				int j=i+l-1,k;
				for(k=2;k<=K;k++)
					for(int t=i;t<j;t++)
						dp[i][j][k]=min(dp[i][j][k],dp[i][t][k-1]+dp[t+1][j][1]);
				dp[i][j][1]=dp[i][j][K]+sum[j]-sum[i-1];
			}
		return dp[1][N][1];
    }
};
