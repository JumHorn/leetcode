#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

class KthLargest
{
public:
	KthLargest(int k, vector<int> &nums)
	{
		size = k;
		for (auto n : nums)
			add(n);
	}

	int add(int val)
	{
		if ((int)q.size() < size)
			q.push(val);
		else if (q.top() < val)
		{
			q.pop();
			q.push(val);
		}
		return q.top();
	}

private:
	priority_queue<int, vector<int>, greater<int>> q;
	int size;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */