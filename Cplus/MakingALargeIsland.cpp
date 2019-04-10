#include<vector>
#include<set>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int largestIsland(vector<vector<int> >& grid) {
		if(grid.empty())
			return 0;
		//calculate connected Island
		vector<vector<int> > IslandIndex;
		unordered_map<int,int> color;
		int c=3;
        for(int i=0;i<(int)grid.size();i++)
			for(int j=0;j<(int)grid[0].size();j++)
				if(grid[i][j]==1)
				{
					int all=connectedIsland(grid,IslandIndex,i,j);
					for(int i=0;i<(int)IslandIndex.size();i++)
						grid[IslandIndex[i][0]][IslandIndex[i][1]]=c;
					color[c]=all;
					c++;
					IslandIndex.clear();
				}

		int res=0;
		for(int i=0;i<(int)grid.size();i++)
			for(int j=0;j<(int)grid[0].size();j++)
				if(grid[i][j]==0)
					res=max(res,bigIsland(grid,color,i,j));
		if(res==0)
			res=grid.size()*grid[0].size();
		return res;
    }

	int connectedIsland(vector<vector<int> >& grid,vector<vector<int> >& IslandIndex,int i,int j)
	{
		if(i<0||i>=(int)grid.size()||j<0||j>=(int)grid[0].size()||grid[i][j]==0)
			return 0;
		IslandIndex.push_back(vector<int>({i,j}));
		grid[i][j]=0;
		return 1+connectedIsland(grid,IslandIndex,i,j-1)+connectedIsland(grid,IslandIndex,i,j+1)+connectedIsland(grid,IslandIndex,i+1,j)+connectedIsland(grid,IslandIndex,i-1,j);
	}

	int bigIsland(vector<vector<int> >& grid,unordered_map<int,int>& color,int i,int j)
	{
		int res=1;
		set<int> colorset;
		if(i-1>=0)
			colorset.insert(grid[i-1][j]);
		if(j-1>=0)
			colorset.insert(grid[i][j-1]);
		if(i+1<(int)grid.size())
			colorset.insert(grid[i+1][j]);
		if(j+1<(int)grid[0].size())
			colorset.insert(grid[i][j+1]);
		for(set<int>::iterator iter=colorset.begin();iter!=colorset.end();++iter)
			res+=color[*iter];
		return res;
	}
};
