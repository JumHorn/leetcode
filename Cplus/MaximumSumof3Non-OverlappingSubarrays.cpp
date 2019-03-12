#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
		vector<int> dp(nums.size()-k+1);
		vector<int> res(3);
		for(int i=0;i<k;i++)
			dp[0]+=nums[i];

		//slide window
		for(int i=1;i<=(int)nums.size()-k;i++)
			dp[i]=dp[i-1]-nums[i-1]+nums[i+k-1];

		int tmp=INT_MIN;
		for(int i=0;i<(int)dp.size()-2*k;i++)
		{
			for(int j=i+k;j<(int)dp.size()-k;j++)
			{
				for(int m=j+k;m<(int)dp.size();m++)
				{
					if(dp[i]+dp[j]+dp[m]>tmp)
					{
						tmp=dp[i]+dp[j]+dp[m];
						res[0]=i;
						res[1]=j;
						res[2]=m;
					}
				}
			}
		}

		return res;
    }
};
