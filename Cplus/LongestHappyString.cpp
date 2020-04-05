#include <queue>
#include <string>
using namespace std;

class Solution
{
public:
	string longestDiverseString(int a, int b, int c)
	{
		string res;
		priority_queue<pair<int, char>> q;
		if (a > 0)
			q.push({a, 'a'});
		if (b > 0)
			q.push({b, 'b'});
		if (c > 0)
			q.push({c, 'c'});
		//first one
		auto tmp = q.top();
		q.pop();
		res.push_back(tmp.second);
		if (tmp.first - 1 > 0)
			q.push({tmp.first - 1, tmp.second});
		//second one
		if (q.empty())
			return res;
		tmp = q.top();
		q.pop();
		res.push_back(tmp.second);
		if (tmp.first - 1 > 0)
			q.push({tmp.first - 1, tmp.second});
		//the other
		while (!q.empty())
		{
			tmp = q.top();
			q.pop();
			int n = res.length();
			if (tmp.second == res[n - 1] && tmp.second == res[n - 2])
			{
				if (q.empty())
					break;
				auto top = q.top();
				q.pop();
				res.push_back(top.second);
				if (top.first - 1 > 0)
					q.push({top.first - 1, top.second});
			}
			else
			{
				res.push_back(tmp.second);
				--tmp.first;
			}
			if (tmp.first > 0)
				q.push({tmp.first, tmp.second});
		}
		return res;
	}
};