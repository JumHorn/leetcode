


int binaryGap(int N){
	int res=0;
	for(int i=0,j=32;i<31;i++)
	{
		if(N&(1<<i))
		{
			if(i-j+1>res)
				res=i-j;
			j=i;
		}
	}
	return res;
}

