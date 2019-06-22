#include<cmath>
#include<algorithm>
using namespace std;

class Solution {
	int dp[10001];
public:
    int racecar(int target) {
        if(dp[target]>0)
			return dp[target];
		int n=floor(log2(target))+1;
		if((1<<n)==target+1)
			dp[target]=n;
		else
		{
			dp[target]=racecar((1<<n)-target-1)+n+1;
			for(int i=0;i<n-1;i++)
				dp[target]=min(dp[target],racecar(target-(1<<(n-1))+(1<<i))+n-1+i+1+1);
		}
		return dp[target];
    }
};
