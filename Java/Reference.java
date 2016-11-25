public class Reference
{
    public static void main(String[] args)
    {
        String A="123";
        String B=A;
        System.out.println(A);
        System.out.println(B);

        A="234";
        System.out.println(A);
        System.out.println(B);            
    }    
}