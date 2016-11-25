public class BitCount
{
	public static void main(String[] args)
	{
		System.out.println(new BitCount().bitcount(2147483647));
	}
	private int bitcount(int i)
	{
		i = i - ((i >>> 1) & 0x55555555);  
		System.out.println(i);
		i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);  
		System.out.println(i);
		i = (i + (i >>> 4)) & 0x0f0f0f0f;  
		System.out.println(i);
		i = i + (i >>> 8);  
		System.out.println(i);
		i = i + (i >>> 16);  
		System.out.println(i);
		return i & 0x3f;  
	}
}
