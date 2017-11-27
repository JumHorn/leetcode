#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted = nums;
        int i,j;
        sort(sorted.begin(),sorted.end());
        for(i=0;i<nums.size();i++)
        {
            if(sorted[i]!=nums[i])
            {
                break;
            }
        }
        if(i==nums.size())
        {
            return 0;
        }
        for(j=nums.size()-1;j>=0;j--)
        {
            if(sorted[j]!=nums[j])
            {
                break;
            }
        }
        return j-i+1;
    }
};