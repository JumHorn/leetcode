#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(nums.size()==0)
        {
            return 0;
        }
        sort(nums.begin(),nums.end());
        if(k==0)
        {
            int temp = nums[0],same=0;
            for(int i=1;i<nums.size();i++)
            {
                if(temp==nums[i])
                {
                    same++;
                    while(i<nums.size()&&temp==nums[i])
                        i++;
                    if(i==nums.size())
                    {
                        break;
                    }
                }
                temp=nums[i];
            }
            return same;
        }
        if(k<0)return 0;
        int temp = nums[0];
        vector<int> numscopy;
        numscopy.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(temp!=nums[i])
            {
                numscopy.push_back(nums[i]);
                temp=nums[i];
            }
        }
        int subtractor=0,result=0;
        for(int i=1;i<numscopy.size();i++)
        {
            if(numscopy[i]-numscopy[subtractor]==k)
            {
                result++;
                subtractor++;
            }
            else if(numscopy[i]-numscopy[subtractor]>k)
            {
                subtractor++;
                i--;
            }
        }
        return result;
    }
};