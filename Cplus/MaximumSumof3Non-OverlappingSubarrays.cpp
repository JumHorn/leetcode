#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
		vector<int> v(nums.size()-k+1);
		for(int i=0;i<k;i++)
			v[0]+=nums[i];

		//slide window
		for(int i=1;i<=(int)nums.size()-k;i++)
			v[i]=v[i-1]-nums[i-1]+nums[i+k-1];

		vector<int> res(3);
		vector<vector<int> > dp(4,vector<int>(v.size()+k));
		//dp[i][j] i 0,1,2,3 j 0~v.size()+k
		//dp[i][j]=max(dp[i-1][j-k]+v[j],dp[i][j-1])	
		for(int i=1;i<(int)dp.size();i++)
			for(int j=k;j<(int)dp[0].size();j++)
					dp[i][j]=max(dp[i-1][j-k]+v[j-k],dp[i][j-1]);
        
		int j=dp[0].size()-1;
		for(int i=2;i>=0;i--)
		{
			while(--j>=k&&dp[i+1][j]==dp[i+1][j+1]);
			res[i]=j+1-k;
			j=j+1-k;
		}
		return res;
    }
};