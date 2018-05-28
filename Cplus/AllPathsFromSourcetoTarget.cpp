#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
	vector<vector<int> > *m_pGraph;
    vector<vector<int> > result;
public:
    vector<vector<int> > allPathsSourceTarget(vector<vector<int> >& graph) {
	   this->m_pGraph = &graph;
	   vector<int> path;
	   path.push_back(0);
	   recursive(path);
	   return result;
    }

	void recursive(vector<int> path)
	{
		for(int i=0;i<(*m_pGraph)[path[path.size()-1]].size();i++)
		{
			if((*m_pGraph)[path[path.size()-1]][i]==m_pGraph->size()-1)
			{
				vector<int> temp = path;
				temp.push_back(m_pGraph->size()-1);
				result.push_back(temp);
			}
			else
			{
				//TODO 消除成环的图
				vector<int> temp = path;
				temp.push_back((*m_pGraph)[path[path.size()-1]][i]);
				recursive(temp);
			}
		}
	}
};
