#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> dailyTemperatures(vector<int> &T)
	{
		int N = T.size();
		vector<int> res(N);
		stack<int> s;
		for (int i = 0; i < N; ++i)
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