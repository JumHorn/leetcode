


int matrixScore(int** A, int ASize, int* AColSize){
	for(int i=0;i<ASize;i++)
	{
		if(A[i][0]==0)
			for(int j=0;j<*AColSize;j++)
				A[i][j]=1-A[i][j];
	}
	for(int j=1;j<*AColSize;j++)
	{
		int count=0;
		for(int i=0;i<ASize;i++)
			count+=A[i][j];
		if(count*2<ASize)
			for(int i=0;i<ASize;i++)
				A[i][j]=1-A[i][j];
	}
	int res=0;
	for(int i=0;i<ASize;i++)
	{
		int val=0;
		for(int j=0;j<*AColSize;j++)
			if(A[i][j]==1)
				val+=1<<(*AColSize-j-1);
		res+=val;
	}
	return res;
}


