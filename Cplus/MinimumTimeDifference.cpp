#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
		int res=INT_MAX;
		sort(timePoints.begin(),timePoints.end());       
		for(vector<string>::iterator iter=timePoints.begin();iter!=timePoints.end()-1;iter++)
		{
			int diff=timeDiff(iter,iter+1);
			if(diff<res)
				res=diff;
		}
		int tmp=24*60-timeDiff(timePoints.begin(),timePoints.end()-1);
		if(tmp<res)
			res=tmp;
		return res;
    }

	int timeDiff(vector<string>::iterator it1,vector<string>::iterator it2)
	{
		int t1=((*it1)[0]*10+(*it1)[1])*60+((*it1)[3]*10+(*it1)[4]);
		int t2=((*it2)[0]*10+(*it2)[1])*60+((*it2)[3]*10+(*it2)[4]);
		return t2-t1;
	}
};
