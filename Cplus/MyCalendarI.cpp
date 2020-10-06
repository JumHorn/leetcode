#include <set>
using namespace std;

class MyCalendar
{
public:
	MyCalendar()
	{
	}

	bool book(int start, int end)
	{
		auto iter = s.lower_bound({start, end});
		if (iter != s.end())
		{
			if (end > iter->first)
				return false;
		}
		if (iter != s.begin())
		{
			--iter;
			if (iter->second > start)
				return false;
		}
		s.insert({start, end});
		return true;
	}

private:
	set<pair<int, int>> s;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */