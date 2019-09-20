


int numPairsDivisibleBy60(int* time, int timeSize){
	int dp[60]={0};
	for(int i=0;i<timeSize;i++)
		dp[time[i]%60]++;
	int res=dp[0]*(dp[0]-1)/2+dp[30]*(dp[30]-1)/2;
	for(int i=1;i<30;i++)
		res+=dp[i]*dp[60-i];
	return res;
}

