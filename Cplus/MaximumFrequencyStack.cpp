#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class FreqStack
{
public:
	FreqStack()
	{
		data.emplace_back(); // 0 reserved
	}

	void push(int x)
	{
		int f = ++freq[x];
		if (f >= data.size())
			data.emplace_back();
		data[f].push(x);
		if (f > maxFreq)
			maxFreq = f;
	}

	int pop()
	{
		int res = data[maxFreq].top();
		data[maxFreq].pop();
		--freq[res];
		if (data[maxFreq].empty())
			--maxFreq;
		return res;
	}

private:
	int maxFreq;				  //continuous
	vector<stack<int>> data;	  // {freq ,val stack}
	unordered_map<int, int> freq; // {val ,freq}
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */