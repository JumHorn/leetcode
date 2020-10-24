#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
	bool wordPattern(string pattern, string s)
	{
		unordered_map<char, string> m;
		unordered_set<string> seen;
		stringstream ss(s);
		string word;
		for (auto c : pattern)
		{
			if (!(ss >> word))
				return false;
			if (m.find(c) == m.end())
			{
				if (seen.find(word) != seen.end())
					return false;
				seen.insert(word);
				m[c] = word;
			}
			else
			{
				if (m[c] != word)
					return false;
			}
		}
		return ss.eof();
	}
};