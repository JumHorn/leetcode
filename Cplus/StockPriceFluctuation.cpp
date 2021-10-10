#include <map>
#include <set>
using namespace std;

class StockPrice
{
public:
	StockPrice()
	{
	}

	void update(int timestamp, int price)
	{
		auto iter = m.find(timestamp);
		if (iter != m.end())
			s.erase(s.find(m[timestamp]));
		m[timestamp] = price;
		s.insert(price);
	}

	int current()
	{
		if (m.empty())
			return -1;
		return m.rbegin()->second;
	}

	int maximum()
	{
		return *s.rbegin();
	}

	int minimum()
	{
		return *s.begin();
	}

private:
	map<int, int> m; //{timestamp,price}
	multiset<int> s;
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */