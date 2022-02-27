#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int prefixCount(vector<string> &words, string pref)
	{
		int res = 0;
		for (auto &w : words)
		{
			if (w.compare(0, pref.size(), pref) == 0)
				++res;
		}
		return res;
	}
};