#include <string>
using namespace std;

class Solution
{
public:
	long long maximumSubsequenceCount(string text, string pattern)
	{
		long long res = 0;
		string s;
		for (auto c : text)
		{
			if (c == pattern[0] || c == pattern[1])
				s.push_back(c);
		}
		int N = s.length();
		if (pattern[0] == pattern[1])
		{
			long long n = N + 1;
			return n * (n - 1) / 2;
		}
		int a = 0, b = 0;
		for (auto c : s)
		{
			if (c == pattern[0])
				++a;
			else
				++b;
		}
		//add it to front
		long long res0 = b;
		for (auto c : s)
		{
			if (c == pattern[1])
				--b;
			else
				res0 += b;
		}
		//add it to front
		long long res1 = a;
		for (auto it = s.rbegin(); it != s.rend(); ++it)
		{
			char c = *it;
			if (c == pattern[0])
				--a;
			else
				res1 += a;
		}
		return max(res0, res1);
	}
};