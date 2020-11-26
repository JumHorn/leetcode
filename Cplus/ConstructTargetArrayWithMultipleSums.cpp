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
			sum -= largest;
			if (largest == 1 || sum == 1)
				return true;
			if (largest < sum || sum == 0 || largest % sum == 0)
				return false;
			largest %= sum; //for single large element,substract many times
			sum += largest;
			q.push(largest);
		}
		return false;
	}
};