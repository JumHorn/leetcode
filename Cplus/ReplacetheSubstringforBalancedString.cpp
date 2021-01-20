#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	int balancedString(string s)
	{
		unordered_map<char, int> m; //{char,count}
		for (auto c : s)
			++m[c];
		int N = s.length(), res = N, avg = N / 4;
		for (int i = 0, j = 0; j < N; ++j)
		{
			for (--m[s[j]]; i < N && m['Q'] <= avg && m['W'] <= avg && m['E'] <= avg && m['R'] <= avg; ++i)
			{
				res = min(res, j - i + 1);
				++m[s[i]];
			}
		}
		return res;
	}
};