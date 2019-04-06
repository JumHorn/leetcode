#include<vector>
using namespace std;

class Solution {
public:
    int uniquePathsIII(vector<vector<int> >& grid) {
		int allzero=0;
		int m,n;
	    for(int i=0;i<(int)grid.size();i++)
			for(int j=0;j<(int)grid[0].size();j++)
			{
				if(grid[i][j]==1)
				{
					m=i;
					n=j;
				}
                else if(grid[i][j]==0)
                    allzero++;
			}
		return uniquePathsIII(grid,allzero,-1,m,n);
    }

	int uniquePathsIII(vector<vector<int> >& grid,int allzero,int zeros,int m,int n)
	{
		if(m>=(int)grid.size()||m<0||n>=(int)grid[0].size()||n<0||grid[m][n]==-1)
			return 0;
		if(grid[m][n]==2)
		{
			if(allzero==zeros)
				return 1;
			else
				return 0;
		}
		int res=0;
		grid[m][n]=-1;
		res+=uniquePathsIII(grid,allzero,zeros+1,m+1,n);
		res+=uniquePathsIII(grid,allzero,zeros+1,m-1,n);
		res+=uniquePathsIII(grid,allzero,zeros+1,m,n+1);
		res+=uniquePathsIII(grid,allzero,zeros+1,m,n-1);
		grid[m][n]=0;
		return res;
	}
};
