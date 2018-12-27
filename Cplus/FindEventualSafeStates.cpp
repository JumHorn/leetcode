#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int> >& graph) {
        vector<int> state(graph.size());//0 unvisited 1 safe 2 unsafe
		vector<int> res;
		for(int i=0;i<graph.size();i++)
			if(eventualSafeNodes(graph,state,i))
				res.push_back(i);
		return res;
    }
	bool eventualSafeNodes(vector<vector<int> >& graph,vector<int>& state,int start)
	{
		if(state[start]!=0)
			return state[start]==1;
        state[start]=2;
		for(int i=0;i<graph[start].size();i++)
		{
			if(!eventualSafeNodes(graph,state,graph[start][i]))
			{
				state[start]=2;
				return false;
			}
		}
		state[start]=1;
		return true;
	}
};
