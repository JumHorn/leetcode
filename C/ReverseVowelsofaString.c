#include<stdio.h>
#include<string.h>
int main()
{
	char * reverseVowels(char *s);
}
char* reverseVowels(char* s) {
	int temp[10000]={0};
	char  c;
	int i,j=0,len=strlen(s);
	int m=0,n=len-1;
	for(i=0;i<len;i++)
	{
		c=s[i];
		if(c>='A'&&c<='Z')c=c+0x20;
		if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
		{
			temp[i]=1;
			j++;
		}
	}
	for(i=0;i<j/2;i++)
	{
		if(temp[m]!=1)m++;
		if(temp[n]!=1)n--;

		c=s[m];
		s[m]=s[n];
		s[n]=c;

		m++;
		n--;
	}
	return s;
}
