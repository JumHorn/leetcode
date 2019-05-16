#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > insert(vector<vector<int> >& intervals, vector<int>& newInterval) {
		if(intervals.empty())
		{
			intervals.push_back(newInterval);
			return intervals;
		}
		if(newInterval[0]>intervals.back()[1])
		{
			intervals.push_back(newInterval);
			return intervals;
		}
		if(newInterval[1]<intervals[0][0])
		{
			intervals.insert(intervals.begin(),newInterval);
			return intervals;
		}
        vector<vector<int> > res;
		int i=0,j=intervals.size(),m=0,n=0;
		for(int k=0;k<(int)intervals.size();k++)
			if(newInterval[0]>=intervals[k][0])
				i=k;
		for(int k=i;k<(int)intervals.size();k++)
			if(newInterval[1]>=intervals[k][0])
				j=k+1;
		if(newInterval[0]<=intervals[i][1])
			m=min(intervals[i--][0],newInterval[0]);
		else
			m=newInterval[0];
		n=max(newInterval[1],intervals[j-1][1]);
		for(int k=0;k<=i;k++)
			res.push_back(intervals[k]);
		res.push_back(vector<int>({m,n}));
		for(int k=j;k<(int)intervals.size();k++)
			res.push_back(intervals[k]);
		return res;
    }
};
