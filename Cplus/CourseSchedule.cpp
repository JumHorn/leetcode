#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {
        vector<int> visited(numCourses);
		vector<int> mem(numCourses);
		vector<vector<int> > adjacencymetrices(numCourses);
		for(int i=0;i<(int)prerequisites.size();i++)
			adjacencymetrices[prerequisites[i][0]].push_back(prerequisites[i][1]);
		for(int i=0;i<numCourses;i++)
		{
			if(visited[i]==0&&!canFinish(visited,mem,adjacencymetrices,i))
				return false;
		}
		return true;
    }

	bool canFinish(vector<int>& visited,vector<int>& mem,vector<vector<int> >& graph,int start)
	{
		if(mem[start]==1)
			return false;
		if(visited[start]==1)
			return true;
		visited[start]=mem[start]=1;
		for(int i=0;i<(int)graph[start].size();i++)
		{
			if(!canFinish(visited,mem,graph,graph[start][i]))
				return false;
		}
        mem[start]=0;
		return true;
	}
};
