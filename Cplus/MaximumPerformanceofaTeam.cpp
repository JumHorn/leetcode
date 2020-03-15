#include <climits>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
	{
		static const int MOD = 1e9 + 7;
		int index = 0;
		queue<int> q;
		long long res = 0, s = 0, e = INT_MAX;
		for (int i = 0; i < n; i++)
		{
			long long p = (long long)speed[i] * (long long)efficiency[i];
			if (p > res)
			{
				res = p;
				index = i;
			}
		}
		for (int i = 0; i < n; i++)
			if (i != index)
				q.push(i);
		unordered_set<int> seen;
		while (--k > 0 && !q.empty())
		{
			int size = q.size();
			seen.insert(index);
			s += speed[index];
			e = min(e, (long long)efficiency[index]);
			bool flag = false;
			while (--size >= 0)
			{
				int tmp = q.front();
				q.pop();
				if (seen.find(tmp) != seen.end())
					continue;
				long long p = (s + speed[tmp]) * min(e, (long long)efficiency[tmp]);
				if (p > res)
				{
					flag = true;
					res = p;
					index = tmp;
				}
				q.push(tmp);
			}
			if (!flag)
				break;
		}
		return res % MOD;
	}
};