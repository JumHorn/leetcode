#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
		vector<vector<int> > res;
		sort(nums.begin(),nums.end());
		permute(res,nums,0);
		return res;
    }

	void permute(vector<vector<int> >& res,vector<int> nums,int start)
	{
		if(start==nums.size())
        {
			res.push_back(nums);
            return;
        }
		for(int i=start;i<nums.size();i++)
		{
			if(i>start&&nums[i]==nums[start])
				continue;
			swap(nums[i],nums[start]);
			permute(res,nums,start+1);
		}
	}
};


