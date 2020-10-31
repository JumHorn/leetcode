#include <algorithm>
#include <climits>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	int maxNumberOfBalloons(string text)
	{
		unordered_map<char, int> m; //{char,count}
		for (auto c : text)
			++m[c];
		int res = INT_MAX;
		m['l'] /= 2;
		m['o'] /= 2;
		string balloon = "balloon";
		for (auto c : balloon)
			res = min(res, m[c]);
		return res;
	}
};