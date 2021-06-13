#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int maximumRemovals(string s, string p, vector<int> &removable)
	{
		int lo = 0, hi = removable.size() + 1;
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (isSubsequence(s, p, removable, mi))
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo - 1;
	}

	bool isSubsequence(string &s, string &p, vector<int> &v, int size)
	{
		int i = 0, j = 0, k = 0, M = s.length(), N = p.length();
		vector<int> tmp(v.begin(), v.begin() + size);
		sort(tmp.begin(), tmp.end());
		for (; i < N && j < M; ++j)
		{
			if (k < size && j == tmp[k])
				++k;
			else
			{
				if (s[j] == p[i])
					++i;
			}
		}
		return i == N;
	}
};