#include<vector>
using namespace std;
//  For all the node
//  traverse the graph to find the value appeared three times 
//  if we can not find one,return the last one
//  If we can, return the value last appeared
class Solution {
public:
	vector<int> parent;
    vector<int> findRedundantConnection(vector<vector<int> >& edges) {
		parent.reserve(1001);
		for(int i=0;i<1001;i++)
			parent[i]=i;
		vector<vector<int> >::iterator iter;
		for(iter=edges.begin();iter!=edges.end();iter++)
		{
			if(!Union(iter->at(0),iter->at(1)))
			{
				return *iter;
			}
		}
		return vector<int>();
    }

	int Find(int x)
	{
		if(parent[x]!=x)
			parent[x]=Find(parent[x]);
		return parent[x];
	}

	bool Union(int x,int y)
	{
		int xr=Find(x),yr=Find(y);
		if(xr==yr)
			return false;
		parent[yr]=xr;
		return true;
	}
};
