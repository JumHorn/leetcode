public class ZigZagConversion
{
	public String convert(String s,int numRows)
	{
		char[][] array = new char[numRows][500];
		StringBuilder str = new StringBuilder();
		char[] arr = s.toCharArray();
		int i=0,j=0,k=0;
		if(s.equals(""))return "";
		while(true)
		{
			for(j=0;j<numRows;j++)
			{
				array[j][k]=arr[i++];
				if(i==s.length())break;
			}
			if(i==s.length())break;
			for(j=j-2;j>0;j--)
			{
				k++;
				array[j][k]= arr[i++];
				if(i==s.length())break;
			}
			if(i==s.length())break;
			k++;
		}
		for(i=0;i<numRows;i++)
		{
			for(j=0;j<array[i].length;j++)
			{
				if(array[i][j]!='\0')
				{
					str.append(""+array[i][j]);
				}
			}
		}
		return str.toString();
	}
}
