#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
	vector<int> singleRes;
    int n;
    vector<vector<int> > combinationSum3(int k, int n) {
       vector<vector<int> > res;
	   singleRes.resize(k);
       this->n=n;
	   combination(res,1,0); 
	   return res;
    }

	void combination(vector<vector<int> >& res,int l,int k)
	{
		if(k==singleRes.size())
		{
			if(n==accumulate(singleRes.begin(),singleRes.end(),0))
				res.push_back(singleRes);
		}
		else
		{
			for(int i=l;i<=9;i++)//only 1-9 combination
			{
				singleRes[k]=i;
				combination(res,i+1,k+1);
			}
		}
	}
};

