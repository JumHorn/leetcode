public class FindtheDifference
{
	public static void main(String[] args)
	{
		new FindtheDifference();
	}
	public char solution()
	{

		String s = new String();
		String t = new String();
		int i=0;
		char[] array_s=s.toCharArray();
		char[] array_t=t.toCharArray();
		for(char c:array_t)
		{
			if(c!=array_s[i++]&&i<array_s.length)
			{
				return c;
			}
		}
		return array_t[array_t.length-1];
	}
}
