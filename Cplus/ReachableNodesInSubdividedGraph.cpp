#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
		vector<vector<pair<int,int>>> graph(N);     
		vector<vector<int>> visited(N,vector<int>(N));
		vector<int> v(N,-1);
		for(int i=0;i<(int)edges.size();i++)
		{
			graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
			graph[edges[i][1]].push_back({edges[i][0],edges[i][2]});
		}
		
		int res=0;
		//dijkstra
		priority_queue<pair<int,int>> q;
		q.push({M,0});
		while(!q.empty())
		{
			int weight=q.top().first;
			int node=q.top().second;
			q.pop();
			if(weight<=v[node])
				continue;
			v[node]=weight;
			++res;
			for(auto n : graph[node])
			{
				if(weight>n.second)
				{
					visited[node][n.first]=n.second;
                    if(weight-n.second-1>v[n.first])
					    q.push({weight-n.second-1,n.first});
				}
				else
					visited[node][n.first]=max(visited[node][n.first],weight);
			}
		}

		for(int k=0;k<(int)edges.size();k++)
        {
			int i=edges[k][0],j=edges[k][1],w=edges[k][2];
				res+=min(w,visited[i][j]+visited[j][i]);
        }
		return res;
    }
};
