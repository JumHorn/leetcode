#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.empty())
        {
            return 0;
        }
        int result=0,sum=1,temp=0;
        for(int i=1;i<chars.size();i++)
        {
            if(chars[temp]==chars[i])
            {
                sum++;
            }
            else
            {
                if(sum==1)
                {
                    result++;
                }
                else 
                {
                    result = result+to_string(sum).size()+1;
                    string s=to_string(sum);
                    int j;
                    for(j=0;j<s.size();j++)
                    {
                        chars[temp+1+j]=s[j];
                    }
                    chars.erase(chars.begin()+temp+j+1,chars.begin()+i);
                    i=temp+j+1;
                }
                temp=i;
                sum=1;
            }
        }
        if(sum==1)
        {
            return result+1;
        }
        else 
        {
            string s=to_string(sum);
            for(int j=0;j<s.size();j++)
            {
                chars[temp+1+j]=s[j];
            }
            return result+to_string(sum).size()+1;
        }
    }
};