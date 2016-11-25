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
	int frequence[26]={0};
	s_len=strlen(s);
	t_len=strlen(t);
	if(s_len!=t_len)
	{
		return false;
	}
	for(i=0;i<s_len;i++)
	{
		frequence[s[i]-'a']++;
	}
	for(j=0;j<t_len;j++)
	{
		if(--frequence[t[j]-'a']<0)
		{
			return false;
		}
	}
	return true;
}
