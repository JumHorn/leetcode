#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<int> res(numCourses),parents(numCourses);
		set<int> noParents;
		vector<set<int>> children(numCourses);		
		for(int i=0;i<(int)prerequisites.size();i++)
		{
			++parents[prerequisites[i][0]];
			children[prerequisites[i][1]].insert(prerequisites[i][0]);
		}
		for(int i=0;i<numCourses;i++)
			if(parents[i]==0)
				noParents.insert(i);
		for(int i=0;i<numCourses;i++)
		{
			if(noParents.empty())
				return vector<int>();
			int orphan=*noParents.begin();
			noParents.erase(orphan);
			res[i]=orphan;
			for(set<int>::iterator iter=children[orphan].begin();iter!=children[orphan].end();++iter)
				if(--parents[*iter]==0)
					noParents.insert(*iter);
		}
		return res;
    }
};
