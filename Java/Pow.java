public class Pow 
{
	public double myPow(double x,int n)
	{
		if(n>=0)
		{
			return solution(x,n);
		}
		else 
		{
			return (1/solution(x,-n));
		}
	}
	public double solution(double x,int n)
	{
		int i;
		double sum=1;
		for(i=0;i<n;i++)
		{
			sum=x*sum;
			if(sum==0)
			{
				return 0;
			}
			if(sum==1)
			{
				return 1;
			}
			if(sum==Double.MAX_VALUE)
			{
				return Double.MAX_VALUE;
			}
		}
		return sum;
	}
}
