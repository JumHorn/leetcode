#include<vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
        int res=0;
	    for(int i=0;i<(int)grid.size();i++)	
			for(int j=0;j<(int)grid[0].size();j++)
			{
				res+=numIslands(grid,i,j);
			}
		return res;
    }

	int numIslands(vector<vector<char> >& grid,int i,int j)
	{
		if(grid[i][j]=='0'||grid[i][j]=='2')
			return 0;
		grid[i][j]='2';
		if(i+1<(int)grid.size())
			numIslands(grid,i+1,j);
		if(i-1>=0)
			numIslands(grid,i-1,j);
		if(j+1<(int)grid[i].size())
			numIslands(grid,i,j+1);
		if(j-1>=0)
			numIslands(grid,i,j-1);
		return 1;
	}
};
