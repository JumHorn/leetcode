#include<limits.h>


int smallestRangeI(int* A, int ASize, int K){
	int max=INT_MIN,min=INT_MAX;
	for(int i=0;i<ASize;i++)
		if(A[i]>max)
			max=A[i];
	for(int i=0;i<ASize;i++)
		if(A[i]<min)
			min=A[i];
	int res=max-min-K*2;
	if(res<=0)
		return 0;
	return res;
}

