#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
		int res=0;
		static unordered_set<int> dp;
		static vector<int> results(1);
        results[0]=1;
		dp.insert(1);
        if(n<=(int)results.size())
            return results[n-1];
		for(int i=results.size();i<n;i++)
		{
			res=results.back();
		    while(!nthUglyNumber(dp,++res));
			results.push_back(res);
		}
		return res;
    }

	bool nthUglyNumber(unordered_set<int>& dp,int n)
	{
		if(dp.find(n)!=dp.end())
			return true;
		bool res=false;
		if(!res&&n%2==0)
			res=nthUglyNumber(dp,n/2);
		if(!res&&n%3==0)
			res=nthUglyNumber(dp,n/3);
		if(!res&&n%5==0)
			res=nthUglyNumber(dp,n/5);
		if(res==true)
			dp.insert(n);
		return res;
	}
};
