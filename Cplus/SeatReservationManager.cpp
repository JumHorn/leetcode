#include <set>
using namespace std;

class SeatManager
{
public:
	SeatManager(int n)
	{
		for (int i = 1; i <= n; ++i)
			s.insert(i);
	}

	int reserve()
	{

		int res = *s.begin();
		s.erase(res);
		return res;
	}

	void unreserve(int seatNumber)
	{
		s.insert(seatNumber);
	}

private:
	set<int> s;
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */