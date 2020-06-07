#include <string>
#include <vector>
using namespace std;

class BrowserHistory
{
public:
	BrowserHistory(string homepage)
	{
		history.push_back(homepage);
		cur = 0;
	}

	void visit(string url)
	{
		++cur;
		int size = history.size();
		while (size > cur)
		{
			history.pop_back();
			size = history.size();
		}
		history.push_back(url);
	}

	string back(int steps)
	{
		cur -= steps;
		if (cur < 0)
			cur = 0;
		return history[cur];
	}

	string forward(int steps)
	{
		int size = history.size();
		cur += steps;
		if (cur >= size)
			cur = size - 1;
		return history[cur];
	}

private:
	vector<string> history;
	int cur;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
