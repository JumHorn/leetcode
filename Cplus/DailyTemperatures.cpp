#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> dailyTemperatures(vector<int> &T)
	{
		vector<int> res(T.size());
		stack<int> s;
		for (int i = 0; i < (int)T.size(); ++i)
		{
			while (!s.empty() && T[s.top()] < T[i])
			{
				res[s.top()] = i - s.top();
				s.pop();
			}
			s.push(i);
		}
		return res;
	}
};