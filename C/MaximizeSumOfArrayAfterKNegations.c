#include<stdlib.h>

int largestSumAfterKNegations(int* A, int ASize, int K){
	int dp[201]={0};
	for(int i=0;i<ASize;i++)
		dp[A[i]+100]++;
	for(int i=0;i<100;i++)
	{
		if(dp[i]!=0)
		{
			if(K>=dp[i])
			{
				dp[-(i-100)+100]+=dp[i];
				K-=dp[i];
				dp[i]=0;
			}
			else
			{
				dp[-(i-100)+100]+=K;
				dp[i]-=K;
				K=0;
			}
		}
		if(K==0)
			break;
	}
	int res=0;
	if(K!=0&&K%2!=0)
	{
		for(int i=100;i<201;i++)
			if(dp[i]!=0)
			{
				dp[i]--;
				res-=i-100;
				break;
			}
	}
	for(int i=0;i<=200;i++)
		res+=dp[i]*(i-100);
	return res;
}

