import java.util.ArrayList;
import java.util.List;
public class BinaryWatch
{
	public List<String> readBinaryWatch(int num)
	{
		List<String> ls = new ArrayList<String>();
		int h,m;
		for(h=0;h<12;h++)
		{
			for(m=0;m<60;m++)
			{
				if(Integer.bitCount(h)+Integer.bitCount(m)==num)
				{
					ls.add(String.format("%d:%02d",h,m));
				}
			}
		}
		return ls;
	}
}
