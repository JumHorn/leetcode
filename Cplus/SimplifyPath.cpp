#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string simplifyPath(string path)
	{
		stringstream ss(path);
		vector<string> token;
		string tok;
		while (getline(ss, tok, '/'))
		{
			if (tok.empty() || tok == ".")
				continue;
			if (tok != "..")
				token.push_back(tok);
			else if (!token.empty())
				token.pop_back();
		}
		string res;
		for (auto &str : token)
			res += '/' + str;
		return res.empty() ? "/" : res;
	}
};