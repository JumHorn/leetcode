#include<vector>
#include<string>
using namespace std;

class DSU
{
public:
	DSU(int size):parent(size),rank(size,1)
	{
		for(int i=0;i<size;i++)
			parent[i]=i;
	}

	int Find(int x)
	{
		if(x!=parent[x])
			parent[x]=Find(parent[x]);
		return parent[x];
	}

	bool Union(int x,int y)
	{
		int xr=Find(x),yr=Find(y);
		if(xr==yr)
			return false;
		parent[yr]=xr;
		rank[xr]+=rank[yr];
		return true;
	}

	int countGroup()
	{
		int res=0;
		for(int i=0;i<(int)parent.size();i++)
			if(parent[i]==i)
				res++;
		return res;
	}
private:
	vector<int> parent;
	vector<int> rank;
};

class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
		DSU dsu(A.size());
        for(int i=0;i<(int)A.size();i++)
			for(int j=i+1;j<(int)A.size();j++)
				if(strDiff(A[i],A[j]))
					dsu.Union(i,j);
		return dsu.countGroup();
    }

	bool strDiff(const string& lhs,const string& rhs)
	{
		int res=0;
		for(int i=0;i<(int)lhs.length();i++)
			if(lhs[i]!=rhs[i])
				res++;
		return res==2||res==0;
	}
};
