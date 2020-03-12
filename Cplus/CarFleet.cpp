#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
	int carFleet(int target, vector<int> &position, vector<int> &speed)
	{
		int n = position.size();
		if (n == 0)
			return 0;
		vector<vector<int>> v(n, vector<int>(2));
		for (int i = 0; i < n; i++)
		{
			v[i][0] = position[i];
			v[i][1] = speed[i];
		}
		sort(v.begin(), v.end());
		stack<double> s;
		for (int i = 0; i < n; i++)
			s.push((target - v[i][0]) * 1.0 / v[i][1]);
		int res = 0;
		while (!s.empty())
		{
			res++;
			double tmp = s.top();
			s.pop();
			while (!s.empty() && tmp >= s.top())
				s.pop();
		}
		return res;
	}
};