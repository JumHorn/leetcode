#include <stack>
#include <vector>
using namespace std;

class DinnerPlates
{
public:
	DinnerPlates(int capacity)
	{
		c = capacity;
		s = 0; //size
		p = 0; //push index
		v = 0; //pop index
	}

	void push(int val)
	{
		++s;
		while (p < data.size() && data[p].size() == c)
			++p;
		if (p < data.size())
			data[p].push(val);
		else
		{
			data.emplace_back();
			data.back().push(val);
		}
		if (p > v)
			v = p;
	}

	int pop()
	{
		if (s == 0)
			return -1;
		--s;
		int res = -1;
		while (v >= 0 && data[v].empty())
			--v;
		res = data[v].top();
		data[v].pop();
		if (p > v)
			p = v;
		return res;
	}

	int popAtStack(int index)
	{
		int res = -1;
		if (index < (int)data.size())
		{
			if (!data[index].empty())
			{
				--s;
				res = data[index].top();
				data[index].pop();
				if (p > index)
					p = index;
			}
		}
		return res;
	}

private:
	vector<stack<int>> data;
	int s, c, p, v;
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */