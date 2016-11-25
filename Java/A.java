import java.util.Scanner;
public class A
{
	public static void main(String[] args)
	{
		int n;
		char a='*',b='=';
		Scanner sc=new Scanner(System.in);
		print myprint=new print();
		triangle angle=new triangle();
		myprint.greeting();
		myprint.talking();
		n=sc.nextInt();
		System.out.println("\n");
		angle.angle(n);
	}  
}
class print
{
	void char_print(char a)
	{
		System.out.print(a);
	}
	void char_print(int a)
	{
		System.out.print(a);
	}
	void greeting()
	{	
		System.out.println("hello world");
	}
	void talking()
	{

		System.out.println("please input a number!");
	}

}
class triangle
{
	print angleprint=new print();
	void angle(int n)
	{
		int[] a=new int[10];
		int[] b=new int[10];
		int i=0,j=0;
		a[0]=1;
		while(true)
		{
			for(j=0;j<=i;j++)
			{	
				angleprint.char_print(a[j]);
				System.out.print(" ");
			}
			System.out.println();
			if(i>=n||i==9)break;
			b[0]=b[i+1]=1;
			for(j=1;j<=i;j++)
			{
				b[j]=a[j]+a[j-1];
			}
			for(j=0;j<=i+1;j++)
			{
				a[j]=b[j];
			}
			i++;
		}
	}
}

