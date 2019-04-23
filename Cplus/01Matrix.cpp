#include<vector>
#include<queue>
#include<set>
using namespace std;

class Solution {
public:
    vector<vector<int> > updateMatrix(vector<vector<int> >& matrix) {
		queue<pair<int,int> > q;
		int direction[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
		for(int i=0;i<matrix.size();i++)
			for(int j=0;j<matrix[0].size();j++)
			{
				if(matrix[i][j]==0)
					q.push(pair<int,int>(i,j));
				else
					matrix[i][j]=INT_MAX;
			}
		while(!q.empty())
		{
			for(int i=0;i<4;i++)
			{
				int x=q.front().first+direction[i][0],y=q.front().second+direction[i][1];
				if(x>=0&&x<matrix.size()&&y>=0&&y<matrix[0].size())
				{
					int tmp=matrix[q.front().first][q.front().second];
					if(matrix[x][y]>tmp)
					{
						matrix[x][y]=tmp+1;
						q.push(pair<int,int>(x,y));
					}
				}
			}
            q.pop();
		}
        return matrix;
    }
};
