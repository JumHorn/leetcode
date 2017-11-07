#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int countSegments(string s) {
        int result=0;
        int flag=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=' ')
            {
                flag=1;
                continue;
            }
            else
            {
                if(flag==1)
                {
                    result++;
                    flag=0;
                }
            }
        }
        return result+flag;
    }
};

//有些语言内置函数，可以比较速度