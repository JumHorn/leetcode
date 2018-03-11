#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(),0);
        vector<int> leftdays;
        if(temperatures.size()==1)
        {
            return result;
        }
        for(int i=1;i<temperatures.size();i++)
        {
            if(temperatures[i]>temperatures[i-1])
            {
                result[i-1]=1;
                for(int j=leftdays.size()-1;j>=0;j--)
                {
                    if(temperatures[i]>temperatures[leftdays[j]])
                    {
                        result[leftdays[j]]=i-leftdays[j];
                        leftdays.pop_back();
                    }
                }
            }
            else
            {
                leftdays.push_back(i-1);
            }
        }
        return result;
    }
};


//time limit exceeded
class Solution0 {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(),0);
        if(temperatures.size()==1)
        {
            return result;
        }
        for(int i=1;i<temperatures.size();i++)
        {
            if(temperatures[i]>temperatures[i-1])
            {
                result[i-1]=1;
                for(int j=i-2;j>=0;j--)
                {
                    if(result[j]==0&&temperatures[i]>temperatures[j])
                    {
                        result[j]=i-j;
                    }
                }
            }
        }
        return result;
    }
};