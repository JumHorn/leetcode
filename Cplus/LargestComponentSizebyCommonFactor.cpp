#include<vector>
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

	int getMaxCluster()
	{
		int res=1;
		for(int i=0;i<(int)rank.size();i++)
			if(parent[i]==i&&rank[i]>res)
				res=rank[i];
		return res;
	}
	
private:
	vector<int> parent;
	vector<int> rank;
};

class Solution {
public:
    int largestComponentSize(vector<int>& A) {
		DSU dsu(A.size());
	    for(int i=0;i<(int)A.size()-1;i++)
			for(int j=i+1;j<(int)A.size();j++)
			{
                int tmp=gcd(A[i],A[j]);
				if(gcd(A[i],A[j])>1)
					dsu.Union(i,j);
			}	
		return dsu.getMaxCluster();
    }
private:
	int gcd(int x,int y)
	{
		if(x==0)
			return y;
		return gcd(y%x,x);
	}
};