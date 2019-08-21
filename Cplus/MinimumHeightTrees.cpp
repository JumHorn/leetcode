#include<vector>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
#include<climits>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(edges.empty())
            return {0};
		unordered_map<int,unordered_set<int>> graph;
		for(int i=0;i<(int)edges.size();i++)
		{
			graph[edges[i][0]].insert(edges[i][1]);
			graph[edges[i][1]].insert(edges[i][0]);
		}
        vector<int> movenode(n);
        while(n>2)
        {
            int leafnode=0;
            for(unordered_map<int,unordered_set<int>>::iterator iter=graph.begin();iter!=graph.end();++iter)
            {
                if(iter->second.size()==1)
                {
                    movenode[leafnode]=iter->first;
                    leafnode++;
                }
            }
            for(int i=0;i<leafnode;i++)
            {
                graph[*graph[movenode[i]].begin()].erase(movenode[i]);
                graph.erase(movenode[i]);
            }
            n-=leafnode;
        }
        vector<int> res;
        for(auto& node:graph)
            res.push_back(node.first);
		return res;
    }
};