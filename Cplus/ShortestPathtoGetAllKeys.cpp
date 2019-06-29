#include<vector>
#include<string>
#include<queue>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
		int m,n,k=0,M=grid.size(),N=grid[0].length();
		for(int i=0;i<M;i++)
			for(int j=0;j<N;j++)
			{
				if(grid[i][j]=='@')
				{
					m=i;
					n=j;
				}
				else if(grid[i][j]<='f'&&grid[i][j]>='a')
					++k;
			}
		int directions[][4]={{1,0},{-1,0},{0,1},{0,-1}};
		unordered_set<int> visited;//state hash (k<<24)+i*N+j
		queue<int> q;
		q.push(m*N+n);
		visited.insert(m*N+n);
		int res=0;
		while(!q.empty())
		{
			++res;
			int size=q.size();
			while(--size>=0)
			{
				int state=q.front();
				q.pop();
				n=(state&0x00ffffff)%N;
				m=(state&0x00ffffff)/N;
				int key=state>>24;
				for(int i=0;i<4;i++)
				{
					int x=m+directions[i][0];
					int y=n+directions[i][1];
					if(x<0||x>=M||y<0||y>=N||grid[x][y]=='#')
						continue;
					if(grid[x][y]>='A'&&grid[x][y]<='F')
					{
						if((key&(1<<(grid[x][y]-'A')))!=0)
						{
							int tmp=(key<<24)+x*N+y;
							if(visited.find(tmp)==visited.end())
							{
								visited.insert(tmp);
								q.push(tmp);
							}
						}
					}
					else if(grid[x][y]>='a'&&grid[x][y]<='f')
					{
						int newkey=(key|(1<<(grid[x][y]-'a')));
						if(newkey==(1<<k)-1)
							return res;
						int tmp=(newkey<<24)+x*N+y;
						if(visited.find(tmp)==visited.end())
						{
							visited.insert(tmp);
							q.push(tmp);
						}
					}
					else
					{
						int tmp=(key<<24)+x*N+y;
						if(visited.find(tmp)==visited.end())
						{
							visited.insert(tmp);
							q.push(tmp);
						}
					}
				}
			}
		}
		return -1;
    }
};
