#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
public:
    vector<vector<int> > findSubsequences(vector<int>& nums) {
        vector<vector<int> > res;
		vector<int> tmp;
		findSubsequences(res,nums,tmp,0);
		return res;
    }

	void findSubsequences(vector<vector<int> >& res,vector<int>& nums,vector<int>& tmp,int start)
	{
		if(tmp.size()>1)
		{
		    res.push_back(tmp);
		}
		set<int> visited;
		for(int i=start;i<nums.size();i++)
		{
			if((tmp.empty()||nums[i]>=tmp.back())&&visited.find(nums[i])==visited.end())
			{
				tmp.push_back(nums[i]);
				findSubsequences(res,nums,tmp,i+1);
				tmp.pop_back();
				visited.insert(nums[i]);
			}
		}
	}
};
