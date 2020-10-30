#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> reorderLogFiles(vector<string> &logs)
	{
		vector<string> digitlog, letterlog;
		for (auto &log : logs)
		{
			int pos = log.find(' ');
			if (isdigit(log[pos + 1]))
				digitlog.push_back(log);
			else
				letterlog.push_back(log);
		}
		sort(letterlog.begin(), letterlog.end(), *this);
		letterlog.insert(letterlog.end(), digitlog.begin(), digitlog.end());
		return letterlog;
	}

	bool operator()(const string &lhs, const string &rhs)
	{
		int N1 = lhs.length(), N2 = rhs.length();
		int i = lhs.find(' ') + 1, j = rhs.find(' ') + 1;
		int res = lhs.compare(i, N1 - i, rhs, j, N2 - j);
		if (res != 0)
			return res < 0;
		return lhs.compare(0, i, rhs, 0, j) <= 0;
	}
};