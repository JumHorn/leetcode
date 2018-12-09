#include<vector>
#include<algorithm>
using namespace std;
/*
dp[i][j]=max{ dp[i-1][j],dp[i][j-1],(j-i)*min{height[i],height[j]} }
0<=i<n,i<j<=n
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<int> dp(height.size());
		for(int j=1;j<height.size();j++)
			dp[j]=max(dp[j-1],j*min(height[0],height[j]));
		for(int i=1;i<height.size();i++)
			for(int j=i+1;j<height.size();j++)
                dp[j]=max(max(dp[j],dp[j-1]),(j-i)*min(height[i],height[j]));
		return dp.back();
    }
};
