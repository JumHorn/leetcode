#include<vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
		if(nums.size()==1)
			return 0;
		int last=nums.size()-1;
		if(nums[0]<=nums[last])
		{
			for(int i=last-1;i>=0;i--)
				if(nums[i]<nums[i+1])
					return i+1;
		}
		else
		{
			for(int i=1;i<=last;i++)
				if(nums[i]<nums[i-1])
					return i-1;
		}
		return 0;
    }
};
