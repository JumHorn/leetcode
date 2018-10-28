#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
		vector<vector<int> > res;
		vector<int> sol;
		combine(candidates,target,res,sol,candidates.begin());
		return res;		
    }

	void combine(vector<int>& candidates,int target,vector<vector<int> >& res, vector<int> sol,vector<int>::iterator start)
	{
		if(target==0)
		{
			res.push_back(sol);
			return;
		}
		for(vector<int>::iterator iter=start;iter!=candidates.end();iter++)
		{
			if(target<0)
			{
				break;
			}
			sol.push_back(*iter);
			combine(candidates,target-*iter,res,sol,iter);
			sol.pop_back();
		}
	}
};
