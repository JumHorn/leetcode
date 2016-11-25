public class DivideTwoIntegers
{
	public int divide(int dividend, int divisor) {
		if(dividend==Integer.MIN_VALUE)
		{
			if(divisor==-1)
			{
				return Integer.MAX_VALUE;
			}

			else
			{
				if(divisor<0)
				{
					dividend=dividend-divisor;
					return divide(-dividend,-divisor)+1;
				}
				else
				{
					dividend=dividend+divisor;
					return -(divide(-dividend,divisor)+1);
				}
			}
		}
		if(divisor==1)
		{			 
			return dividend;
		}
		if(dividend>0&&divisor>0)
		{

			int sum=0;
			while(dividend-divisor>=0)
			{
				dividend=dividend-divisor;
				sum++;
				if(sum==Integer.MAX_VALUE)
					return sum;
			}
			return sum;
		}
		else if(dividend<0&&divisor<0)
		{
			return divide(-dividend,-divisor);
		}
		else if(dividend>0&&divisor<0)
		{
			return -divide(dividend,-divisor);
		}
		else if(dividend<0&&divisor>0)
		{
			return -divide(-dividend,divisor);
		}
		else
		{
			return 0;
		}
	}
}
