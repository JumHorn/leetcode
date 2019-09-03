#include<stdlib.h>
#include<string.h>

void duplicateZeros(int* arr, int arrSize){
	int *p=(int*)malloc((arrSize+1)*sizeof(int));
	int i=0,j=0;
	while(j<arrSize&&i<arrSize)
	{
		if(arr[i]==0)
		{
			p[j]=0;
			j++;
		}
		p[j++]=arr[i++];
	}
	memcpy(arr,p,sizeof(int)*arrSize);
}

