#include<vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.empty())
            return 1;
		for(int i=0;i<(int)nums.size();i++)
		{
			if(nums[i]==i+1||nums[i]<1||nums[i]>(int)nums.size())
				continue;
            if(nums[i]!=nums[nums[i]-1])
            {
			    swap(nums[i],nums[nums[i]-1]);
			    i--;
            }
		}
		for(int i=0;i<(int)nums.size();i++)
			if(nums[i]!=i+1)
				return i+1;
		return nums.size()+1;
    }
};
