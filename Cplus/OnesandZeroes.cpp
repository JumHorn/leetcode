#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
		if(strs.empty())
			return 0;
		vector<vector<int> > dp(m+1,vector<int>(n+1));
		vector<vector<int> > binstr(strs.size(),vector<int>(2));
		for(int i=0;i<(int)strs.size();i++)
			for(int j=0;j<(int)strs[i].size();j++)
				strs[i][j]=='1'? binstr[i][1]++:binstr[i][0]++;
        for(int k=0;k<(int)binstr.size();k++)
            for(int i=m;i>=binstr[k][0];i--)
                for(int j=n;j>=binstr[k][1];j--)
                    if(i>=binstr[k][0]&&j>=binstr[k][1])
                        dp[i][j]=max(dp[i][j],1+dp[i-binstr[k][0]][j-binstr[k][1]]);
		return dp.back().back();
    }
};
