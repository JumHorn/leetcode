#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> removeSubfolders(vector<string> &folder)
	{
		vector<string> res;
		sort(folder.begin(), folder.end());
		for (string &s : folder)
		{
			if (res.empty() ||
				res.back().compare(0, res.back().length(), s, 0, res.back().length()) != 0 ||
				s[res.back().length()] != '/')
				res.push_back(s);
		}
		return res;
	}
};