#include<vector>
#include<algorithm>
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
    vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> res;
        sort(intervals.begin(),intervals.end(),*this);
		Interval tmp(intervals[0]);
		for(int i=1;i<(int)intervals.size();i++)
		{
			if(intervals[i].start<=tmp.end)
				tmp.end=max(tmp.end,intervals[i].end);
			else
			{
				res.push_back(tmp);
				tmp=intervals[i];
			}
		}
		if(tmp!=res.back())
			res.push_back(tmp);
		return res;
    }

	bool operator()(Interval& left,Interval& right)
	{
		if(left.start<right.start)
			return true;
		if(left.start>right.start)
			return false;
		if(left.end<right.end)
			return true;
		return false;
	}
};
