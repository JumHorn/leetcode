#include<vector>
#include<unordered_map>
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
		unordered_map<int,int> factor;
	    for(int i=0;i<(int)A.size();i++)
		{
			for(int j=2;j*j<=A[i];j++)
			{
				if(A[i]%j==0)
				{
					if(factor.find(j)==factor.end())
						factor[j]=i;
					else
						dsu.Union(i,factor[j]);
					if(factor.find(A[i]/j)==factor.end())
						factor[A[i]/j]=i;
					else
						dsu.Union(i,factor[A[i]/j]);
				}
			}
			if(factor.find(A[i])==factor.end())
				factor[A[i]]=i;
			else
				dsu.Union(i,factor[A[i]]);
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
