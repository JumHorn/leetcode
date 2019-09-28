#include<vector>
using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
		int res=0,M=matrix.size(),N=matrix[0].size();
		vector<vector<int>> dp(M+1,vector<int>(N+1));        
		for(int i=0;i<M;i++)
			for(int j=0;j<N;j++)
				dp[i+1][j+1]=matrix[i][j]+dp[i][j+1]+dp[i+1][j]-dp[i][j];
		for(int i=1;i<=M;i++)
			for(int j=1;j<=N;j++)
			{
				for(int k=i;k<=M;k++)
					for(int l=j;l<=N;l++)
					{
						int tmp=dp[k][l]-dp[k][j-1]-dp[i-1][l]+dp[i-1][j-1];
						if(tmp==target)
							res++;
					}
			}
		return res;
    }
};