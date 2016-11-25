#include<stdio.h>
#include<string.h>
int main()
{
	int titleToNumber(char *s);
}

int titleToNumber(char *s)
{
	int i,len,result=0,carry=1;
	len=strlen(s);
	for(i=0;i<len-1;i++)
	{
		carry=carry*26;
	}
	for(i=0;i<len;i++)
	{
		result=result+(*s-'A'+1)*carry;
		s++;
		carry=carry/26;
	}
	return result;
}
