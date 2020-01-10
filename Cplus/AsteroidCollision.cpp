#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> asteroidCollision(vector<int>& asteroids)
	{
		vector<int> res;
		stack<int> s;
		for (int i = 0; i < (int)asteroids.size(); i++)
		{
			if (asteroids[i] > 0)
				s.push(asteroids[i]);
			else
			{
				bool flag = true;
				while (!s.empty())
				{
					if (-asteroids[i] > s.top())
						s.pop();
					else if (-asteroids[i] == s.top())
					{
						flag = false;
						s.pop();
						break;
					}
					else
						break;
				}
				if (flag && s.empty())
					res.push_back(asteroids[i]);
			}
		}
		vector<int> right;
		while (!s.empty())
		{
			right.push_back(s.top());
			s.pop();
		}
		for (int i = right.size() - 1; i >= 0; i--)
			res.push_back(right[i]);
		return res;
	}
};
