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
		int res=0;
		for(int i=0;i<height.size();i++)
			for(int j=i+1;j<height.size();j++)
                res=max(res,(j-i)*min(height[i],height[j]));
		return res;
    }
};
