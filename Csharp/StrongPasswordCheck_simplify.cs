using System;
using System.Collections.Generic;
public class StrongPasswordChecker
{
    public int strongPasswordChecker(string s)
    {
        char[] pwd;
        int len,temp=0,t=0;
        pwd=s.ToCharArray();
        len=s.Length;
        if(len<6)
        {
            temp=6-len;
            t=number_check(pwd)+uppercase_check(pwd)+lowercase_check(pwd);
            return temp>=t?temp:t;
        }
        if(len<21)
        {
            temp=repeat_check(pwd);
            t=number_check(pwd)+uppercase_check(pwd)+lowercase_check(pwd);
            return temp>=t?temp:t;
        }
        else
        {
            List<int> repeat = new List<int>();
            int i=0,j;
            t=number_check(pwd)+uppercase_check(pwd)+lowercase_check(pwd);
            while(i<s.Length-1)
            {
                j=i+1;
                while(j<s.Length)
                {
                    if(s[i]==s[j])
                    {
                        j++;
                    }
                    else
                    {
                        break;
                    }
                }
                if(j-i>2)
                {
                    repeat.Add(j-i);
                }
                i=j;
            }
            int delete=len-20;
            repeat.Sort();
            for(int m=0;m<repeat.Count;m++)
            {
                if(delete>=(repeat[m]%3+1))
                {
                    delete-=1+repeat[m]%3;
                    repeat[m]-=1+repeat[m]%3;
                }
                if(delete==0)
                {
                    break;
                }
            }   
            Console.WriteLine(repeat[0]+" "+delete);
            if(delete>0)
            {
                for(int n=0;n<repeat.Count;n++)
                {
                    while(repeat[n]>2)
                    {
                        if(delete>2)
                        {
                            repeat[n]-=3;
                            delete-=3;
                        }
                        else
                        {
                            repeat[n]-=delete;
                            delete=0;
                        }
                        if(delete==0)
                        {
                            break;
                        }
                    }
                    if(delete==0)
                    {
                        break;
                    }
                }
            }
            foreach (var item in repeat)
            {
                temp+=item/3;
            }           
            return len-20+(temp>t?temp:t);
        }
    }
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
        string s = "aaaaaa1234567890123Ubefg";
        StrongPasswordChecker sp = new StrongPasswordChecker {};
        Console.WriteLine(sp.strongPasswordChecker(s));
    }
}