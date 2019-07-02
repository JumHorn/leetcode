#include<vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int M=obstacleGrid.size(),N=obstacleGrid[0].size();
		vector<vector<long>> dp(M+1,vector<long>(N+1));
		dp[0][1]=1;
		for(int i=1;i<=M;i++)
			for(int j=1;j<=N;j++)
				if(obstacleGrid[i-1][j-1]!=1)
					dp[i][j]=dp[i-1][j]+dp[i][j-1];
		return dp[M][N];
    }
};
