public class PalindromeNumber
{
	public boolean isPalindrome(int x)
	{
		int[] array = new int[11];
		int i=1,j=0;
		if(x==0)
		{
			return true;
		}
		else 
		{
			while(x!=0)
			{
				array[i++]=x%10;
				x=x/10;
			}
		}
		if(array[1]<0)
		{
			array[j++]=0;
		}
		i--;
		while(i-j>1)
		{
			if(array[i]!=array[j])
			{
				return false;
			}
			i--;
			j++;
		}
		if(i==j)
		{
			return true;
		}
		return true;
	}
}

//testing -2147447412
