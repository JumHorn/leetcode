#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
		int all=accumulate(nums.begin(),nums.end(),0);
		if(all&0x1)
			return false;
		all/=2;
		return combination(nums,0,0,all);
    }

	bool combination(vector<int>& nums,int tmp,int start,int all)
	{
		if(tmp==all)
			return true;
		if(tmp>all)
			return false;
		for(int i=start;i<(int)nums.size();i++)
		{
			tmp+=nums[i];
			if(combination(nums,tmp,i+1,all))
				return true;
			tmp-=nums[i];
		}
		return false;
	}
};
