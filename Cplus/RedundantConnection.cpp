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
		parent.reserve(edges.size()+1);
		for(int i=0;i<edges.size()+1;i++)
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
		int tmp=x;
		while(parent[x]!=x)
			x=parent[x];
		return parent[tmp]=x;
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
