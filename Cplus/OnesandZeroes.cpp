#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
		if(strs.empty())
			return 0;
		vector<vector<int> > data(strs.size(),vector<int>(2));
		for(int i=0;i<(int)strs.size();i++)
			for(int j=0;j<(int)strs[i].length();j++)
				data[i][strs[i][j]-'0']++;		
		vector<vector<int> > dp1(strs.size()+1,vector<int>(m+1));
		for(int j=1;j<=m;j++)
			for(int i=1;i<=(int)strs.size();i++)
			{
				if(j<data[i-1][0]||data[i-1][0]>0)
					dp1[i][j]=dp1[i-1][j];
				else
					dp1[i][j]=max(dp1[i-1][j],dp1[i-1][j-data[i-1][0]]+1);
			}
		vector<vector<int> > dp2(strs.size()+1,vector<int>(n+1));
		for(int j=1;j<=n;j++)
		{
			for(int i=1;i<=(int)strs.size();i++)
			{
				if(m<data[i-1][0]||j<data[i-1][1])
					dp2[i][j]=dp2[i-1][j];
				else
					dp2[i][j]=max(dp2[i-1][j],dp2[i-1][j-data[i-1][1]]+1);
			}
		}
		return dp2.back().back();
    }
};
