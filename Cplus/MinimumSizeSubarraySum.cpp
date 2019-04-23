#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
		int res=0,l=0,r=nums.size();
		while(l<=r)
		{
			int tmp=(r-l)/2+l;
			int all=accumulate(nums.begin(),nums.begin()+tmp,0);
			if(all>=s)
			{
				res=tmp;
				r=tmp-1;
				continue;
			}
			int i=0;
			for(i=1;i<nums.size()-tmp+1;i++)
			{
				all=all-nums[i-1]+nums[i+tmp-1];
				if(all>=s)
				{
					res=tmp;
					r=tmp-1;
					break;
				}
			}
			if(i==nums.size()-tmp+1)
			{
				l=tmp+1;
			}
		}
		return res;
    }
};
