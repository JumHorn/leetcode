public class FindtheDifference_low
{
	public static void main(String[] args)
	{
		new FindtheDifference_low();
	}
	public char solution()
	{
		String s=new String();
		String t=new String();
		char[] array_s=s.toCharArray();
		char[] array_t=t.toCharArray();
		int i=0,j=0;
		int[] array = new int[array_s.length];
		for(i=0;i<array_s.length;i++)
		{
			array[i]=0;
		}
		for(i=0;i<array_t.length;i++)
		{
			for(j=0;j<array_s.length;j++)
			{
			    if(array[j]==1)
			    {
			        continue;
			    }
				if(array_t[i]==array_s[j])
				{
					array[j]=1;
					break;
				}

			}
			if(j==array_s.length)
			{
				return array_t[i];
			}
		}
		return ' ';
	}
}
