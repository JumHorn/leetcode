#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
	string orderlyQueue(string S, int K)
	{
		int N = S.length();
		if (K >= 2)
		{
			sort(S.begin(), S.end());
			return S;
		}

		auto iter = min_element(S.begin(), S.end());
		int d = distance(S.begin(), iter);
		for (int j = 0; j < N; ++j)
		{
			if (j != d && S[j] == S[d])
			{
				if (minReverse(S, N, j, d))
					d = j;
			}
		}
		strReverse(S, 0, d);
		return S;
	}

	void strReverse(string &s, int i, int d)
	{
		string tmp(s.substr(i, d - i));
		copy(s.begin() + d, s.end(), s.begin() + i);
		copy(tmp.begin(), tmp.end(), s.begin() + i + s.length() - d);
	}

	bool minReverse(const string &s, int n, int i, int j)
	{
		for (int k = 0; k < n; k++)
		{
			if (s[(i + k) % n] != s[(j + k) % n])
				return s[(i + k) % n] < s[(j + k) % n];
		}
		return false;
	}
};