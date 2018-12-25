#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int> >& graph) {
		vector<int> nodecolor(graph.size(),0);//all initial nodes are not colored
		for(int i=0;i<graph.size();i++)
			if(nodecolor[i]==0&&!validColor(graph,nodecolor,1,i))
				return false;
        return true;
	}

	bool validColor(vector<vector<int> >& graph,vector<int>& nodecolor,int color,int node)
	{
		if(nodecolor[node]!=0)
			return nodecolor[node]==color;
		nodecolor[node]=color;
		for(int i=0;i<graph[node].size();i++)
			if(!validColor(graph,nodecolor,-color,graph[node][i]))
                return false;
        return true;
	}
};
