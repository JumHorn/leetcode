#include <algorithm>
#include <bitset>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> peopleIndexes(vector<vector<string>> &favoriteCompanies)
	{
		unordered_map<string, int> m;
		int id = 0, N = favoriteCompanies.size();
		for (auto &fc : favoriteCompanies)
		{
			for (auto &c : fc)
			{
				if (m.find(c) == m.end())
					m[c] = id++;
			}
		}

		vector<bitset<BIT_SIZE>> v;
		for (auto &fc : favoriteCompanies)
		{
			bitset<BIT_SIZE> bit;
			for (auto &c : fc)
				bit[m[c]] = 1;
			v.push_back(bit);
		}

		vector<int> res;
		for (int i = 0, j = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (i != j && (v[i] & v[j]) == v[i])
					break;
			}
			if (j == N)
				res.push_back(i);
		}
		return res;
	}

private:
	static const int BIT_SIZE = 50000;
};