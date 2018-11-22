#include<vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
		if(nums.size()==1)
			return nums[0];
 		int res=nums[0];
		for(int i=1;i<nums.size();i++)
		{
			if(nums[i]<nums[i-1])
				return min(nums[i],res);
		}
		return res;
    }
};
