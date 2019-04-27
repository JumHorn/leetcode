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
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
				for(int k=0;k<(int)binstr.size();k++)
				{
					int tmp=max(dp[i-1][j],dp[i][j-1]);
					if(i>=binstr[k][0]&&j>=binstr[k][1])
						dp[i][j]=max(1+dp[i-binstr[k][0]][j-binstr[k][1]],tmp);
					else
						dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				}
		return dp.back().back();
    }
};

int main()
{
	vector<string> v;
	v.push_back("10");
	v.push_back("0001");
	v.push_back("111001");
	v.push_back("1");
	v.push_back("0");
	Solution sol;
	cout<<sol.findMaxForm(v,5,3)<<endl;
}