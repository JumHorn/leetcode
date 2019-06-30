#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
		int N=grid.size();
		//r1 c1 r2
		vector<vector<vector<int>>> dp(N,vector<vector<int>>(N,vector<int>(N,INT_MIN)));
		return max(0,dfs(grid,dp,0,0,0));
    }

	int dfs(vector<vector<int>>& grid,vector<vector<vector<int>>>& dp,int r1,int c1,int r2)
	{
		int N=grid.size(),c2=r1+c1-r2;
		if(r1>=N||c1>=N||r2>=N||c2>=N||grid[r1][c1]==-1||grid[r2][c2]==-1)
			return -5000;//max N*N make all results minus
		if(r1==N-1&&c1==N-1)
			return grid[r1][c1];
		if(dp[r1][c1][r2]!=INT_MIN)
			return dp[r1][c1][r2];
        int res=grid[r1][c1];
        if(r1!=r2)
            res+=grid[r2][c2];
		res+=max(max(dfs(grid,dp,r1,c1+1,r2),dfs(grid,dp,r1,c1+1,r2+1)),
                max(dfs(grid,dp,r1+1,c1,r2),dfs(grid,dp,r1+1,c1,r2+1)));
        dp[r1][c1][r2]=res;
		return res;
	}
};