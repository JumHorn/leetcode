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
        // for(int i=0;i<intervals.size();i++)
        // {
        //     cout<<intervals[i].start<<" "<<intervals[i].end<<endl;
        // }
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
		return false;
	}
};
