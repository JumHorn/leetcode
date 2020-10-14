#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
	int sumSubarrayMins(vector<int> &A)
	{
		stack<int> s; //increase stack storing index
		int res = 0, N = A.size();
		for (int i = 0; i <= N; ++i)
		{
			while (!s.empty() && (i == N || A[s.top()] > A[i]))
			{
				int index = s.top();
				s.pop();
				int j = s.empty() ? -1 : s.top();
				res = (res + (i - index) * (index - j) * A[index]) % MOD;
			}
			s.push(i);
		}
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};