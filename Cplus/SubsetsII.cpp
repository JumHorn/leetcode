#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > res;
		sort(nums.begin(),nums.end());
		vector<int> n;
		combination(res,nums,n,0);
		return res;
    }

	void combination(vector<vector<int> >& res,vector<int>& nums,vector<int>& n,int start)
	{
		if(find(res.begin(),res.end(),n)==res.end())
			res.push_back(n);
		for(int i=start;i<nums.size();i++)
		{
			n.push_back(nums[i]);
			combination(res,nums,n,i+1);
			n.pop_back();
		}
	}
};
