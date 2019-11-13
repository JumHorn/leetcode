#include<string.h>
#include<stdlib.h>

#define swap(a,b) if((a)!=(b))((a)^=(b)^=(a)^=(b))

int dfs(char* s,int start)
{
	int res=1;
	char alpha[26]={0};
	for(int i=start;s[i];i++)
	{
		if(alpha[s[i]-'A']!=0)
			continue;
		alpha[s[i]-'A']=1;
		swap(s[i],s[start]);
		res+=dfs(s,start+1);
		swap(s[i],s[start]);
	}
	return res;
}

int numTilePossibilities(char * tiles){
	return dfs(tiles,0)-1;
}
