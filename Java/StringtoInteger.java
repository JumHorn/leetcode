//INT_MAX 2147483647   INT_MIN -2147483648
public class StringtoInteger
{
	public int myAtoi(String str)
	{
		char[] array = str.toCharArray();
		long sum=0;
		int i,j,k;
		for(i=0;i<str.length();i++)
		{
			if(array[i]>='0'&&array[i]<='9')
			{
				if(i<2)
				{
					break;
				}

				else if(array[i-1]=='+'&&array[i-2]!='-')
				{
					break;
				}
				else if(array[i-1]=='-'&&array[i-2]!='+')
				{
					break;
				}
				else if(array[i-1]=='+'&&array[i-2]=='-')
				{
					return 0;
				}
				else if(array[i-1]=='-'&&array[i-2]=='+')
				{
					return 0;
				}
				else 
				{
					break;
				}


			}
		}
		if(array[i-1]==' ')
			for(k=0;k<i;k++)
			{
				if(array[k]=='+'||array[k]=='-')
				{
					return 0;
				}
			}

		if(i==str.length())
		{
			return 0;
		}
		else
		{
			for(j=i+1;j<str.length();j++)
			{
				if(array[j]>'9'||array[j]<'0')
				{
					break;
				}
			}
			j--;
			for(k=i;k<=j;k++)
			{
				sum=sum*10+array[k]-'0';
			}
			if(i>=1&&array[i-1]=='-')
			{
				if(-sum>-2147483648)
					return (int)-sum;
				else
					return -2147483648;
			}
			else
			{
				if(sum<=2147483647)
					return (int)sum;
				else
					return 2147483647;
			}
		}
	}
}
