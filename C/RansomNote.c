#include<stdio.h>
#include<stdbool.h>
#include<string.h>
void main()
{
	bool canConstruct(char * ransomNote,char * magazine);
        char a[]="bg",b[]="efjbdfbdgfjhhaiigfhbaejahgfbbgbjagbddfgdiaigdadhcfcj";
        printf("%d\n",canConstruct(a,b));
}

bool canConstruct(char * ransomNote,char * magazine)
{
	int ransomNote_len=strlen(ransomNote);
	int magazine_len=strlen(magazine);printf("%d,%d\n",ransomNote_len,magazine_len);
	int i,j;
	for(i=0;i<ransomNote_len;i++)
	{
		for(j=0;j<magazine_len;j++)
		{
			if(ransomNote[i]==magazine[j])
			{
				magazine[j]=0;
				break;
			}
		}
		if(j==magazine_len)
		{
			break;
		}
	}
	if(i==ransomNote_len)
	{
		return true;
	}
	else
	{
		return false;
	}
}
