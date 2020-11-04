#include <string>
#include <vector>
using namespace std;

class BrowserHistory
{
public:
	BrowserHistory(string homepage)
	{
		history.push_back(homepage);
		top = 0;
		size = 1;
	}

	void visit(string url)
	{
		size = ++top + 1;
		if (top >= (int)history.size())
			history.push_back(url);
		else
			history[top] = url;
	}

	string back(int steps)
	{
		top -= steps;
		if (top < 0)
			top = 0;
		return history[top];
	}

	string forward(int steps)
	{
		top += steps;
		if (top >= size)
			top = size - 1;
		return history[top];
	}

private:
	vector<string> history;
	int size;
	int top;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */