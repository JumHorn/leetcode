#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
		if(n<4)
			return n;
		vector<int> dp(n+1);
		dp[0]=0;
		dp[1]=1;
		dp[2]=2;
		dp[3]=3;
		for(int i=4;i<=n;i++)
		{
			int tmp=INT_MAX;
			for(int j=1;j*j<=i;j++)
			{
				tmp=min(tmp,1+dp[i-j*j]);
			}
			dp[i]=tmp;
		}
		return dp.back();
    }
};

int main()
{
	Solution sol;
	sol.numSquares(11);
}