public class ReverseWordsinaString
{
	public String reverseWords(String s)
	{
		        int i,j,k;
		i=j=s.trim().length()-1;
		StringBuilder sb = new StringBuilder();
		char[] array = s.trim().toCharArray();
		while(j>=0)
		{
			for(j=i;j>=0;j--)
			{
				if(!Character.isWhitespace(array[j]))
				{
					i=j;
					break;
				}
			}
			for(j=j-1;j>=0;j--)
			{
				if(Character.isWhitespace(array[j]))
				{
					break;
				}
			}
			if(j>=0||(!Character.isWhitespace(array[0])&&j==-1))
			{
				for(k=j+1;k<=i;k++)
				{
					sb.append(""+array[k]);
				}
				sb.append(" ");
				i=j;
			}
		}
		return sb.toString().trim();
	}
}
