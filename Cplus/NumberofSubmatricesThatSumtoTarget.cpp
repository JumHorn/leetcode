#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
		int res=0,M=matrix.size(),N=matrix[0].size();
		vector<vector<int>> dp(M,vector<int>(N+1));        
		for(int i=0;i<M;i++)
			for(int j=0;j<N;j++)
				dp[i][j+1]=matrix[i][j]+dp[i][j];
		for(int i=1;i<=N;i++)
			for(int j=i;j<=N;j++)
			{
                unordered_map<int,int> m;
                m[0]=1;
                int add=0;
				for(int k=0;k<M;k++)
                {
                    add+=dp[k][j]-dp[k][i-1];
                    res+=m[add-target];
                    m[add]++;
                }
			}
		return res;
    }
};

int main()
{
    vector<vector<int>> v=
    {
        {{0,1,0},{1,1,1},{0,1,0}}
    };
    Solution sol;
    sol.numSubmatrixSumTarget(v,0);
    return 0;
}