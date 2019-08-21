#include<vector>
#include<algorithm>
#include<unordered_set>
#include<climits>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(edges.empty())
            return {0};
		vector<unordered_set<int>> graph(n);
		for(int i=0;i<(int)edges.size();i++)
		{
			graph[edges[i][0]].insert(edges[i][1]);
			graph[edges[i][1]].insert(edges[i][0]);
		}
        vector<int> movenode(n);
        vector<int> leftnode(n);
        while(n>2)
        {
            int leafnode=0;
            for(int i=0;i<(int)graph.size();i++)
            {
                if(leftnode[i]!=-1&&graph[i].size()==1)
                {
                    movenode[leafnode]=i;
                    leafnode++;
                }
            }
            for(int i=0;i<leafnode;i++)
            {
                graph[*graph[movenode[i]].begin()].erase(movenode[i]);
                graph[movenode[i]].clear();
                leftnode[movenode[i]]=-1;
            }
            n-=leafnode;
        }
        vector<int> res;
        for(int i=0;i<(int)leftnode.size();i++)
            if(leftnode[i]!=-1)
                res.push_back(i);
		return res;
    }
};