#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	bool isPossible(vector<int> &target)
	{
		priority_queue<int> q;
		long sum = 0;
		for (auto n : target)
		{
			q.push(n);
			sum += n;
		}
		while (!q.empty())
		{
			int largest = q.top();
			q.pop();
			if (largest == 1)
				return true;
			sum -= largest;
			if (sum == 1) //only two number,the other is 1
				return true;
			if (largest < sum || sum == 0)
				return false;
			largest = largest - largest / sum * sum; //for single large element,substract many times
			sum += largest;
			if (largest < 1)
				return false;
			q.push(largest);
		}
		return false;
	}
};