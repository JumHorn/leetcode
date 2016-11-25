#include<stdio.h>
#include<stdbool.h>
#include<string.h>
int main()
{
	bool isAnagram(char *s,char *t);
}

bool isAnagram(char *s,char *t)
{
	int s_len,t_len,i,j;
	s_len=strlen(s);
	t_len=strlen(t);
	if(s_len!=t_len)
	{
		return false;
	}
	for(i=0;i<s_len;i++)
	{
		for(j=0;j<t_len;j++)
		{
			if(s[i]==t[j])
			{
				t[j]='\0';
				break;
			}
		}
		if(j==t_len)
		{
			return false;
		}
	}
	return true;
}
