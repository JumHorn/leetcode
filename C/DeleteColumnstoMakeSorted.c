

int minDeletionSize(char ** A, int ASize){
	int res=0,i=0,j=0;
	char *p=A[0];
	while(*p)
	{
		for(i=0;i<ASize-1;i++)
			if(A[i][j]>A[i+1][j])
				break;
		if(i!=ASize-1)
			res++;
		j++;
		++p;
	}
	return res;
}

