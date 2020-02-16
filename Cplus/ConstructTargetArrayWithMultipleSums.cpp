#include <algorithm>
#include <queue>
#include <unordered_set>
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
			int tmp = q.top();
			q.pop();
			if (tmp == 1)
				return true;
			sum -= tmp;
			if (sum == 1)
				return true;
			if (tmp < sum)
				return false;
			tmp = tmp - tmp / sum * sum;
			sum += tmp;
			if (tmp < 1)
				return false;
			q.push(tmp);
		}
		return false;
	}
};