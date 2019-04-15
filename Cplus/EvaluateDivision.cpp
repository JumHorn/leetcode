#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string> > equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string,map<string,double> > graph;
		for(int i=0;i<(int)equations.size();i++)
		{
			graph[equations[i].first][equations[i].second]=values[i];
			graph[equations[i].second][equations[i].first]=1.0/values[i];
		}
		vector<double> res(queries.size(),1.0);
		for(int i=0;i<(int)queries.size();i++)
		{
			if(graph.find(queries[i].first)==graph.end()||graph.find(queries[i].second)==graph.end())
			{
				res[i]=-1.0;
				continue;
			}
			unordered_set<string> visited;
			visited.insert(queries[i].first);
			if(!calcEquation(graph,visited,queries[i].first,queries[i].second,res[i]))
				res[i]=-1.0;
		}
		return res;
    }
	
	bool calcEquation(unordered_map<string,map<string,double> >& graph,unordered_set<string>& visited,const string& src,string& dst,double& value)
	{
		if(src==dst)
			return true;
		map<string,double>::iterator iter=graph[src].find(dst);
		if(iter!=graph[src].end())
		{
			value*=iter->second;
			return true;
		}
		for(iter=graph[src].begin();iter!=graph[src].end();++iter)
		{
			if(visited.find(iter->first)==visited.end())
			{
				visited.insert(iter->first);
				value*=iter->second;
				if(calcEquation(graph,visited,iter->first,dst,value))
					return true;
				value/=iter->second;
			}
		}
		return false;
	}
};
