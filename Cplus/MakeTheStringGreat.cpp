#include <cctype>
#include <string>
using namespace std;

class Solution
{
public:
	string makeGood(string s)
	{
		string res; //view res as stack
		for (int i = 0; i < (int)s.length(); ++i)
		{
			if (!res.empty() && res.back() != s[i] && tolower(res.back()) == tolower(s[i]))
				res.pop_back();
			else
				res.push_back(s[i]);
		}
		return res;
	}
};