public class CompareVersionNumbers
{
	public int compareVersion(String version1,String version2)
	{
		int i=0,j=0,m=0,n=0;
		char[] array1 = version1.toCharArray();
		char[] array2 = version2.toCharArray();
		while(i<array1.length&&j<array2.length)
		{
			while(i<array1.length&&array1[i]!='.')
				i++;     
			while(j<array2.length&&array2[j]!='.')
				j++;
			if(chartoInteger(array1,m,i)>chartoInteger(array2,n,j))
			{
				return 1;
			}
			else if(chartoInteger(array1,m,i)<chartoInteger(array2,n,j))
			{
				return -1;
			}
			else
			{
				if(i<array1.length)
					m=++i;
				if(j<array2.length)
					n=++j;
			}
		}
		if(i==array1.length&&j<array2.length)
		{
			if(check(array2,j))
				return 0;
			else
				return -1;
		}
		else if(i<array1.length&&j==array2.length)
		{ 
			if(check(array1,i))
				return 0;
			else 
				return 1;
		}
		else 
		{
			return 0;
		}
	}
	public int chartoInteger(char[] array,int i,int j)
	{
		int sum=0,k;
		for(k=i;k<j;k++)
		{
			sum=sum*10+array[k]-'0';
		}
		return sum;
	}
	public boolean check(char[] array,int i)
	{
		while(i<array.length)
		{
			if(array[i]!='0'&&array[i]!='.')
			{
				return false;
			}
			i++;
		}
		return true;
	}
}
