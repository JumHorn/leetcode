#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct Teams
{
	char t;
	vector<int> rank;
	Teams(int n) : rank(n) {}
};

class Solution
{
public:
	string rankTeams(vector<string> &votes)
	{
		unordered_map<char, int> index;
		int n = votes[0].length();
		vector<Teams> v(n, Teams(n));
		for (int i = 0; i < n; i++)
		{
			index[votes[0][i]] = i;
			v[i].t = votes[0][i];
			v[i].rank[i]++;
		}
		for (int j = 1; j < (int)votes.size(); j++)
		{
			for (int i = 0; i < n; i++)
			{
				int tmp = index[votes[j][i]];
				v[tmp].rank[i]++;
			}
		}
		sort(v.begin(), v.end(), *this);
		string res;
		for (auto &iter : v)
			res += iter.t;
		return res;
	}

	bool operator()(const Teams &lhs, const Teams &rhs)
	{
		for (int i = 0; i < (int)lhs.rank.size(); i++)
			if (lhs.rank[i] != rhs.rank[i])
				return lhs.rank[i] > rhs.rank[i];
		return lhs.t < rhs.t;
	}
};