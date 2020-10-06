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
		int sum = 0;
		for (auto &n : boundary)
		{
			sum += n.second;
			if (sum >= 3)
			{
				if (--boundary[start] == 0)
					boundary.erase(start);
				if (++boundary[end] == 0)
					boundary.erase(end);
				return false;
			}
		}
		return true;
	}

private:
	map<int, int> boundary;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */