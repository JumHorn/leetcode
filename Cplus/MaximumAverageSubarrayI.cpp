#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double result,temp=0;
        for(int i=0;i<k;i++)
        {
            temp+=nums[i];
        }
        result=temp;
        for(int i=k;i<nums.size();i++)
        {
            temp=temp+nums[i]-nums[i-k];
            if(temp>result)
            {
                result=temp;
            }
        }
        return result/k;
    }
};