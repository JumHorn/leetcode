#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	struct info
	{
		int p, h, index;
		char d;

		info()
		{
		}

		info(int _p, int _h, int _i, char _d) : p(_p), h(_h), index(_i), d(_d)
		{
		}
	};

	vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions)
	{
		vector<info> v;
		int N = positions.size();
		for (int i = 0; i < N; ++i)
			v.push_back(info(positions[i], healths[i], i, directions[i]));
		sort(v.begin(), v.end(), [](info &lhs, info &rhs)
			 { return lhs.p < rhs.p; });
		vector<pair<int, int>> stk; //{position,healthy}
		for (int i = 0; i < N; ++i)
		{
			int &p = v[i].p, &h = v[i].h;
			char &d = v[i].d;
			if (d == 'R')
				stk.push_back({v[i].index, i});
			else
			{
				while (!stk.empty() && v[stk.back().second].d == 'R' && h > 0)
				{
					if (h > v[stk.back().second].h)
					{
						stk.pop_back();
						--h;
					}
					else if (h == v[stk.back().second].h)
					{
						stk.pop_back();
						h = 0;
					}
					else
					{
						if (--v[stk.back().second].h == 0)
							stk.pop_back();
						h = 0;
					}
				}
				if (h > 0)
					stk.push_back({v[i].index, i});
			}
		}
		sort(stk.begin(), stk.end(), [](pair<int, int> &lhs, pair<int, int> &rhs)
			 { return lhs.first < rhs.first; });
		vector<int> res;
		for (auto n : stk)
			res.push_back(v[n.second].h);
		return res;
	}
};