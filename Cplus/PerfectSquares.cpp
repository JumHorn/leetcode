#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
		static vector<int> dp({0});
        while(n>=(int)dp.size())
        {
            int m=dp.size(),tmp=INT_MAX;
            for(int j=1;j*j<=m;j++)
            {
                tmp=min(tmp,1+dp[m-j*j]);
            }
            dp.push_back(tmp);
        }
		return dp[n];
    }
};

int main()
{
	Solution sol;
	sol.numSquares(11);
}
