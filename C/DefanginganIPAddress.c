#include<string.h>
#include<stdlib.h>

char * defangIPaddr(char * address){
	int len=strlen(address);
	int j=0;
	char* p=(char*)malloc(sizeof(char)*(len+7));
	for(int i=0;i<len+7;)
	{
		if(address[j]=='.')
		{
			p[i]='[';
			p[i+1]='.';
			p[i+2]=']';
			i+=3;
		}
		else
			p[i++]=address[j];
		j++;
	}
	p[len+6]='\0';
	return p;
}

