#include<vector>
#include<algorithm>
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
			if(tmp.back()<tmp[tmp.size()-2])
				return;
            if(find(res.begin(),res.end(),tmp)==res.end())
			{
				if(isExist(res,tmp))
			    	res.push_back(tmp);
			}
		}
		for(int i=start;i<nums.size();i++)
		{
			tmp.push_back(nums[i]);
			findSubsequences(res,nums,tmp,i+1);
			tmp.pop_back();
		}
	}

	bool isExist(vector<vector<int> >& res,vector<int>& tmp)
	{
		for(int i=0;i<res.size();i++)
		{
			if(res[i].size()==tmp.size())
			{
				int j=0;
				for(j=0;j<tmp.size();j++)
					if(res[i][j]!=tmp[j])
						break;
				if(j==tmp.size())
					return false;
			}
		}
		return true;
	}
};
