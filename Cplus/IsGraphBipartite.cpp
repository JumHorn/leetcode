#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int> >& graph) {
		vector<char> color(graph.size());
        for(int i=0;i<(int)graph.size();i++)
		    if(color[i]==0&&!isBipartite(graph,color,i,1))
                return false;
        return true;
	}

	bool isBipartite(vector<vector<int> >& graph,vector<char>& color,int n,char c)
	{
		if(color[n]!=0)
			return color[n]==c;
		color[n]=c;
		for(int i=0;i<(int)graph[n].size();i++)
		{
			if(!isBipartite(graph,color,graph[n][i],-c))
				return false;
		}
		return true;
	}
};
