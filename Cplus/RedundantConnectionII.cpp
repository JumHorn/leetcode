#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
		vector<vector<int>> graph(edges.size()+1);
		vector<int> res;
		int twoparents=-1;
		unordered_set<int> visited;
		for(int i=0;i<(int)edges.size();i++)
		{
			if(visited.count(edges[i][0])>0&&visited.count(edges[i][1])>0)
				res=edges[i];
			visited.insert(edges[i][0]);
			visited.insert(edges[i][1]);
			graph[edges[i][1]].push_back(edges[i][0]);
			if(graph[edges[i][1]].size()>1)
				twoparents=edges[i][1];
		}
		if(twoparents==-1)
			return res;
		int id=graph[twoparents][0];
		while((int)graph[id].size()>0&&id!=twoparents)
			id=graph[id][0];
		if(id==twoparents)
			return {graph[twoparents][0],twoparents};
		else
			return {graph[twoparents][1],twoparents};
    }
};
