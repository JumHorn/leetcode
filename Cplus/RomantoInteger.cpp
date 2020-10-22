#include <unordered_map>
using namespace std;

class Solution
{
public:
	int romanToInt(string s)
	{
		unordered_map<char, int> m = {{'I', 1},
									  {'V', 5},
									  {'X', 10},
									  {'L', 50},
									  {'C', 100},
									  {'D', 500},
									  {'M', 1000}};
		int N = s.length(), res = m[s.back()];
		for (int i = N - 2; i >= 0; --i)
			res += (m[s[i]] < m[s[i + 1]] ? -m[s[i]] : m[s[i]]);
		return res;
	}
};