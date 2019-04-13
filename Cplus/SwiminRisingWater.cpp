#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
	struct Node
	{
		int elevation;
		int x,y;//coordinate
		Node(int t,int i,int j):elevation(t),x(i),y(j){}
		bool operator<(const Node& n) const { return elevation>n.elevation; }
	};
public:
    int swimInWater(vector<vector<int> >& grid) {
		vector<vector<int> > visited(grid.size(),vector<int>(grid.size(),0));
		int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
		priority_queue<Node> pq;
		pq.push(Node(grid[0][0],0,0));
		visited[0][0]=1;
		int res=0;
		while(!pq.empty())
		{
			Node tmp=pq.top();
			pq.pop();
			res=max(res,tmp.elevation);
			if(tmp.x==(int)grid.size()-1&&tmp.y==(int)grid.size()-1)
				return res;
			for(int i=0;i<4;i++)
			{
				int x=tmp.x+dir[i][0],y=tmp.y+dir[i][1];
				if(x>=0&&x<(int)grid.size()&&y>=0&&y<(int)grid.size()&&visited[x][y]==0)
				{
					visited[x][y]=1;
					pq.push(Node(grid[x][y],x,y));
				}
			}
		}
		return res;
    }
};
