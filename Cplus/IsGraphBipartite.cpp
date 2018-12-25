#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int> >& graph) {
		if(graph.size()<2)
			return true;
        vector<int> unsort;
		unordered_set<int> node1,node2;
		node1.insert(0);
		for(int i=0;i<graph[0].size();i++)
			node2.insert(graph[0][i]);
		for(int i=1;i<graph.size();i++)
		{
			if(node1.find(i)!=node1.end())
			{
				for(int j=0;j<graph[i].size();j++)
				{
					if(node2.find(graph[i][j])!=node2.end())
						return false;
					node2.insert(graph[i][j]);
				}
			}
			if(node2.find(i)!=node2.end())
			{
				for(int j=0;j<graph[i].size();j++)
				{
					if(node1.find(graph[i][j])!=node1.end())
						return false;
					node1.insert(graph[i][j]);
				}
			}
			unsort.push_back(i);
		}
		for(int i=0;i<unsort.size();i++)
		{}
		return true;
    }
};
