#include <cmath>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	long long pickGifts(vector<int> &gifts, int k)
	{
		priority_queue<int> q;
		for (auto n : gifts)
			q.push(n);
		while (--k >= 0)
		{
			int n = q.top();
			q.pop();
			q.push(sqrt(n));
		}
		long long res = 0;
		while (!q.empty())
		{
			res += q.top();
			q.pop();
		}
		return res;
	}
};