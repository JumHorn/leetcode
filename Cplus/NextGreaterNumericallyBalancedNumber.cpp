#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int nextBeautifulNumber(int n)
	{
		string s = to_string(n);
		int N = s.length(), res = 1224444;
		if (n == 1e6)
			return res;
		if (n == 0)
			return 1;
		if (N == 1)
			return 22;
		for (int i = 1; i < N - i; ++i)
		{
			vector<int> v(8);
			v[i] = i;
			v[N - i] = N - i;
			int val = backTracking(v, s, 0, 0);
			if (val >= 0 && val < res)
				res = val;
		}

		int val = stoi("1" + string(N, '0' + N));
		if (N == 5)
			val = 122333;
		if (val < res && val > n)
			res = val;

		vector<int> v(8);
		v[N] = N;
		val = backTracking(v, s, 0, 0);
		if (val >= 0 && val < res)
			res = val;

		if (N == 6)
		{
			vector<int> v(8);
			v[1] = 1;
			v[2] = 2;
			v[3] = 3;
			int val = backTracking(v, s, 0, 0);
			if (val >= 0 && val < res)
				res = val;
		}
		return res;
	}

	int backTracking(vector<int> &v, string &s, int index, int val)
	{
		int N = s.length();
		for (int i = 1; i < (int)v.size(); ++i)
		{
			if (v[i] == 0)
				continue;
			if (i == s[index] - '0' && index != N - 1)
			{
				--v[i];
				int res = backTracking(v, s, index + 1, val * 10 + i);
				++v[i];
				if (res >= 0)
					return res;
			}
			else if (i > s[index] - '0')
			{
				--v[i];
				val = val * 10 + i;
				for (int j = 1; j < (int)v.size(); ++j)
				{
					for (; v[j] != 0; --v[j])
						val = val * 10 + j;
				}
				return val;
			}
		}
		return -1;
	}
};