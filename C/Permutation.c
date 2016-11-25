#include<stdio.h>
#include<string.h>
void swap(char *a,char *b);
int main()
{
	void permutation(char *s,int start);
	char a[]="1234";
	permutation(a,0);
}
void permutation(char *s,int start)
{
	int i;
	if(start==strlen(s)-1)
	{
		printf("%s\n",s);
	}
	for(i=start;i<strlen(s);i++)
	{
		swap(&s[start],&s[i]);
		permutation(s,start+1);
		swap(&s[start],&s[i]);     //no need to swap
	}
}
void swap(char * a,char * b)
{
	char temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
