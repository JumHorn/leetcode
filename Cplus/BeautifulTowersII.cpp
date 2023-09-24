#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
	long long maximumSumOfHeights(vector<int> &maxHeights)
	{
		int N = maxHeights.size();
		vector<long long> prefix(N + 1), suffix(N + 1);
		stack<int> p, s;
		for (int i = 0; i < N; ++i)
		{
			prefix[i + 1] = prefix[i];
			while (!p.empty() && maxHeights[p.top()] > maxHeights[i])
			{
				int index = p.top();
				p.pop();
				prefix[i + 1] -= (long long)maxHeights[index] * (index - (p.empty() ? -1 : p.top()));
			}
			prefix[i + 1] += (long long)maxHeights[i] * (i - (p.empty() ? -1 : p.top()));
			p.push(i);
		}
		for (int i = N - 1; i >= 0; --i)
		{
			suffix[i] = suffix[i + 1];
			while (!s.empty() && maxHeights[s.top()] > maxHeights[i])
			{
				int index = s.top();
				s.pop();
				suffix[i] -= (long long)maxHeights[index] * ((s.empty() ? N : s.top()) - index);
			}
			suffix[i] += (long long)maxHeights[i] * ((s.empty() ? N : s.top()) - i);
			s.push(i);
		}

		long long res = 0;
		for (int i = 0; i < N; ++i)
			res = max(res, prefix[i] + suffix[i]);
		return res;
	}
};