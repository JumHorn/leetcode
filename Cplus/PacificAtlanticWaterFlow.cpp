#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > pacificAtlantic(vector<vector<int> >& matrix) {
        if(matrix.empty())
            return vector<vector<int> >();
		vector<vector<int> > dp(matrix.size(),vector<int>(matrix[0].size())),res;
		bool pacific=false,atlantic=false;
		for(int i=0;i<(int)matrix.size();i++)
			for(int j=0;j<(int)matrix[0].size();j++)
			{
				pacific=atlantic=false;
				if(dp[i][j]==0&&pacificAtlantic(matrix,dp,i,j,pacific,atlantic))
				{
					res.push_back(vector<int>({i,j}));
					dp[i][j]=2;
				}
			}

		return res;
    }

	bool pacificAtlantic(vector<vector<int> >& matrix,vector<vector<int> >& dp,int i,int j,bool& p,bool& a)
	{
		static const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
		if(dp[i][j]==3||i==0||j==0)
			p=true;
		if(dp[i][j]==4||i==(int)matrix.size()-1||j==(int)matrix[0].size()-1)
			a=true;
		if(p&&a)
			return true;
		if(dp[i][j]!=0)
			return dp[i][j]==2;
		dp[i][j]=1;
		bool res=false;
		for(int d=0;d<4;d++)
		{
			int x=i+dir[d][0],y=j+dir[d][1];
            if(x>=0&&x<(int)matrix.size()&&y>=0&&y<(int)matrix[0].size()&&matrix[i][j]>=matrix[x][y])
				res|=pacificAtlantic(matrix,dp,x,y,p,a);
		}
		dp[i][j]=0;
		if(!res)
		{
			if(p)
				dp[i][j]=3;
			else if(a)
				dp[i][j]=4;
			else
				dp[i][j]=5;
		}
		return res;
	}
};
