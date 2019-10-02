
static int hash[]={0,1,5,-1,-1,2,9,-1,8,6};

int canBeRotated(int N)
{
	int tmp=N,base=1,rotate=0;
	while(tmp!=0)
	{
		if(hash[tmp%10]==-1)
			return 0;
		rotate+=hash[tmp%10]*base;
		tmp/=10;
		base*=10;
	}
	if(N==rotate)
		return 0;
	return 1;
}


int rotatedDigits(int N){
	int res=0;
	for(int i=1;i<=N;i++)
		res+=canBeRotated(i);
	return res;
}

