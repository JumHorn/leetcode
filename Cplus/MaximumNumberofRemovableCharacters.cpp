#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int maximumRemovals(string s, string p, vector<int> &removable)
	{
		int N = removable.size(), lo = 0, hi = N + 1;
		vector<int> remove(s.size(), s.size());
		for (int i = 0; i < N; ++i)
			remove[removable[i]] = i;
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (isSubsequence(s, p, remove, mi))
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo - 1;
	}

	bool isSubsequence(string &s, string &p, vector<int> &remove, int size)
	{
		int i = 0, j = 0, k = 0, M = s.length(), N = p.length();
		for (; i < N && j < M; ++j)
		{
			if (remove[j] >= size && s[j] == p[i])
				++i;
		}
		return i == N;
	}
};