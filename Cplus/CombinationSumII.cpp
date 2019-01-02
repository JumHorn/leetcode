#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > res;
		vector<int> tmp;
		sort(candidates.begin(),candidates.end());
		combination(res,candidates,target,tmp,0);
		return res;
    }

	void combination(vector<vector<int> >& res,vector<int>& candidates,int target,vector<int>& tmp,int start)
	{
		for(int i=start;i<(int)candidates.size();i++)
		{
			if(target-candidates[i]==0)
			{
				tmp.push_back(candidates[i]);
				if(find(res.begin(),res.end(),tmp)==res.end())
					res.push_back(tmp);
                tmp.pop_back();
				return;
			}
			if(target-candidates[i]<0)
				return;
			tmp.push_back(candidates[i]);
			combination(res,candidates,target-candidates[i],tmp,i+1);
			tmp.pop_back();
		}
	}
};
