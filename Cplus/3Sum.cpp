#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> tmp(3);
		sort(nums.begin(),nums.end());
		threeSum(res,tmp,nums,0,3,0);
		return res;
    }

	void threeSum(vector<vector<int>>& res,vector<int>& tmp,vector<int>& nums,int start,int n,int target)
	{
		if(n==2)
		{
			int low=start,high=nums.size()-1;
			while(low<high)
			{
				int sum=nums[low]+nums[high]-target;
				if(sum==0)
				{
					tmp[0]=nums[low];
					tmp[1]=nums[high];
					res.push_back(tmp);
					while(++low<high&&nums[low]==nums[low-1]);
					while(low<--high&&nums[high]==nums[high+1]);
				}
				else if(sum<0)
					low++;
				else
					high--;
			}
			return;
		}
		for(int i=start;i<(int)nums.size();)
		{
			tmp[n-1]=nums[i];
			threeSum(res,tmp,nums,i+1,n-1,target-nums[i]);
			i++;
			while(i<(int)nums.size()&&nums[i]==nums[i-1])
				i++;
		}
	}
};
