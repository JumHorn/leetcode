#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
		int res=nums[0];
		for(int i=(int)nums.size()-1;i>0;i--)
			if(nums[i]-nums[i-1]<0)		
				res=min(res,nums[i]);
		return res;
    }
};
