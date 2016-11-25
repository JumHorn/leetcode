import java.util.*;
public class leetcode1
{
	public static void main(String[] args)
	{
		int m=1,n,p=0,i=0;
		int[] array=new int[10000];
		Scanner sc = new Scanner(System.in);
		System.out.println("please enter a number");
		n=sc.nextInt();
		for(i=0;i<=n;i++)
		{
			array[i]=0;
		}
		i=0;
		while(true)
		{
			if(array[m]==0)
			{
				i=i%3+1;
				if(i==3)
				{
					array[m]=1;
					p++;
					System.out.print(m+"  ");
				}
			}
			if(m==n)
				m=1;
			else
				m++;

			if(p==n)break;
		}
		System.out.println();
	}
}
