#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int main()
{
	char * reverseVowels(char *s);
	bool check(char c);
}
bool check(char c)
{

	if(c>='A'&&c<='Z')c=c+0x20;
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
	{
		return true;
	}
	return false;

}
char * reverseVowels(char *s)
{
	char  c;
	int i,j=0,len=strlen(s);
	int m=0,n=len-1;

	while(m<n)
	{
		while(!check(s[m])&&m<n)m++;
		while(!check(s[n])&&m<n)n--;

		c=s[m];
		s[m]=s[n];
		s[n]=c;

		m++;
		n--;
	}
	return s;
}
