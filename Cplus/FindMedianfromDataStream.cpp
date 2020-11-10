#include <functional>
#include <queue>
#include <vector>
using namespace std;

class MedianFinder
{
public:
	/** initialize your data structure here. */
	MedianFinder()
	{
	}

	void addNum(int num)
	{
		if (low.size() > high.size())
			high.push(num);
		else
			low.push(num);
		if (!high.empty() && low.top() > high.top())
		{
			int h = high.top(), l = low.top();
			high.pop();
			low.pop();
			high.push(l);
			low.push(h);
		}
	}

	double findMedian()
	{
		if (low.size() > high.size())
			return low.top();
		return (low.top() + high.top()) / 2.0;
	}

private:
	priority_queue<int> low;
	priority_queue<int, vector<int>, greater<int>> high;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */