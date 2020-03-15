#include <vector>
using namespace std;

class CustomStack
{
public:
	CustomStack(int maxSize)
	{
		size = maxSize;
	}

	void push(int x)
	{
		if ((int)v.size() < size)
			v.push_back(x);
	}

	int pop()
	{
		if (v.empty())
			return -1;
		int res = v.back();
		v.pop_back();
		return res;
	}

	void increment(int k, int val)
	{
		for (int i = 0; i < k && i < (int)v.size(); i++)
			v[i] += val;
	}

private:
	vector<int> v;
	int size;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
