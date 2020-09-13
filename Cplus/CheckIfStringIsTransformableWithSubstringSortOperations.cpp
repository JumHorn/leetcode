#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	bool isTransformable(string s, string t)
	{
		vector<vector<int>> pos(10);
		vector<int> used(10);  //used index of pos
		for (int i = 0; i < (int)s.length(); ++i)
			pos[s[i] - '0'].push_back(i);
		for (auto c : t)
		{
			int i = c - '0';
			if (used[i] >= (int)pos[i].size())
				return false;
			for (int j = 0; j < i; ++j)
			{
				if (used[j] < (int)pos[j].size() && pos[j][used[j]] < pos[i][used[i]])
					return false;
			}
			++used[i];
		}
		return true;
	}
};
