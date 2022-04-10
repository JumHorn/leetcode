#include <string>
using namespace std;

class Solution
{
public:
	string minimizeResult(string expression)
	{
		auto p = expression.find('+');
		string l = expression.substr(0, p), r = expression.substr(p + 1);
		int num = stoi(l) + stoi(r);
		string res = '(' + expression + ')';
		for (int i = 0; i < (int)l.length(); ++i)
		{
			string l1s = l.substr(0, i), l2s = l.substr(i);
			int l1 = 1, l2 = stoi(l2s);
			if (!l1s.empty())
				l1 = stoi(l1s);
			for (int j = 0; j < (int)r.length(); ++j)
			{
				string r1s = r.substr(0, j + 1), r2s = r.substr(j + 1);
				int r1 = stoi(r1s), r2 = 1;
				if (!r2s.empty())
					r2 = stoi(r2s);
				int val = l1 * (l2 + r1) * r2;
				if (val < num)
				{
					num = val;
					res = l1s + '(' + l2s + '+' + r1s + ')' + r2s;
				}
			}
		}
		return res;
	}
};