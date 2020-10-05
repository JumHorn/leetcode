#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> asteroidCollision(vector<int> &asteroids)
	{
		vector<int> res;
		stack<int> s;
		for (auto asteroid : asteroids)
		{
			if (asteroid > 0)
				s.push(asteroid);
			else
			{
				while (!s.empty() && s.top() < -asteroid)
					s.pop();
				if (!s.empty() && s.top() == -asteroid)
					s.pop();
				else if (s.empty())
					res.push_back(asteroid);
			}
		}
		res.resize(res.size() + s.size());
		for (int i = res.size() - 1; !s.empty(); --i)
		{
			res[i] = s.top();
			s.pop();
		}
		return res;
	}
};