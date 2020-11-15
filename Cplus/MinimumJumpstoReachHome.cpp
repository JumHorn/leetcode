#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumJumps(vector<int> &forbidden, int a, int b, int x)
	{
		queue<pair<int, int>> q; //{pos,direction}
		unordered_set<int> s(forbidden.begin(), forbidden.end());
		vector<int> seen(5000);
		q.push({0, 0});
		seen[0] = 1;
		int res = 0;
		for (int res = 0; !q.empty(); ++res)
		{
			int size = q.size();
			for (int size = q.size(); size > 0; --size)
			{
				int at = q.front().first;
				int d = q.front().second;
				q.pop();
				if (at == x)
					return res;
				int forward = at + a, backward = at - b;
				if (forward < 5000 && s.find(forward) == s.end() && seen[forward] == 0)
				{
					seen[forward] = 1;
					q.push({forward, 0});
				}
				if (d < 1 && backward >= 0 && s.find(backward) == s.end() && seen[backward] == 0)
				{
					// seen[backward] = 1;
					q.push({backward, 1});
				}
			}
		}
		return -1;
	}
};