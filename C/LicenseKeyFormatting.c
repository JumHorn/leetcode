#include<ctype.h>
#include<string.h>
#include<stdlib.h>

char * licenseKeyFormatting(char * S, int K){
	int count=0;
	for(int i=0;i<(int)strlen(S);i++)
	{
		if(S[i]!='-')
			count++;
		S[i]=(char)toupper(S[i]);
	}
    if(count==0||K==0)
        return "";
	int first=count%K;
	if(first==0)
		first=K;
	char* p=(char*)malloc((count+count/K+(count%K?0:-1)+1)*sizeof(char));
	int i=0,j=0,k=K;
	while(j<first)
	{
		if(S[i]!='-')
			p[j++]=S[i];
		i++;
	}
	while(i<(int)strlen(S))
	{
		if(S[i]!='-')
		{
            if(k==K)
            {
                p[j++]='-';
                k=0;
            }
			p[j++]=S[i];
			k++;
		}
		i++;
	}
	p[j]='\0';
	return p;
}