#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	char findTheDifference(string s, string t)
	{
		unordered_map<char, int> m;
		for (auto c : t)
			++m[c];
		for (auto c : s)
		{
			if (--m[c] == 0)
				m.erase(c);
		}
		return m.begin()->first;
	}
};