#include<list>
using namespace std;

class MyCalendar {
public:
	list<pair<int,int> > l;
    MyCalendar() {
        l.push_back(make_pair(-1,-1));
    }
    
    bool book(int start, int end) {
        for(list<pair<int,int> >::iterator iter=l.begin();iter!=l.end();iter++)
		{
			list<pair<int,int> >::iterator tmp=iter;
			tmp++;
			if(start>iter->first&&(tmp==l.end()||start<tmp->first))
			{
				if(start<iter->second)
					return false;
				tmp=iter;
				tmp++;
				if(tmp==l.end())
				{
					l.insert(tmp,make_pair(start,end));
					return true;
				}
				else
				{
					if(end>tmp->first)
						return false;
					else
					{
						l.insert(tmp,make_pair(start,end));
						return true;
					}
				}
			}
		}
		return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
