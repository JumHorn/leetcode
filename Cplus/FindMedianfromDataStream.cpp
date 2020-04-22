#include <queue>
using namespace std;

class MedianFinder
{
public:
	/** initialize your data structure here. */
	MedianFinder()
	{
		median = 0.0;
		count = 0;
	}

	void addNum(int num)
	{
		int left, right = num;
		++count;
		if (count == 1)
		{
			median = num;
			low.push(num);
			return;
		}
		if (count % 2 == 0)
			high.push(-num);
		else
			low.push(num);
		left = low.top();
		right = -high.top();
		if (left > right)
		{
			low.pop();
			high.pop();
			low.push(right);
			high.push(-left);
		}
		left = low.top();
		right = -high.top();
		if (count % 2 == 0)
			median = (left + right) / 2.0;
		else
			median = left;
	}

	double findMedian()
	{
		return median;
	}

private:
	double median;
	priority_queue<int> low;
	priority_queue<int> high;
	int count;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */