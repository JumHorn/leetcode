#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
		if(nums.empty())
			return 0;
		vector<int> dp(nums.size());        
		dp[0]=nums[0];
		for(int i=1;i<(int)nums.size();i++)
		{
			int tmp=1;
			for(int j=i;j>=1;j--)
			{
				tmp*=nums[j];
				dp[i]=max(dp[i],tmp*nums[j]*dp[j-1]);
			}
		}
		return *max_element(dp.begin(),dp.end());
    }
};
