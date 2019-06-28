#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
		int m=grid.size(),n=grid[0].size();
		vector<vector<int>> tmp(m+1,vector<int>(n+1));
		for(int i=2;i<=m;i++)
			tmp[i][0]=-1;
		for(int i=2;i<=n;i++)
			tmp[0][i]=-1;
		for(int i=0;i<m;i++)
			copy(grid[i].begin(),grid[i].end(),tmp[i+1].begin()+1);
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
			{
				if(tmp[i][j]!=-1)
				{
					if(tmp[i-1][j]==-1&&tmp[i][j-1]==-1)
						tmp[i][j]=-1;
					else if(tmp[i-1][j]==-1)
						tmp[i][j]+=tmp[i][j-1];
					else if(tmp[i][j-1]==-1)
						tmp[i][j]+=tmp[i-1][j];
					else
						tmp[i][j]+=max(tmp[i-1][j],tmp[i][j-1]);
				}
			}		
		int res=tmp.back().back();
		if(res==-1)
			return 0;
		int i=m,j=n;
        grid[0][0]=0;
		while(i>1||j>1)
		{
			grid[i-1][j-1]=0;
			if(tmp[i][j]-tmp[i][j-1]>tmp[i][j]-tmp[i-1][j])
				i--;
			else
				j--;
		}
		for(int i=0;i<m;i++)
			copy(grid[i].rbegin(),grid[i].rend(),tmp[m-i].begin()+1);
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
			{
				if(tmp[i][j]!=-1)
				{
					if(tmp[i-1][j]==-1&&tmp[i][j-1]==-1)
						tmp[i][j]=-1;
					else if(tmp[i-1][j]==-1)
						tmp[i][j]+=tmp[i][j-1];
					else if(tmp[i][j-1]==-1)
						tmp[i][j]+=tmp[i-1][j];
					else
						tmp[i][j]+=max(tmp[i-1][j],tmp[i][j-1]);
				}
			}		
		return res+tmp.back().back();
    }
};