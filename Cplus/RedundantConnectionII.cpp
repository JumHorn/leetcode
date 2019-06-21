#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
		vector<vector<int>> parent(edges.size()+1);
		vector<vector<int>> graph(edges.size()+1);
		for(int i=0;i<(int)edges.size();i++)
		{
			parent[edges[i][1]].push_back(edges[i][0]);
			graph[edges[i][0]].push_back(edges[i][1]);
		}
		vector<int> res;
		unordered_set<int> visited;
		for(int i=1;i<=(int)graph.size();i++)
		{
			if(visited.find(i)==visited.end())
			{
				visited.insert(i);
				if(DFS(res,graph,i,visited))
				{
					res[0]=parent[res[1]].back();
					return res;
				}
			}
		}
		return res;
    }

	bool DFS(vector<int>& res,vector<vector<int>>& graph,int n,unordered_set<int>& visited)
	{
		for(int i=0;i<(int)graph[n].size();i++)
		{
			if(visited.find(graph[n][i])!=visited.end())
			{
				res.push_back(n);
				res.push_back(graph[n][i]);
				return true;
			}
			visited.insert(graph[n][i]);
			if(DFS(res,graph,graph[n][i],visited))
				return true;
		}
		return false;
	}
};
