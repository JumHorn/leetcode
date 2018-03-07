#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        int temp;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
            {
                temp=nums[i]-1;
                if(nums[temp]==0)
                {
                    result.push_back(nums[i]);
                    nums[temp]=-1;
                }
                else if(nums[temp]>0)
                {
                    nums[i]=nums[temp];
                    nums[temp]=0;
                    i--;
                }
            }
        }
        return result;
    }
};