#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int result;
    int countSubstrings(string s) {
        result = s.length();
        for(int i=2;i<=s.length();i++) //length
        {
            for(int j=i-1;j<s.length();j++)//index
            {
                result+=palindrom(s,j,i);
            }
        }
        return result;
    }

    int palindrom(string& s,int index,int length)
    {
        int i=index-length+1,j=index;
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return 0;
            }
            i++;
            j--;
        }
        return 1;
    }
};

//Manacher's Algorithm