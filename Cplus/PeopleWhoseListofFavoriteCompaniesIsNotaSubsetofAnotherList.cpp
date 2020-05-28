#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> peopleIndexes(vector<vector<string>> &favoriteCompanies)
	{
		int n = favoriteCompanies.size();
		vector<int> v(n);
		for (int i = 0; i < n; i++)
			v[i] = i;
		sort(v.begin(), v.end(), [&](int lhs, int rhs) { return favoriteCompanies[lhs].size() < favoriteCompanies[rhs].size(); });
		vector<int> res;
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = n - 1; j > i; j--)
			{
				if (v[j] == -1)
					continue;
				if (favoriteCompanies[v[j]].size() <= favoriteCompanies[v[i]].size())
					break;
				if (contains(favoriteCompanies[v[j]], favoriteCompanies[v[i]]))
				{
					v[i] = -1;
					break;
				}
			}
			if (v[i] != -1)
				res.push_back(v[i]);
		}
		sort(res.begin(), res.end());
		return res;
	}

	bool contains(vector<string> &lhs, vector<string> &rhs)
	{
		for (auto &s : rhs)
		{
			if (find(lhs.begin(), lhs.end(), s) == lhs.end())
				return false;
		}
		return true;
	}
};