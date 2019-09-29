

int repeatedNTimes(int* A, int ASize){
	for(int k=1;k<=3;k++)
	{
		for(int i=0;i<ASize-k;i++)
		{
			if(A[i]==A[i+k])
				return A[i];
		}
	}
	return 0;
}

