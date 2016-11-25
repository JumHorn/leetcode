#include<stdio.h>
#include<string.h>
int main()
{
	int romanToInt(char *s);
}

int romanToInt(char *s)
{

	int map[100];
	map['I']=1;
	map['V']=5;
	map['X']=10;
	map['L']=50;
	map['C']=100;
	map['D']=500;
	map['M']=1000;
	int len=strlen(s);
	int i,j,result=0,flag;
	for(i=0;i<len-1;i++)
	{
		j=i+1;
		switch(s[j]-s[i])
		{
			case 13:;
			case 15 :;
			case -12:;
			case -21:;
			case 1:;
			case 10:if(s[i]=='I'||s[i]=='C'||s[i]=='X'){result+=map[s[j]]-map[s[i]];i++;flag=0;break;}
			default :result+=map[s[i]];flag=1;break;
		}
	}
	if(i==len-1&&flag!=1)
	{
		result+=map[s[i]];
	}
	if(flag==1)
	{
		result+=map[s[j]];
	}
	return result;
}
