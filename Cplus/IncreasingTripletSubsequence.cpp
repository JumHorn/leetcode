#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
		int one=INT_MAX,two=INT_MAX;
		for(int i=0;i<(int)nums.size();i++)
		{
			if(nums[i]>two)
				return true;
			if(nums[i]>one)
				two=nums[i];
			else
				one=min(one,nums[i]);
		}
		return false;
	}
};
