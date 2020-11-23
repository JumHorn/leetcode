#include <map>
#include <set>
#include <stack>
#include <vector>
using namespace std;

class DinnerPlates
{
public:
	DinnerPlates(int capacity)
	{
		c = capacity;
	}

	void push(int val)
	{
		if (available.empty())
			available.insert(data.size());

		data[*available.begin()].push(val);
		if (data[*available.begin()].size() == c)
			available.erase(available.begin());
	}

	int pop()
	{
		while (!data.empty() && data.rbegin()->second.empty())
			data.erase(data.rbegin()->first);

		if (data.empty())
			return -1;
		return popAtStack(data.rbegin()->first);
	}

	int popAtStack(int index)
	{
		if (data[index].empty())
			return -1;
		int val = data[index].top();
		data[index].pop();
		available.insert(index);
		if (data[index].empty())
			data.erase(index);
		return val;
	}

private:
	int c;
	map<int, stack<int>> data;
	set<int> available; //keep indices of all not full stacks.
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */