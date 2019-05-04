#include<climits>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
		vector<vector<int> > dp(key.length(),vector<int>(ring.length()));
		return findRotateSteps(dp,ring,0,key,0);
    }

	int findRotateSteps(vector<vector<int> >& dp,const string& ring,int r,const string& key,int k)
	{
		if(k==(int)key.length())
			return 0;
		if(dp[k][r]!=0)
			return dp[k][r];
		int n=ring.size(),res=INT_MAX,tmp,radius=0;
		if(ring[r]==key[k])
			return findRotateSteps(dp,ring,r,key,k+1)+1;
		while(++radius<=(int)ring.size()/2)
		{
			tmp=(r+radius)%n;
			if(ring[tmp]==key[k])
			{
				res=min(res,findRotateSteps(dp,ring,tmp,key,k+1)+radius+1);
			}
			tmp=(r-radius+n)%n;
			if(ring[tmp]==key[k])
			{
				res=min(res,findRotateSteps(dp,ring,tmp,key,k+1)+radius+1);
			}
		}
		dp[k][r]=res;
		return res;
	}
};
