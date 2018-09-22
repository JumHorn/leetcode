#include<vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
		for(int i=0;i<nums.size()-1;i++)
		{
			for(int j=i+1;j<nums.size();j++)
			{
				if((nums[i]^nums[j])==0)
				{
					return nums[i];
				}
			}
		}
    }
};
