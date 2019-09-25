#include<stdlib.h>

int comp(const void* lhs,const void* rhs)
{
	return *(int*)lhs-*(int*)rhs;
}

int largestPerimeter(int* A, int ASize){
	qsort((void*)A,ASize,sizeof(int),comp);
	for(int i=ASize-1;i>=2;i--)
	{
		if(A[i]<A[i-1]+A[i-2])
			return A[i]+A[i-1]+A[i-2];
	}
	return 0;
}

