#include <map>
using namespace std;

class MyCalendarTwo
{
public:
	MyCalendarTwo()
	{
	}

	bool book(int start, int end)
	{
		++boundary[start];
		--boundary[end];
		int active = 0, res = 0;
		for (auto &n : boundary)
		{
			active += n.second;
			res = max(res, active);
		}
		if (res < 3)
			return true;
		//reset
		--boundary[start];
		++boundary[end];
		return false;
	}

private:
	map<int, int> boundary;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */