#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int M=matrix.size()+1,N=matrix[0].size()+1;
		vector<vector<int> > dp(M,vector<int>(N));
		for(int i=1;i<M;i++)
			for(int j=1;j<N;j++)
				dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+matrix[i-1][j-1];
		int res=INT_MIN;
		for(int i=1;i<M;i++)
			for(int j=i;j<M;j++)
			{
				for(int m=1;m<N;m++)
                    for(int n=m;n<N;n++)
                    {
					    int tmp=dp[j][n]-dp[j][m-1]-dp[i-1][n]+dp[i-1][m-1];
                        if(tmp<=k)
                        {
                            res=max(res,tmp);
                            if(res==k)
                                return res;
                        }
			        }
			}
        return res;
    }
};