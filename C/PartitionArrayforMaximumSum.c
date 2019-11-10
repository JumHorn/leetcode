#include<stdlib.h>
#include<string.h>

int maxSumAfterPartitioning(int* A, int ASize, int K){
	int *dp=(int*)malloc((ASize+1)*sizeof(int));
    memset(dp,0,sizeof(int)*(ASize+1));
	dp[1]=A[0];
	for(int i=1;i<ASize;i++)
	{
		int max=A[i],index=i-K>=0?i-K:-1;
		for(int j=i;j>index;j--)
		{
			if(A[j]>max)
				max=A[j];
			if(max*(i-j+1)+dp[j]>dp[i+1])
				dp[i+1]=max*(i-j+1)+dp[j];
		}
	}
	return dp[ASize];
}

