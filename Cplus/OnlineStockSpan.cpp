#include <stack>
using namespace std;

class StockSpanner
{
public:
	StockSpanner()
	{
		index = 0;
	}

	int next(int price)
	{
		while (!s.empty() && s.top().second <= price)
			s.pop();
		int res = index - (s.empty() ? -1 : s.top().first);
		s.push({index++, price});
		return res;
	}

private:
	stack<pair<int, int>> s; //{index,value}
	int index;				 //current index
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */