#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> printVertically(string s)
	{
		vector<string> v = split(s);
		int index = 0;
		vector<string> res;
		while (index < (int)s.length())
		{
			string tmp;
			for (int i = 0; i < (int)v.size(); i++)
			{
				if (index < (int)v[i].length())
					tmp += v[i][index];
				else
					tmp += " ";
			}
			int j = tmp.length() - 1;
			while (j >= 0)
			{
				if (tmp[j] != ' ')
					break;
				j--;
			}
			if (j < 0)
				break;
			res.push_back(tmp.substr(0, j + 1));
			++index;
		}
		return res;
	}

	vector<string> split(const string &s)
	{
		vector<string> res;
		int i = 0, j = 0;
		while (j < (int)s.length())
		{
			while (j < (int)s.length() && s[j] != ' ')
				j++;
			res.push_back(s.substr(i, j - i));
			i = ++j;
		}
		return res;
	}
};
