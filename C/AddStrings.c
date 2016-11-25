#include<stdio.h>
#include<string.h>
char a[5100];
int main()
{
	char * addStrings(char *num1,char *num2);
	char a[]="99",b[]="1";
	printf("%s\n",addStrings(a,b));
}

char * addStrings(char *num1,char *num2)
{
	char *p;
	//a[5100]='\0';
	int num1_len,num2_len,i,j,t,k=5099,c=0;//c stand for carry
	num1_len=strlen(num1);
	num2_len=strlen(num2);
	i=num1_len-1;
	j=num2_len-1;
	while(i>=0&&j>=0)
	{
		t=num1[i]-'0'+num2[j]-'0'+c;
		c=t/10; printf("%d\n",c);
		a[k]=t%10+'0';printf("%c\n",a[k]);

		k--;
		i--;
		j--;
	}
	if(i<0&&j>=0)
	{
		while(j>=0)
		{
			t=num2[j]-'0'+c;
			c=t/10;printf("%d\n",c);
			a[k]=t%10+'0';printf("%c\n",a[k]);

			k--;
			j--;
		}
	}
	if(i>=0&&j<0)
	{
		while(i>=0)
		{
			t=num1[i]-'0'+c;
			c=t/10;
			a[k]=t%10+'0';

			k--;
			i--;
		}
	}
	if(i<0&&j<0)
	{
		if(c==1)
		{
			a[k]='1';printf("%c\n",a[k]);
		}
		else
		{
			k++;
		}
	}
	p=&a[k];
	return p;
}
