#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int> >& graph) {
        unordered_set<int> safe,unsafe,visited;
		vector<int> res;
		eventualSafeNodes(graph,safe,unsafe,res,0,visited);
		sort(res.begin(),res.end());
		return res;
    }
	void eventualSafeNodes(vector<vector<int> >& graph,unordered_set<int>& safe,unordered_set<int>& unsafe,vector<int>& res,int start,unordered_set<int>& visited)
	{
		if(safe.find(start)!=safe.end())
			return;
		if(unsafe.find(start)!=unsafe.end())
			return;
		if(visited.find(start)!=visited.end())
		{
			unsafe.insert(start);
			return;
		}
		for(int i=start;i<graph[start].size();i++)
		{
			visited.insert(i);
			eventualSafeNodes(graph,safe,unsafe,res,graph[start][i],visited);
			visited.erase(visited.find(i));
		}
	}
};
