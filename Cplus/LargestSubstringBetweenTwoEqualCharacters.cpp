#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxLengthBetweenEqualCharacters(string s)
	{
		int N = s.length(), res = 0;
		unordered_map<char, int> m; //{char,index}
		for (int i = 0; i < N; ++i)
		{
			m.insert({s[i], i});
			res = max(res, i - m[s[i]]);
		}
		return res - 1;
	}
};