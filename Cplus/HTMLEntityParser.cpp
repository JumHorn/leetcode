#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	string entityParser(string text)
	{
		unordered_map<string, string> entity;
		entity["&quot;"] = "\"";
		entity["&apos;"] = "\'";
		entity["&amp;"] = "&";
		entity["&gt;"] = ">";
		entity["&lt;"] = "<";
		entity["&frasl;"] = "/";
		int i = 0, j = 0, n = text.length();
		string res;
		while (i < n)
		{
			if (text[i] == '&')
			{
				j = i + 1;
				while (j < n && text[j] != '&' && text[j] != ';')
					++j;
				if (j == n || text[j] == '&')
				{
					res += text.substr(i, j - i);
					i = j;
				}
				else
				{
					string tmp = text.substr(i, j - i + 1);
					if (entity.find(tmp) == entity.end())
					{
						res += tmp;
						i = ++j;
					}
					else
					{
						res += entity[tmp];
						i = ++j;
					}
				}
			}
			else
			{
				res.push_back(text[i]);
				++i;
			}
		}
		return res;
	}
};
