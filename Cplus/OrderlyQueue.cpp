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

		int d = min_element(S.begin(), S.end()) - S.begin();
		for (int j = d + 1; j < N; ++j)
		{
			if (S[j] == S[d])
			{
				if (minReverse(S, N, j, d))
					d = j;
			}
		}
		strRotate(S, d);
		return S;
	}

	void strRotate(string &s, int pivot)
	{
		reverse(s.begin(), s.begin() + pivot);
		reverse(s.begin() + pivot, s.end());
		reverse(s.begin(), s.end());
	}

	bool minReverse(const string &s, int n, int i, int j)
	{
		for (int k = 0; k < n; ++k)
		{
			if (s[(i + k) % n] != s[(j + k) % n])
				return s[(i + k) % n] < s[(j + k) % n];
		}
		return false;
	}
};