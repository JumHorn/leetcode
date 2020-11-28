#include <list>
using namespace std;

class FrontMiddleBackQueue
{
public:
	FrontMiddleBackQueue()
	{
	}

	void pushFront(int val)
	{
		data.push_front(val);
	}

	void pushMiddle(int val)
	{
		int N = data.size();
		auto iter = next(data.begin(), N / 2);
		data.insert(iter, val);
	}

	void pushBack(int val)
	{
		data.push_back(val);
	}

	int popFront()
	{
		if (data.empty())
			return -1;
		int res = data.front();
		data.pop_front();
		return res;
	}

	int popMiddle()
	{
		if (data.empty())
			return -1;
		int N = data.size();
		auto iter = next(data.begin(), (N - 1) / 2);
		int res = *iter;
		data.erase(iter);
		return res;
	}

	int popBack()
	{
		if (data.empty())
			return -1;
		int res = data.back();
		data.pop_back();
		return res;
	}

private:
	list<int> data;
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */