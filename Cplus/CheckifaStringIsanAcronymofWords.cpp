#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	bool isAcronym(vector<string> &words, string s)
	{
		string res;
		for (auto &w : words)
			res.push_back(w.front());
		return res == s;
	}
};