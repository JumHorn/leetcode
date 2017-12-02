#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int maxsame=0,num,n=1;
        vector<int> maxnum;
        vector<int> temp = nums;
        sort(temp.begin(),temp.end());
        num=temp[0];
        maxnum.push_back(temp[0]);
        for(int i=1;i<temp.size();i++)
        {
            if(temp[i]==num)
            {
                n++;
            }
            else
            {
                if(n>maxsame)
                {
                    maxnum.clear();
                    maxsame=n;
                    maxnum.push_back(num);
                }
                else if(n==maxsame)
                {
                    maxnum.push_back(num);
                }
                n=1;
                num=temp[i];
            }
        }
        if(n>maxsame)
        {
            maxnum.clear();
            maxsame=n;
            maxnum.push_back(num);
        }
        else if(n==maxsame)
        {
            maxnum.push_back(num);
        }
        if(maxsame==1)
        {
            return 1;
        }
        int result=2147483647;
        for(int k=0;k<maxnum.size();k++)
        {
            int i,j;
            for(i=0;i<nums.size();i++)
            {
                if(nums[i]==maxnum[k])
                {
                    break;
                }
            }
            for(j=nums.size()-1;j>=0;j--)
            {
                if(nums[j]==maxnum[k])
                {
                    break;
                }
            }
            if(j-i+1<result)
            {
                result=j-i+1;
            }
        }
        return result;
    }
};