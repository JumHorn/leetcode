#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        if(s.length()==0)
        {
            return 0;
        }
        vector<int> sum;
        int temp=1;
        char flag=s[0];
        for(int i=1;i<s.length();i++)
        {
            if(s[i]==flag)
            {
                temp++;
            }
            else
            {
                flag=s[i];
                sum.push_back(temp);
                temp=1;
            }
        }
        sum.push_back(temp);

        int ans=0;
        for(int i=1;i<sum.size();i++)
        {
            ans+=sum[i]>sum[i-1]?sum[i-1]:sum[i];
        }
        return ans;
    }
};