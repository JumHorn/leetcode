#include<stdlib.h>
#define swap(a,b)if((a)!=(b))(a)^=(b)^=(a)^=(b)

char * largestTimeFromDigits(int* A, int ASize){
	char* res=(char*)malloc(sizeof(char)*(ASize+2));
	for(int i=0;i<ASize-1;i++)
		for(int j=0;j<ASize-1-i;j++)
			if(A[j]>A[j+1])
				swap(A[j],A[j+1]);
	res[0]='\0';
	if(A[0]>2)
		return res;
	if(A[0]==2)
	{
		if(A[1]>3||A[2]>5)
			return res;
	}
	else if(A[0]==1||A[0]==0)
	{
		if(A[1]>5)
			return res;
	}
	int B[4]={0};
	int i=3;
	while(A[i]>2)
		i--;
	res[0]=A[i]+'0';
	B[i]=-1;
label:
	i=3;
	while(true)
	{
		if(B[i]==-1||(res[0]=='2'&&A[i]>3))
			i--;
		else
		{
			res[1]=A[i]+'0';
			B[i]=-1;
			break;
		}
	}
	res[2]=':';
	i=3;
	while(i>=0&&(A[i]>5||B[i]==-1))
		i--;
	if(i<0)
	{
		B[1]=B[2]=B[3]=0;
		B[0]=-1;
		res[0]=A[0]+'0';
		goto label;
	}

	res[3]=A[i]+'0';
	B[i]=-1;

	i=3;
	while(B[i]==-1)
		i--;
	res[4]=A[i]+'0';
	res[5]='\0';
	return res;
}

