#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int minus=0;
        if(nums.size()<3)
        {
            return true;
        }
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-nums[i-1]<0)
            {
                minus++;
                if(minus==2)
                {
                    return false;
                }
                if(i-1==0||nums[i]-nums[i-2]>=0)
                {
                    continue;
                }
                else
                {
                    if(i!=nums.size()-1&&nums[i+1]-nums[i-1]<0)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};