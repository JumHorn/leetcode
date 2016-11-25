#include<stdio.h>
#include<string.h>
int main()
{
	int longestPalindrome(char *s);
	char a[]="zeusnilemacaronimaisanitratetartinasiaminoracamelinsuez";
        printf("%d\n",longestPalindrome(a));
	printf("\n");
}

int longestPalindrome(char *s)
{	
	int statistics[58]={0};
	int len=strlen(s),i,result=0;
	for(i=0;i<len;i++)
	{
		statistics[s[i]-'A']++;
	}
	for(i=0;i<58;i++)
	{
		printf("%d\t",statistics[i]);
		if(statistics[i]%2==0)
			result+=statistics[i];
		else
			result+=statistics[i]-1;
	}
	for(i=0;i<26;i++)
	{
		if(statistics[i]%2==1)
		{
			result+=1;
			break;
		}
		if(statistics[i+32]%2==1)
		{
			result+=1;
			break;
		}
	}
	return result;
}
