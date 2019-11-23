#include <algorithm>
#include <queue>
#include <set>
using namespace std;

class Solution
{
public:
	bool canMeasureWater(int x, int y, int z)
	{
		if (z > x + y)
			return false;
		if (z == 0 || z == x || z == y || z == x + y)
			return true;
		set<pair<int, int>> s;
		queue<pair<int, int>> q;
		q.push({x, y});
		s.insert({x, y});
		int a, b;
		while (!q.empty())
		{
			int size = q.size();
			while (--size >= 0)
			{
				a = q.front().first;
				b = q.front().second;
				if (z == a || z == b || z == a + b)
					return true;
				q.pop();
				if (s.find({0, b}) == s.end())
				{
					s.insert({0, b});
					q.push({0, b});
				}
				if (s.find({x, b}) == s.end())
				{
					s.insert({x, b});
					q.push({x, b});
				}
				if (s.find({a, 0}) == s.end())
				{
					s.insert({a, 0});
					q.push({a, 0});
				}
				if (s.find({a, y}) == s.end())
				{
					s.insert({a, y});
					q.push({a, y});
				}
				//a->b
				int a1 = max(0, a - (y - b));
				int b1 = min(y, b + a);
				if (s.find({a1, b1}) == s.end())
				{
					s.insert({a1, b1});
					q.push({a1, b1});
				}
				//b->a
				a1 = min(x, a + b);
				b1 = max(0, b - (x - a));
				if (s.find({a1, b1}) == s.end())
				{
					s.insert({a1, b1});
					q.push({a1, b1});
				}
			}
		}
		return false;
	}
};