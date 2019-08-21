#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		vector<int> mhts(n);
		vector<vector<int>> graph(n);
        vector<int> visited(n);
		for(int i=0;i<(int)edges.size();i++)
		{
			graph[edges[i][0]].push_back(edges[i][1]);
			graph[edges[i][1]].push_back(edges[i][0]);
		}
		for(int i=0;i<n;i++)
			mhts[i]=getMinHeight(graph,INT_MAX,i);
		vector<int> res;
		res.push_back(0);
		for(int i=1;i<n;i++)
		{
			if(mhts[i]<mhts[res.front()])
			{
				res.clear();
				res.push_back(i);
			}
			else if(mhts[i]==mhts[res.front()])
				res.push_back(i);
		}
		return res;
    }

	int getMinHeight(vector<vector<int>>& graph,int parent,int current)
	{
		int height=0;
		for(int i=0;i<(int)graph[current].size();i++)
            if(graph[current][i]!=parent)
			    height=max(height,1+getMinHeight(graph,current,graph[current][i]));
		return height;
	}
};