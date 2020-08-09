#include <string>
using namespace std;

class Solution
{
public:
	string makeGood(string s)
	{
		string res = s;
		bool flag = true;
		while (flag)
		{
			s = res;
			res.clear();
			flag = false;
			int i = 0;
			for (i = 0; i < (int)s.length() - 1; ++i)
			{
				if (s[i] != s[i + 1] && tolower(s[i]) == tolower(s[i + 1]))
				{
					++i;
					flag = true;
					continue;
				}
				res.push_back(s[i]);
			}
			if (i == (int)s.length() - 1)
				res.push_back(s[i]);
		}
		return res;
	}
};
