#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
		vector<vector<int> > res;
		vector<int> sol;
		sort(candidates.begin(),candidates.end());
		combine(candidates,target,res,sol,candidates.begin());
		return res;		
    }

	void combine(vector<int>& candidates,int target,vector<vector<int> >& res, vector<int>& sol,vector<int>::iterator start)
	{
		for(vector<int>::iterator iter=start;iter!=candidates.end();iter++)
		{
			if(target==*iter)
			{
				sol.push_back(*iter);
				res.push_back(sol);
				sol.pop_back();
				return;
			}
			if(target<*iter)
			{
				return;
			}
			sol.push_back(*iter);
			combine(candidates,target-*iter,res,sol,iter);
			sol.pop_back();
		}
	}
};
