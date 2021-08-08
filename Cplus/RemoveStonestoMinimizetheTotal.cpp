#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int minStoneSum(vector<int> &piles, int k)
	{
		priority_queue<int> q;
		int res = 0;
		for (auto n : piles)
		{
			q.push(n);
			res += n;
		}
		for (int i = 0; i < k && !q.empty(); ++i)
		{
			int n = q.top();
			q.pop();
			res -= n / 2;
			n = n - n / 2;
			if (n != 0)
				q.push(n);
		}
		return res;
	}
};