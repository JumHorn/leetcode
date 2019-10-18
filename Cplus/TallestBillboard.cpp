#include<vector>
#include<unordered_map>
#include<cmath>
#include<algorithm>
using namespace std;

class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
		unordered_map<int,int> dp;
		dp[0]=0;
		for(int i=0;i<(int)rods.size();i++)
		{
			unordered_map<int,int> tmp(dp);
			for(auto& n:tmp)
			{
				dp[n.first+rods[i]]=max(dp[n.first+rods[i]],tmp[n.first]);
				if(rods[i]>=n.first)
					dp[abs(n.first-rods[i])]=max(dp[abs(n.first-rods[i])],tmp[n.first]+n.first);
				else
					dp[abs(n.first-rods[i])]=max(dp[abs(n.first-rods[i])],tmp[n.first]+rods[i]);
			}
		}
		return dp[0];
    }
};