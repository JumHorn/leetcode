#include<ctype.h>
#include<string.h>
#include<stdlib.h>

char * licenseKeyFormatting(char * S, int K){
	int count=0;
    int len=strlen(S);
	for(int i=0;i<len;i++)
	{
		if(S[i]!='-')
			count++;
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
			p[j++]=toupper(S[i]);
		i++;
	}
	while(i<len)
	{
		if(S[i]!='-')
		{
            if(k==K)
            {
                p[j++]='-';
                k=0;
            }
			p[j++]=toupper(S[i]);
			k++;
		}
		i++;
	}
	p[j]='\0';
	return p;
}