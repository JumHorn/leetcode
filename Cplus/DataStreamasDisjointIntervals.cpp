#include<vector>
#include<list>
using namespace std;

//Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class SummaryRanges {
	list<Interval> l;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {

    }

    void addNum(int val) {
        if(l.empty())
        {
            l.push_back(Interval(val,val));
            return;
        }
		bool flag=true;
        for(list<Interval>::iterator iter=l.begin();iter!=l.end();++iter)
		{
			if(iter->start>val)
			{
				flag=false;
				if(iter==l.begin())
				{
					if(iter->start-val==1)
						iter->start=val;
					else
						l.insert(iter,Interval(val,val));
				}
				else
				{
					if(iter->start-val==1)
					{
						iter->start=val;
						int tmp=iter->end;
						--iter;
						if(val-iter->end==1)
						{
							iter->end=tmp;
							l.erase(++iter);
						}
					}
					else
					{
						--iter;
						if(val-iter->end==1)
							iter->end=val;
						else if(val>iter->end+1)
							l.insert(++iter,Interval(val,val));
					}
				}
                return;
			}
		}
		if(flag)
		{
			if(val>l.back().end+1)
				l.push_back(Interval(val,val));
			else if(val-l.back().end==1)
				l.back().end=val;
		}
    }

    vector<Interval> getIntervals() {
        return vector<Interval>(l.begin(),l.end());
    }
};
