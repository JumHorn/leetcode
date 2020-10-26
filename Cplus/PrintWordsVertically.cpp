#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> printVertically(string s)
	{
		int maxWordLen = 0;
		vector<string> strs = split(s, maxWordLen);
		int N = strs.size();
		vector<string> res;
		for (int j = 0; j < maxWordLen; ++j)
		{
			res.push_back("");
			for (int i = 0; i < N; ++i)
			{
				if (j < (int)strs[i].length())
					res.back().push_back(strs[i][j]);
				else
					res.back().push_back(' ');
			}
			while (!res.back().empty() && res.back().back() == ' ')
				res.back().pop_back();
		}
		return res;
	}

	vector<string> split(const string &s, int &maxLen)
	{
		vector<string> res;
		stringstream ss(s);
		res.push_back("");
		while (ss >> res.back())
		{
			maxLen = max(maxLen, (int)res.back().length());
			res.push_back("");
		}
		res.pop_back();
		return res;
	}
};