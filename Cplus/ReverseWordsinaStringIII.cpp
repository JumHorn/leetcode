#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

class Solution
{
public:
	string reverseWords(string s)
	{
		string res, token;
		for (stringstream ss(s); ss >> token;)
		{
			reverse(token.begin(), token.end());
			res += token + ' ';
		}
		if (!res.empty())
			res.pop_back();
		return res;
	}
};