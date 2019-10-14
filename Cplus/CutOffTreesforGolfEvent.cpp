#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
		int N=forest.size(),M=forest[0].size();
        vector<int> height;
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				if(forest[i][j]>1)
					height.push_back(forest[i][j]);
		sort(height.begin(),height.end());
		int cut=0,res=0,i=0,j=0,steps=0;
		if(forest[0][0]==height[cut])
			cut++;
		int dir[][2]={{-1,0},{1,0},{0,-1},{0,1}};
start:
		while(cut<(int)height.size())
		{
			queue<int> q;
			unordered_set<int> visited;
			visited.insert(i*M+j);
			q.push(i*M+j);
			while(!q.empty())
			{
				int size=q.size();
				steps++;
				while(--size>=0)
				{
					i=q.front()/M;
					j=q.front()%M;
					q.pop();
					for(int k=0;k<4;k++)
					{
						int x=i+dir[k][0],y=j+dir[k][1];
						if(x>0&&x<M&&y>0&&y<N&&forest[x][y]!=0)
						{
							if(visited.find(x*M+y)==visited.end())
							{
								if(forest[x][y]==height[cut])
								{
									i=x;
									j=y;
									res+=steps;
									cut++;
									goto start;
								}
								else
								{
									visited.insert(x*M+y);
									q.push(x*M+y);
								}
							}
						}
					}
				}
			}
			return -1;
		}
		return res;
    }
};

int main()
{
	vector<vector<int>> v=
	{
		{1,2,3},
		{0,0,4},
		{7,6,5}
	};
	Solution sol;
	sol.cutOffTree(v);
	return 0;
}