#include<climits>
#include<string>
using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
		return findRotateSteps(ring,0,key,0);
    }

	int findRotateSteps(const string& ring,int r,const string& key,int k)
	{
		if(k==(int)key.length())
			return 0;
		int n=ring.size(),res=INT_MAX,tmp,radius=0;
		if(ring[r]==key[k])
			return findRotateSteps(ring,r,key,k+1)+1;
		while(++radius<=ring.size()/2)
		{
			tmp=(r+radius)%n;
			if(ring[tmp]==key[k])
			{
				res=min(res,findRotateSteps(ring,tmp,key,k+1)+radius+1);
			}
			tmp=(r-radius+n)%n;
			if(ring[tmp]==key[k])
			{
				res=min(res,findRotateSteps(ring,tmp,key,k+1)+radius+1);
			}
		}
		return res;
	}
};