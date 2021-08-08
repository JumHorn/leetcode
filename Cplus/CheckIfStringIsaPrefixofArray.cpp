#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	bool isPrefixString(string s, vector<string> &words)
	{
		int i = 0, N = s.length();
		for (auto &str : words)
		{
			int n = str.length();

			if (N - i < n)
				return false;
			if (s.compare(i, n, str) != 0)
				return false;
			i += n;
			if (i == N)
				return true;
		}
		return false;
	}
};