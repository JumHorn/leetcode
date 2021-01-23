#include <map>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	bool isPossibleDivide(vector<int> &nums, int k)
	{
		int N = nums.size();
		if (N % k != 0)
			return false;
		map<int, int> m; //{val,count}
		for (auto n : nums)
			++m[n];
		queue<int> q;
		int opened = 0, last = -1;
		for (auto &n : m)
		{
			if ((opened > 0 && n.first - last > 1) || opened > n.second)
				return false;
			q.push(n.second - opened);
			last = n.first;
			opened = n.second;
			if (q.size() == k)
			{
				opened -= q.front();
				q.pop();
			}
		}
		return opened == 0;
	}
};