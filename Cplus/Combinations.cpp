#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
		vector<vector<int> > res;
		vector<int> tmp;
		combine(res,tmp,1,n,k);
		return res;
    }

	void combine(vector<vector<int> >& res,vector<int>& sol,int i,int n,int k)
	{
		if(k==0)
		{
			res.push_back(sol);
			return;
		}
		if(i>n)
		{
			return;
		}
		for(int j=i;j<=n-k+1;j++)
		{
			sol.push_back(j);
			combine(res,sol,j+1,n,k-1);
			sol.pop_back();
		}
	}
};
