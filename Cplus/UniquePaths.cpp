/*
dynamic programming
A(m,n)=A(m-1,n)+A(m,n-1)
A(1,n)=1
A(m,1)=1
*/

#include<vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
		vector<vector<int> > dp(m,vector<int>(n,1));
    	for(int i=1;i<m;i++)
		{
			for(int j=1;j<n;j++)
			{
				dp[i][j]=dp[i-1][j]+dp[i][j-1];
			}
		}
		return dp[m-1][n-1];
	}
};

//class Solution {
//public:
//    int uniquePaths(int m, int n) {
//		if(m==1||n==1)
//		{
//			return 1;
//		}
//		return uniquePaths(m-1,n)+uniquePaths(m,n-1);        
//    }
//};
