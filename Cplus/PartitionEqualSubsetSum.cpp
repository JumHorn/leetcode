#include<vector>
#include<numeric>
#include<algorithm>
#include<functional>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
		int all=accumulate(nums.begin(),nums.end(),0);
		if(all&0x1)
			return false;
		all/=2;
		sort(nums.begin(),nums.end(),greater<int>());
		if(nums.front()>all)
			return false;
		return combination(nums,0,all);
    }

	bool combination(vector<int>& nums,int start,int all)
	{
		if(0==all)
			return true;
		if(all<0)
			return false;
		for(int i=start;i<(int)nums.size();i++)
			if(combination(nums,i+1,all-nums[i]))
				return true;
		return false;
	}
};
