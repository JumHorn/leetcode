#include<vector>
#include<algorithm>
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

		vector<vector<int> > res(v.size()+k,vector<int>(3));
		vector<vector<int> > dp(4,vector<int>(v.size()+k));
		//dp[i][j] i 0,1,2,3 j 0~v.size()+k
		//dp[i][j]=max(dp[i-1][j-k]+v[j],dp[i][j-k])
		for(int i=1;i<(int)dp.size();i++)
			for(int j=k;j<(int)dp[0].size();j++)
			{
				if(dp[i-1][j-k]+v[j-k]>dp[i][j-k])
				{
					for(int m=0;m<i-1;m++)
						res[j][m]=res[j-k][m];
					res[j][i-1]=j;
					dp[i][j]=dp[i-1][j-k]+v[j-k];
				}
				else
				{
					for(int m=0;m<i;m++)
						res[j][m]=res[j-k][m];
					dp[i][j]=dp[i][j-k];
				}
			}
		int index=(int)dp[0].size()-1;
		for(;index>0;index--)
		{
			if(dp.back()[index]!=dp.back().back())
				return res[index+1];
		}
		return res[index];
    }
};
