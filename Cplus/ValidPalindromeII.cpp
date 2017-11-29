#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int r,l,flag=0;
        l=0;
        r=s.size()-1;
        while(l<r)
        {
            if(s[r]!=s[l])
            {
                if(flag==1)
                {
                    break;
                }
                l++;
                flag=1;
                continue;
            }
            l++;
            r--;
        }
        if(l>=r)
        {
            return true;
        }
        l=0;
        r=s.size()-1;
        while(l<r)
        {
            if(s[r]!=s[l])
            {
                if(flag==0)
                {
                    return false;
                }
                r--;
                flag=0;
                continue;
            }
            l++;
            r--;
        }
        return true;
    }
};