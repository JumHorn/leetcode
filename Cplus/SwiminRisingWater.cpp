#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
	struct node
	{
		int max;
		int x,y;//current coordinate
		set<pair<int,int> > visited;
        bool operator<(const node& n) const
        {
            return n.max>max;
        }
	};

public:
    int swimInWater(vector<vector<int> >& grid) {
        int res=-1;
		vector<pair<int,int> > v;
		set<node> visited;
		swimInWater(grid,visited,v,0,0,res);
		return res;
    }

	void swimInWater(vector<vector<int> >& grid,set<node>& visited,vector<pair<int,int> >& v,int i,int j,int& res)
	{
		if(i<0||i>=(int)grid.size()||j<0||j>=(int)grid[0].size())
			return;
		if(i==(int)grid.size()-1&&j==(int)grid[0].size()-1)
		{
			v.push_back(pair<int,int>(i,j));
			int tmp=0;
			for(int j=0;j<(int)v.size();j++)
				tmp=max(tmp,grid[v[j].first][v[j].second]);
			res=min(res,tmp);
			return;
		}
		node n;
		n.x=i;
		n.y=j;
		for(int i=0;i<(int)v.size();i++)
			n.visited.insert(v[i]);
		n.max=max(n.max,grid[i][j]);
		if(visited.find(n)!=visited.end())
			return;
		visited.insert(n);
		v.push_back(pair<int,int>(i,j));
		swimInWater(grid,visited,v,i-1,j,res);
		swimInWater(grid,visited,v,i+1,j,res);
		swimInWater(grid,visited,v,i,j-1,res);
		swimInWater(grid,visited,v,i,j+1,res);
		v.pop_back();
	}
};
