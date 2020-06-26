#include <map>
#include <algorithm>
using namespace std;

class MyCalendarThree
{
public:
	MyCalendarThree()
	{
	}

	int book(int start, int end)
	{
		++boundary[start];
		--boundary[end];
		int active = 0, res = 0;
		for (auto &n : boundary)
		{
			active += n.second;
			res = max(res, active);
		}
		return res;
	}

private:
	map<int, int> boundary;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
