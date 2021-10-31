#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries)
	{
		int N = s.length();
		vector<int> left(N, -1), right(N, -1);
		for (int i = 0, j = -1; i < N; ++i)
		{
			if (s[i] == '|')
			{
				left[i] = i;
				j = i;
			}
			else
				left[i] = j;
		}
		for (int i = N - 1, j = -1; i >= 0; --i)
		{
			if (s[i] == '|')
			{
				right[i] = i;
				j = i;
			}
			else
				right[i] = j;
		}
		vector<int> prefix(N + 1);
		for (int i = 0; i < N; ++i)
			prefix[i + 1] = prefix[i] + (s[i] == '*' ? 1 : 0);
		vector<int> res;
		for (auto &q : queries)
		{
			int l = q[0], r = q[1];
			if (left[r] == -1 || right[l] == -1)
				res.push_back(0);
			else
				res.push_back(max(0, prefix[left[r] + 1] - prefix[right[l]]));
		}
		return res;
	}
};