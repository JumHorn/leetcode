#include<stdlib.h>
#include<string.h>

int findJudge(int N, int** trust, int trustSize, int* trustColSize){
	int *people=(int*)calloc(sizeof(int),N),judge=0;
	for(int i=0;i<trustSize;i++)
		people[trust[i][0]-1]=1;
	for(int i=0;i<N;i++)
		if(people[i]==0)
		{
			if(judge==0)
				judge=i+1;
			else
				return -1;
		}
	memset(people,0,N*sizeof(int));
	for(int i=0;i<trustSize;i++)
	{
		if(trust[i][1]==judge)
			people[trust[i][0]-1]=1;
	}
	int count=0;
	for(int i=0;i<N;i++)
		if(people[i]==0&&++count>=2)
			return -1;
	return judge;
}

