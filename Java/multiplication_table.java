import java.util.Scanner;
public class multiplication_table
{
	public static void main(String[] args)
	{
		Scanner sc=new Scanner(System.in);
		int n,i,j;
		System.out.println("please enter a number!");
		n=sc.nextInt();
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=i;j++)
			{
				System.out.print(j+"*"+i+"="+i*j+" ");
			}
			System.out.println();
		}
	}
}
