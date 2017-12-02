#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for(int i=left;i<=right;i++)
        {
            if(Dividing(i))
            {
                result.push_back(i);
            }
        }
        return result;
    }
    bool Dividing(int i)
    {
        if(i==0)
        {
            return false;
        }
        int m=i,n=i%10;
        while(m!=0)
        {
            if(n==0)
            {
                return false;
            }
            if(i%n!=0)
            {
                return false;
            }
            m=m/10;
            n=m%10;
        }
        return true;
    }
};