#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
	bool isIsomorphic(string s, string t)
	{
		int N = s.length();
		unordered_map<char, char> m;
		unordered_set<char> seen; //aready matched
		for (int i = 0; i < N; ++i)
		{
			if (m.find(s[i]) == m.end() && seen.find(t[i]) == seen.end())
			{
				m[s[i]] = t[i];
				seen.insert(t[i]);
			}
			if (m[s[i]] != t[i])
				return false;
		}
		return true;
	}
};