#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
		vector<unordered_map<int,bool> > dp(1100);
		return canCross(stones,0,0,dp);  
    }

	bool canCross(vector<int>& stones,int current,int skip,vector<unordered_map<int,bool> >& dp)
	{
		if(current==(int)stones.size()-1)
		{
			dp[current][skip]=true;
			return true;
		}
		if(dp[current].find(skip)!=dp[current].end())
			return dp[current][skip];
		int k=skip+1,i,j;
		for(i=current+1;i<(int)stones.size();i++)
		{
			if(k+stones[current]==stones[i])
			{
				if(canCross(stones,i,k,dp))
					return true;
				dp[i][k]=false;
			}
			if(stones[i]>k+stones[current])
				break;
		}
		k--;
		if(k>0)
		{
			for(j=i-1;j>current;j--)
			{
				if(k+stones[current]==stones[j])
				{
					if(canCross(stones,j,k,dp))
						return true;
					dp[j][k]=false;
				}
				if(stones[j]<k+stones[current])
					break;
			}
		}
		k--;
		if(k>0)
		{
			for(;j>current;j--)
			{
				if(k+stones[current]==stones[j])
				{
					if(canCross(stones,j,k,dp))
						return true;
					dp[j][k]=false;
				}
				if(stones[j]<k+stones[current])
					break;
			}
		}
		dp[current][k]=false;
		return false;
	}
};