#include<list>
using namespace std;

class MyCalendarTwo {
	list<pair<int,int> > _single;//ordered
	list<pair<int,int> > _double;//no order
public:
    MyCalendarTwo() {

    }

    bool book(int start, int end) {
		for(list<pair<int,int> >::iterator iter=_double.begin();iter!=_double.end();iter++)
            if((start<=iter->first&&end>iter->first)||(start<iter->second&&start>=iter->first))
				return false;
        for(list<pair<int,int> >::iterator iter=_single.begin();iter!=_single.end();iter++)
        {
            if(end<=iter->first)
            {
                _single.insert(iter,pair<int,int>(start,end));
                start=end;
                break;
            }
            if(start>=iter->first&&start<iter->second&&end>=iter->second)
            {
                _double.push_back(pair<int,int>(start,iter->second));
                swap(iter->second,start);
                if(iter->first>=iter->second)
                {
                    iter=_single.erase(iter);
                    iter--;
                }
            }
            else if(start<=iter->first&&end>=iter->second)
            {
                if(iter->first!=start)
                    _single.insert(iter,pair<int,int>(start,iter->first));
                _double.push_back(pair<int,int>(iter->first,iter->second));
                start=iter->second;
            }
            else if(start<=iter->first&&end<iter->second)
            {
                if(iter->first!=start)
                    _single.insert(iter,pair<int,int>(start,iter->first));
                _double.push_back(pair<int,int>(iter->first,end));
                iter->first=end;
                start=end;
            }
            else if(start>=iter->first&&start<iter->second&&end<iter->second)
            {
                _double.push_back(pair<int,int>(start,end));
                if(iter->first!=start)
                    _single.insert(iter,pair<int,int>(iter->first,start));
                iter->first=end;
                start=end;
            }
            if(start>=end)
                break;
        }
        if(start<end)
        {
            _single.push_back(pair<int,int>(start,end));
        }
		return true;
    }

	void swap(int& a,int& b)
	{
		a^=b;
		b^=a;
		a^=b;
	}
};
