#include<vector>
using namespace std;

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int> >& dislikes) {
		vector<vector<int> > graph(N+1,vector<int>());
		for(int i=0;i<(int)dislikes.size();i++)
			graph[dislikes[i][0]].push_back(dislikes[i][1]);
		vector<int> color(N+1);
		for(int i=1;i<(int)graph.size();i++)
			if(color[i]==0&&!possibleBipartion(graph,color,i,1))
				return false;
		return true;
    }

	bool possibleBipartion(vector<vector<int> >& graph,vector<int>& color,int n,int c)
	{
		if(color[n]!=0)
			return color[n]!=c;
		color[n]=c;
		for(int i=0;i<(int)graph[n].size();i++)
			if(!possibleBipartion(graph,color,graph[n][i],-c))
				return false;
		return true;
	}
};
