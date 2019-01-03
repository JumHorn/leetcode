#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
		vector<vector<int> > res;
		permute(res,nums,0);
		return res;
    }

	void permute(vector<vector<int> >& res,vector<int>& nums,int start)
	{
		if(start==nums.size())
			if(find(res.begin(),res.end(),nums)==res.end())
				res.push_back(nums);
		for(int i=start;i<nums.size();i++)
		{
			swap(nums[i],nums[start]);
			permute(res,nums,start+1);
			swap(nums[i],nums[start]);
		}
	}
};
