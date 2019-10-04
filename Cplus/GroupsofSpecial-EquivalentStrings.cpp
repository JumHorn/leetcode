#include<vector>
#include<string>
using namespace std;

class DSU
{
public:
	DSU(int size):parent(size)
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
};

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        DSU dsu(A.size());
        for(int i=0;i<(int)A.size()-1;i++)
            for(int j=i+1;j<(int)A.size();j++)
                if(specialEquivalent(A[i],A[j]))
                    dsu.Union(i,j);
        return dsu.countGroup();
    }

    bool specialEquivalent(const string& lhs,const string& rhs)
    {
        int even[26]={0};
        for(int i=0;i<(int)lhs.length();i+=2)
        {
            even[lhs[i]-'a']++;
            even[rhs[i]-'a']--;
        }
        for(int i=0;i<26;i++)
            if(even[i]!=0)
                return false;

        int odd[26]={0};
        for(int i=1;i<(int)lhs.length();i+=2)
        {
            odd[lhs[i]-'a']++;
            odd[rhs[i]-'a']--;
        }
        for(int i=0;i<26;i++)
            if(odd[i]!=0)
                return false;
        return true;
    }
};
