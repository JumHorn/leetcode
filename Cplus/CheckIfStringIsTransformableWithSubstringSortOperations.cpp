#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	bool isTransformable(string s, string t)
	{
		vector<vector<int>> pos(10);
		for (int i = (int)s.length() - 1; i >= 0; --i)
			pos[s[i] - '0'].push_back(i);
		for (auto c : t)
		{
			int i = c - '0';
			if (pos[i].empty())
				return false;
			for (int j = 0; j < i; ++j)
			{
				if (!pos[j].empty() && pos[j].back() < pos[i].back())
					return false;
			}
			pos[i].pop_back();
		}
		return true;
	}
};