#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;        
		vector<int> tmp;
		sort(nums.begin(),nums.end());
		threeSum(res,tmp,nums,0,0,3,0);
		return res;
    }

	void threeSum(vector<vector<int>>& res,vector<int>& tmp,vector<int>& nums,int start,int sum,int n,int target)
	{
		if((int)tmp.size()==n)
		{
			if(sum==target)
				res.push_back(tmp);
			return;
		}
		for(int i=start;i<(int)nums.size();i++)
		{
			tmp.push_back(nums[i]);
			threeSum(res,tmp,nums,i+1,sum+nums[i],n,target);
			tmp.pop_back();
			while(i>0&&i<(int)nums.size()&&nums[i]==nums[i-1])
				i++;
		}
	}
};
