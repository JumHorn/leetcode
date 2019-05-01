#include<vector>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {
        vector<int> color(numCourses);
		vector<vector<int> > adjacencymetrices(numCourses);
		for(int i=0;i<(int)prerequisites.size();i++)
		{
			adjacencymetrices[prerequisites[i][0]].push_back(prerequisites[i][1]);
		}
		for(int i=0;i<(int)color.size();i++)
		{
			if(color[i]==0&&!canFinish(color,adjacencymetrices,i,1))
				return false;
		}
		return true;
    }

	bool canFinish(vector<int>& color,vector<vector<int> >& graph,int start,int c)
	{
		if(color[start]!=0)
			return color[start]==c;
		color[start]=c;
		for(int i=0;i<(int)graph[start].size();i++)
			if(!canFinish(color,graph,graph[start][i],-c))
				return false;
		return true;
	}
};
