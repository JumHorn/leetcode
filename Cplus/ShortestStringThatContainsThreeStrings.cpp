#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string minimumString(string a, string b, string c)
	{
		vector<string> v = {a, b, c};
		sort(v.begin(), v.end());
		string res = cat(v[0], v[1], v[2]);
		while (next_permutation(v.begin(), v.end()))
		{
			string str = cat(v[0], v[1], v[2]);
			if (str.size() < res.size())
				res = str;
			else if (str.size() == res.size())
				res = min(res, str);
		}
		return res;
	}

	string cat(string &a, string &b, string &c)
	{
		string s1 = cat(a, b);
		return cat(s1, c);
	}

	string cat(string &lhs, string &rhs)
	{
		int len = overlap(lhs, rhs);
		return lhs + rhs.substr(len);
	}

	int overlap(string &a, string &b)
	{
		int k = 0, N = a.size();
		for (; k < N; ++k)
		{
			int i = k, j = 0;
			while (i < N && a[i] == b[j])
				++i, ++j;
			if (j == b.size())
				return b.size();
			if (i == N)
				break;
		}
		return a.size() - k;
	}
};