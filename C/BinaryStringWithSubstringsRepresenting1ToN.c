#include<string.h>
#include<stdlib.h>

int toInt(char* S,int start,int end)
{
	int val=0,index=end;
	while(index>=start)
	{
		val|=((S[index]-'0')<<(end-index));
		--index;
	}
	return val;
}

bool queryString(char * S, int N){
	int len=strlen(S);
	char* p=(char*)malloc(N*sizeof(char));
	memset(p,0,N*sizeof(char));
	for(int i=0;i<len;i++)
		for(int j=i;j<len;j++)
		{
			if(j-i>31)
				break;
			int val=toInt(S,i,j);
			if(val>N)
				break;
			if(val>0)
				p[val-1]=1;
		}
	for(int i=0;i<N;i++)
		if(p[i]==0)
			return false;
	return true;
}

