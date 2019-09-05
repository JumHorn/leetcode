#include<stdio.h>
#include<stdlib.h>

bool Equiv(int** dominoes,int i,int j)
{
	return dominoes[i][0]==dominoes[j][0]&&dominoes[i][1]==dominoes[j][1];
}

int comp(const void* lhs,const void* rhs)
{
	int* a=*(int**)lhs;
	int* b=*(int**)rhs;
	if(a[0]!=b[0])
		return a[0]-b[0];
	return a[1]-b[1];
}

int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize){
	int res=0;
    for(int i=0;i<dominoesSize;i++)
    {
        if(dominoes[i][0]>dominoes[i][1])
        {
            dominoes[i][0]^=dominoes[i][1];
            dominoes[i][1]^=dominoes[i][0];
            dominoes[i][0]^=dominoes[i][1];
        }
    }
	qsort(dominoes,dominoesSize,sizeof(int*),comp);
	for(int i=0;i<dominoesSize-1;)
	{
		int j=i+1;
		while(j<dominoesSize&&Equiv(dominoes,i,j))
			j++;
		if(j-i>1)
			res+=(j-i)*(j-i-1)/2;
		i=j;
	}
	return res;
}