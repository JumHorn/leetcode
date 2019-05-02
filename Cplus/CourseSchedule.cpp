#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {
        unordered_set<int> visited(numCourses);
		vector<vector<int> > adjacencymetrices(numCourses);
		for(int i=0;i<(int)prerequisites.size();i++)
			adjacencymetrices[prerequisites[i][0]].push_back(prerequisites[i][1]);
		for(int i=0;i<numCourses;i++)
		{
			if(visited.find(i)==visited.end()&&!canFinish(visited,adjacencymetrices,i))
				return false;
		}
		return true;
    }

	bool canFinish(unordered_set<int>& visited,vector<vector<int> >& graph,int start)
	{
		visited.insert(start);
		for(int i=0;i<(int)graph[start].size();i++)
		{
			if(visited.find(graph[start][i])!=visited.end())
				return false;
			if(!canFinish(visited,graph,graph[start][i]))
				return false;
		}
        visited.erase(visited.find(start));
		return true;
	}
};
