#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> generateParenthesis(int n)
	{
		vector<pair<string, int>> parenthesis(1, {"", 0}); //{str,left-right}
		vector<string> res;
		for (int i = 0; i < 2 * n; ++i)
		{
			vector<pair<string, int>> old;
			for (auto &p : parenthesis)
			{
				if (p.second > 0)
					old.push_back({p.first + ')', p.second - 1});
				old.push_back({p.first + '(', p.second + 1});
			}
			parenthesis = old;
		}
		for (auto &p : parenthesis)
		{
			if (p.second == 0)
				res.push_back(p.first);
		}
		return res;
	}
};