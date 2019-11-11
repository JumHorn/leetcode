#include<stdlib.h>
#include<string.h>

#define min(a,b) (((a)>(b))?(b):(a))
#define max(a,b) (((a)>(b))?(a):(b))

int mincostTickets(int* days, int daysSize, int* costs, int costsSize){
	int *dp=(int*)malloc((days[daysSize-1]+1)*sizeof(int));
	memset(dp,0,(days[daysSize-1]+1)*sizeof(int));
	int index=0;
	for(int i=1;i<=days[daysSize-1];i++)
	{
		if(i!=days[index])
		{
			dp[i]=dp[i-1];
		}
		else
		{
			index++;
			dp[i]=dp[i-1]+costs[0];
			dp[i]=min(dp[i],dp[max(0,i-7)]+costs[1]);
			dp[i]=min(dp[i],dp[max(0,i-30)]+costs[2]);
		}
	}
	return dp[days[daysSize-1]];
}