#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
		vector<unordered_map<int,int>> graph(N,unordered_map<int,int>(N));       
		vector<vector<int>> visited(N,vector<int>(N));
		vector<int> v(N,-1);
		for(int i=0;i<(int)edges.size();i++)
		{
			graph[edges[i][0]][edges[i][1]]=edges[i][2];
			graph[edges[i][1]][edges[i][0]]=edges[i][2];
		}
		dfs(0,M,graph,visited,v);
		int res=0;
		for(int i=0;i<N;i++)
			if(v[i]>=0)
				res+=1;
		for(int i=0;i<N-1;i++)
			for(int j=i+1;j<N;j++)
				res+=min(graph[i][j],visited[i][j]+visited[j][i]);
		return res;
    }

	void dfs(int n,int m,vector<unordered_map<int,int>>& graph,vector<vector<int>>& visited,vector<int>& v)
	{
		if(v[n]>=m)
			return;
		v[n]=m;
		if(m==0)
			return;
		for(auto iter : graph[n])
		{
			if(m>iter.second)
			{
				visited[n][iter.first]=iter.second;
				dfs(iter.first,m-iter.second-1,graph,visited,v);
			}
			else
				visited[n][iter.first]=max(visited[n][iter.first],m);
		}
	}
};