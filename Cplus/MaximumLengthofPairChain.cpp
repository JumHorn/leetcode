#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int> >& pairs) {
        sort(pairs.begin(),pairs.end(),*this);
		vector<int> dp(pairs.size(),1);
		for(int i=1;i<(int)dp.size();i++)
		{
			int res=1;
			for(int j=i-1;j>=0;j--)
			{
				if(pairs[i][0]>pairs[j][1])
				{
					res=max(res,dp[j]+1);
				}
			}
			dp[i]=res;
		}
		return dp.back();
    }

	bool operator()(vector<int>& a,vector<int>& b)
	{
		if(a[0]<b[0])
			return true;
		if(a[0]>b[0])
			return false;
		if(a[1]<b[1])
			return true;
		return false;
	}
};
