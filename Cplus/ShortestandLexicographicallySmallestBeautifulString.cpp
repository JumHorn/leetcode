#include <string>
using namespace std;

class Solution
{
public:
	string shortestBeautifulSubstring(string s, int k)
	{
		int N = s.size(), len = N + 1, ones = k;
		for (int i = 0, j = 0; i < N; ++i)
		{
			if (s[i] == '1')
				--k;
			for (; k < 0 || s[j] == '0'; ++j)
			{
				if (s[j] == '1')
					++k;
			}
			if (k == 0)
				len = min(len, i - j + 1);
		}
		if (len == N + 1)
			return "";
		string res(len, '1');
		int count = 0;
		for (int i = 0; i < len; ++i)
		{
			if (s[i] == '1')
				++count;
		}
		if (count == ones)
			res = s.substr(0, len);
		for (int i = len; i < N; ++i)
		{
			if (s[i] == '1')
				++count;
			if (s[i - len] == '1')
				--count;
			if (count == ones)
				res = min(res, s.substr(i - len + 1, len));
		}
		return res;
	}
};