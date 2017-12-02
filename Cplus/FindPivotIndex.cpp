#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size()==0)
        {
            return -1;
        }
        if(nums.size()==1)
        {
            return 0;
        }
        int leftsum=0,rightsum=accumulate(nums.begin(),nums.end(),0)-nums[0],provit=0;
        while(provit<nums.size())
        {
            if(leftsum==rightsum)
            {
                return provit;
            }
            leftsum+=nums[provit];
            provit++;
            rightsum-=nums[provit];
        }
        return -1;
    }
};