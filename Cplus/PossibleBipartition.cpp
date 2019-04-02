#include<vector>
using namespace std;

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int> >& dislikes) {
        if(N==1)
            return true;
    	vector<int> group1(N+1);
    	vector<int> group2(N+1);
		for(int i=1;i<N+1;i++)
		{
			group1[i]=i;
			group2[i]=i;
		}
		int p1=dislikes[0][0],p2=dislikes[0][1];
		for(int i=1;i<(int)dislikes.size();i++)
		{
			if(p1==dislikes[i][0]||Union(group1,p1,dislikes[i][0]))
			{
				if(dislikes[i][1]!=Find(group1,dislikes[i][1]))
					return false;
				if(!Union(group2,p2,dislikes[i][1]))
					return false;
			}
			else if(p2==dislikes[i][0]||Union(group2,p2,dislikes[i][0]))
			{
				if(dislikes[i][1]!=Find(group2,dislikes[i][1]))
					return false;
				if(!Union(group1,p1,dislikes[i][1]))
					return false;
			}
			else
				return false;
		}
		return true;
    }

	int Find(vector<int>& parent,int x)
	{
		if(parent[x]!=x)
			parent[x]=Find(parent,parent[x]);
		return parent[x];
	}

	bool Union(vector<int>& parent,int x,int y)
	{
		int xr=Find(parent,x),yr=Find(parent,y);
		if(xr==yr)
			return false;
		parent[yr]=xr;
		return true;
	}
};
