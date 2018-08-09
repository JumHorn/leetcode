#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
		int max=0;
		for(int i=0;i<nums.size()-1;i++)
		{
			for(int j=i+1;j<nums.size();j++)
			{
				if((nums[i]^nums[j])>max)
					max=(nums[i]^nums[j]);
			}
		}		
		return max;
    }
};

