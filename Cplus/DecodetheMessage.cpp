#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	string decodeMessage(string key, string message)
	{
		unordered_map<char, char> m;
		for (auto c : key)
		{
			if (c != ' ' && m.count(c) == 0)
				m[c] = 'a' + m.size();
		}
		string res;
		for (auto c : message)
		{
			if (m.count(c) != 0)
				res.push_back(m[c]);
			else
				res.push_back(c);
		}
		return res;
	}
};