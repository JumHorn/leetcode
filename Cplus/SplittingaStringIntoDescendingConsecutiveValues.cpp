#include <climits>
#include <string>
using namespace std;

class Solution
{
public:
	bool splitString(string s)
	{
		int N = s.length();
		long val = 0;
		for (int i = 0; i < N - 1; ++i)
		{
			val = val * 10 + s[i] - '0';
			if (val >= (long)INT_MAX * 100)
				return false;
			if (backTracking(s, i + 1, val))
				return true;
		}
		return false;
	}

	bool backTracking(string &s, int index, long val)
	{
		int N = s.length();
		if (index >= N)
			return true;
		long v = 0;
		for (int i = index; i < N; ++i)
		{
			v = v * 10 + s[i] - '0';
			if (v > val - 1)
				return false;
			if (val - v == 1 && backTracking(s, i + 1, v))
				return true;
		}
		return false;
	}
};