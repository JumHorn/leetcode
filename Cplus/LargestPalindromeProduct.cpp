#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

class Solution {
public:
    int largestPalindrome(int n) {
        long temp = pow(10,n),maxnum=0,multi;  
        for(int i=temp-1;i>=temp-1000;i--)
        {
            for(int j=temp-1;j>=temp-1000;j--)
            {
                multi = (long)i*j;
                if(IsPalindrome(multi))
                {
                    if(maxnum<multi)
                    {
                        maxnum = multi;
                    }
                }
            }
        }  
        return maxnum%1337;    
    }
    bool IsPalindrome(long num)
    {
        vector<char> str;
        while(num!=0)
        {
            str.push_back(num%10);
            num /= 10;
        }
        for(int i=0;i<str.size()/2;i++)
        {
            if(str[i]!=str[str.size()-i-1])
            {
                return false;
            }
        }
        return true;
    }
    // false method to judge palindrome 900099
    // bool IsPalindrome(long num)
    // {
    //     if(num<10)
    //     {
    //         return true;
    //     }
    //     int i,temp=10,head,tail;
    //     for(i=1;i<17;i++)
    //     {
    //         head = num/temp;
    //         if(head<10)
    //         {
    //             break;
    //         }
    //         temp *= 10;
    //     }
    //     tail = num%10;
    //     if(head==tail)
    //     {
    //         num %= temp;
    //         num /= 10;
    //         return IsPalindrome(num);
    //     }
    //     return false;
    // }
};

class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;
        int upper = pow(10, n) - 1;
        int lower = pow(10, n-1);
        for (int i = upper; i >= lower; i--) {
            long cand = buildPalindrome(i);
            for (long j = upper; j*j >= cand; j--) {
                if (cand % j == 0 && cand / j <= upper) {
                    cout<<cand<<endl;
                    return cand % 1337;
                }
            }
        }
        return -1;
    }

    long buildPalindrome(int n) {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        return stol(to_string(n) + s);
    }
}; 

int main()
{
    Solution sol;
    if(sol.IsPalindrome(900099))
    {
        cout<<"palindrome"<<endl;
    }
}