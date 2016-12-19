public class StrongPasswordChecker
{
    public int strongPasswordChecker(string s)
    {
        char[] pwd;
        int len,temp,t;
        pwd=s.ToCharArray();
        len=s.Length;
        if(len<6)
        {
            temp=6-len;
            t=number_check(pwd)+uppercase_check(pwd)+lowercase_check(pwd);
            if(temp>=t)
            {
                return temp;
            }
            else
            {
                return t;
            }
        }
        if(len<21)
        {
            temp=repeat_check(pwd);
            t=number_check(pwd)+uppercase_check(pwd)+lowercase_check(pwd);
            if(temp>=t)
            {
                return temp;
            }
            else
            {
                return t;
            }
        }
        else
        {
            temp=repeat_check(pwd);
            t=number_check(pwd)+uppercase_check(pwd)+lowercase_check(pwd);
            if(temp>t)
            {
                int i=0,t1=0,k,k1=temp;
                while(i<s.Length-3)
                {
                    if(s[i]==s[i+1]&&s[i]==s[i+2])
                    {
                        if(s[i+3]==s[i])
                        {
                            k=i;
                            i++;
                            while(i<s.Length-3&&s[i]==s[i+3])
                            {
                                i++;
                            }
                            t1+=(i+3-k)/3;
                            k1--;
                        }
                        i+=3;
                        continue;
                    }
                    i++;
                }
                return len-20+Math.Max(3-t,t1+k1);
            }
            else
            {
                return t+len-20;
            }
        }
        // return 0;
    }
    // public int length_check(int s)
    // {
    //     if( s<6 || s>20 )
    //     {
    //         return 1;
    //     }
    //     return 0;
    // }
    public int repeat_check(char[] s)
    {   
        int i=0,t=0;
        while(i<s.Length-2)
        {
            if(s[i]==s[i+1]&&s[i]==s[i+2])
            {
                t++;
                i+=3;
                continue;
            }
            i++;
        }
        return t;
    }
    public int number_check(char[] s)
    {
        int i=0;
        for(i=0;i<s.Length;i++)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                return 0;
            }
        }
        return 1;
    }
    public int uppercase_check(char[] s)
    {
        int i=0;
        for(i=0;i<s.Length;i++)
        {
            if(s[i]>='A'&&s[i]<='Z')
            {
                return 0;
            }
        }
        return 1;   
    }
    public int lowercase_check(char[] s)
    {
        int i=0;
        for(i=0;i<s.Length;i++)
        {
            if(s[i]>='a'&&s[i]<='z')
            {
                return 0;
            }
        }
        return 1;   
    }
    static void Main(string[] args)
    {
    }
}