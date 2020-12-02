#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> generateParenthesis(int n)
	{
		vector<pair<string, int>> parenthesis(1, {"", 0}); //{str,left-right}
		for (int i = 0; i < 2 * n; ++i)
		{
			vector<pair<string, int>> next;
			for (auto &p : parenthesis)
			{
				if (p.second > 0)
					next.push_back({p.first + ')', p.second - 1});
				next.push_back({p.first + '(', p.second + 1});
			}
			parenthesis = next;
		}

		vector<string> res;
		for (auto &p : parenthesis)
		{
			if (p.second == 0)
				res.push_back(p.first);
		}
		return res;
	}
};