#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> twoEditWords(vector<string> &queries, vector<string> &dictionary)
	{
		vector<string> res;
		for (auto &q : queries)
		{
			for (auto &d : dictionary)
			{
				if (diff(q, d) <= 2)
				{
					res.push_back(q);
					break;
				}
			}
		}
		return res;
	}

	int diff(string &lhs, string &rhs)
	{
		int N = lhs.size(), res = 0;
		for (int i = 0; i < N; ++i)
			res += lhs[i] == rhs[i] ? 0 : 1;
		return res;
	}
};