#include<vector>
using namespace std;

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
		vector<int> res(hits.size());
        vector<vector<int>> visited;
		for(int i=0;i<(int)hits.size();i++)
		{
			if(grid[hits[i][0]][hits[i][1]]==0)
            {
				res[i]=0;
                continue;
            }
			grid[hits[i][0]][hits[i][1]]=0;
			int tmp=0;
			tmp=dfs(grid,hits[i][0]-1,hits[i][1],visited);
			if(tmp!=-1)
				res[i]+=tmp;
            else
                for(int i=0;i<(int)visited.size();i++)
                    grid[visited[i][0]][visited[i][1]]=1;
            visited.clear();
			tmp=dfs(grid,hits[i][0]+1,hits[i][1],visited);
			if(tmp!=-1)
				res[i]+=tmp;
            else
                for(int i=0;i<(int)visited.size();i++)
                    grid[visited[i][0]][visited[i][1]]=1;
            
            visited.clear();
			tmp=dfs(grid,hits[i][0],hits[i][1]-1,visited);
			if(tmp!=-1)
				res[i]+=tmp;
            else
                for(int i=0;i<(int)visited.size();i++)
                    grid[visited[i][0]][visited[i][1]]=1;
            visited.clear();
			tmp=dfs(grid,hits[i][0],hits[i][1]+1,visited);
			if(tmp!=-1)
				res[i]+=tmp;
            else
                for(int i=0;i<(int)visited.size();i++)
                    grid[visited[i][0]][visited[i][1]]=1;
		}
		return res;
    }

	int dfs(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& visited)
	{
		int res=0;
		if(i<0||i>=(int)grid.size()||j<0||j>=(int)grid[0].size()||grid[i][j]==0)
			return 0;
		if(i==0)
			return -1;
		int tmp=0;
		grid[i][j]=0;
        visited.push_back({i,j});
        res++;
		tmp=dfs(grid,i-1,j,visited);
		if(tmp==-1)
			return -1;
        res+=tmp;
		tmp=dfs(grid,i+1,j,visited);
		if(tmp==-1)
			return -1;
        res+=tmp;
		tmp=dfs(grid,i,j-1,visited);
        if(tmp==-1)
			return -1;
        res+=tmp;
		tmp=dfs(grid,i,j+1,visited);
		if(tmp==-1)
			return -1;
        res+=tmp;
		return res;
	}
};

int main()
{
    vector<vector<int>> v=
    {
        {0,1,1,1,1,1,1,0,1},
        {1,1,1,1,0,1,1,1,0},
        {0,0,0,1,0,0,1,1,1},
        {0,0,1,1,0,1,1,1,0},
        {0,0,0,0,0,1,1,1,1},
        {0,0,0,0,0,0,0,1,0}
    };
    //vector<vector<int>> t={{1,8},{2,1},{1,4},{3,0},{3,4},{0,7},{1,6}};
    vector<vector<int>> t={{1,6}};
    Solution sol;
    sol.hitBricks(v,t);
    return 0;
}