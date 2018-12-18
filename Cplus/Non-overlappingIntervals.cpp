#include<algorithm>
#include<vector>
using namespace std;
//Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
		int res=0,len=0;
        sort(intervals.begin(),intervals.end(),*this);
		while(len<intervals.size())
		{
            int i;
			for(i=len+1;i<intervals.size();i++)
			{
				if(intervals[i].start<intervals[len].end)
				{
					res++;
				}
				else
				{
                    len=i;
					break;
				}
			}
            if(i==intervals.size())
                break;
		}
		return res;
    }

	bool operator()(const Interval& i1,const Interval& i2)
	{
		if(i1.end<i2.end)
			return true;
		else if(i1.end>i2.end)
			return false;
		if(i1.start<i2.start)
			return true;
		return false;
	}
};
