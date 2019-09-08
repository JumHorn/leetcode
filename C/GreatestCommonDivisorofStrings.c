#include<string.h>
#include<stdlib.h>
#include<limits.h>
#include<stdio.h>

int gcd(int x,int y)
{
	if(x==0)
		return y;
	return gcd(y%x,x);
}

bool divide(char* p,char* q,int len)
{
	int i=0;
	while(*p)
	{
		if(*p++!=q[i++%len])
			return false;
	}
	return true;
}

char * gcdOfStrings(char * str1, char * str2){
	int len1=strlen(str1),len2=strlen(str2);
	if(len1<len2)
	{
		int tmp=len1;
		len1=len2;
		len2=tmp;

		char* p=str1;
		str1=str2;
		str2=p;
	}
	char* res=(char*)calloc(sizeof(char),len2+1);
	int map1[26]={0},map2[26]={0};
	for(int i=0;i<len1;i++)
		map1[str1[i]-'A']++;
	for(int i=0;i<len2;i++)
		map2[str2[i]-'A']++;
	for(int i=0;i<26;i++)
	{
		if(map2[i]==0)
		{
			if(map1[i]!=0)
				return res;
		}
		else if(map1[i]<map2[i])
			return res;
	}
	int g=gcd(len1,len2);
	int s=INT_MAX;
	memcpy(res,str2,len2);
	for(int i=0;i<26;i++)
	{
		if(map2[i]!=0&&map2[i]<s)
			s=map2[i];
	}
	s=len2/s;
	for(int i=g;i>=s;i--)
	{
		if(len2%i==0)
		{
			if(len1%i==0&&divide(str2,str2,i)&&divide(str1,str2,i))
			{
				res[i]='\0';
				return res;
			}
		}
	}
	res[0]='\0';
	return res;
}

int main()
{
	char a[]="ABCABC";
	char b[]="ABC";
	printf("%s",gcdOfStrings(a,b));
	return 0;
}
