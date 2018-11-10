#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int> > dp(nums.size(),vector<int>(nums.size()));
		for(int i=0;i<nums.size();i++)
			dp[i][i]=nums[i];
		for(int i=1;i<nums.size();i++)
			for(int j=0;j<int(nums.size()-i);j++)
			{
				dp[j][j+i]=max(nums[j]+accumulate(nums.begin()+j+1,nums.begin()+j+i+1,0)-dp[j+1][j+i],nums[j+i]+accumulate(nums.begin()+j,nums.begin()+j+i,0)-dp[j][j+i-1]);
			}
		return dp.front().back()>=accumulate(nums.begin(),nums.end(),0)/2.0;
    }
};
