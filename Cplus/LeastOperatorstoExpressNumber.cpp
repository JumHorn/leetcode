#include<algorithm>
#include<unordered_map>
#include<climits>
using namespace std;

class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
		unordered_map<long,long> visited;
        return getTarget(x,target,visited);
    }

    long getTarget(long x, long target,unordered_map<long,long>& visited)
    {
        if(visited.find(target)!=visited.end())
			return visited[target];
        long res;
		if(target<=x)
        {
			res=min(2*target-1,2*(x-target));
            visited[target]=res;
            return res;
        }
		pair<long,long> large=getGreaterThan(x,target);
        pair<long,long> smalllarge={large.first/x,large.second-1};
		pair<long,long> small=getLessThan(x,target,smalllarge);

        if(large.first>=2*target)
            res=LONG_MAX;
        else
            res=getTarget(x,large.first-target,visited)+large.second+1;
        res=min(res,min(getTarget(x,smalllarge.first-target,visited)+smalllarge.second+1,
                        getTarget(x,target-small.first,visited)+small.second+1));

		visited[target]=res;
		return res;
    }

	pair<long,long> getGreaterThan(long x,long target)
	{
		long fx=x,i=0;
		while(fx<target)
		{
			i++;
			fx*=x;
		}
		return {fx,i};
	}

    pair<long,long> getLessThan(long x,long target,pair<long,long>& small)
	{
        long i;
        for(i=1;i<x;i++)
        {
            if(small.first*i>target)
                break;
        }
        pair<long,long> res={small.first*(i-1),small.second*(i-1)+(i-2)};
        small={small.first*i,small.second*i+(i-1)};
		return res;
	}
};