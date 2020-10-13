#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
	int carFleet(int target, vector<int> &position, vector<int> &speed)
	{
		int N = position.size();
		if (N == 0)
			return 0;
		vector<pair<int, int>> v(N);
		for (int i = 0; i < N; ++i)
		{
			v[i].first = position[i];
			v[i].second = speed[i];
		}
		sort(v.begin(), v.end());
		stack<double> s;
		for (int i = 0; i < N; ++i)
			s.push((target - v[i].first) * 1.0 / v[i].second);
		int res = 0;
		while (!s.empty())
		{
			++res;
			double time = s.top();
			s.pop();
			while (!s.empty() && time >= s.top())
				s.pop();
		}
		return res;
	}
};