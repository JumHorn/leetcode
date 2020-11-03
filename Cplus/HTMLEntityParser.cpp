#include <regex>
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
		for (auto &en : entity)
			text = regex_replace(text, regex(en.first), en.second);
		return text;
	}
};