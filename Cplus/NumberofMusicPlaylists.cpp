#include<cmath>
#include<vector>
using namespace std;

class Solution {
	static const int mod=1e9+7;
public:
    int numMusicPlaylists(int N, int L, int K) {
		vector<vector<long> > dp(L+1,vector<long>(N+1));
		dp[0][0]=1;
		for(int i=1;i<=L;i++)
			for(int j=1;j<=N;j++)
			{
				dp[i][j]=dp[i-1][j-1]*(N-(j-1))%mod;
				if(j>K)
					dp[i][j]=(dp[i][j]+dp[i-1][j]*(j-K)%mod)%mod;
			}
		return dp.back().back();
    }
};
