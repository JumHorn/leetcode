#include<iostream>
#include<cmath>
using namespace std;

class Solution {
public:
    int checkRecord(int n) {
        int MOD = 1e9+7;
		int (*dp)[2][3]=new int[n+1][2][3];
		for(int i=0;i<2;i++)
			for(int j=0;j<3;j++)
				dp[0][i][j]=1;
		for(int i=1;i<=n;i++)
			for(int j=0;j<2;j++)
				for(int k=0;k<3;k++)
				{
					int val=dp[i-1][j][2];
					if(j>0)
						val=(val+dp[i-1][j-1][2])%MOD;
					if(k>0)
						val=(val+dp[i-1][j][k-1])%MOD;
					dp[i][j][k]=val;
				}
        return dp[n][1][2];
    }
};
