#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

/*
not nomal kmp code
i jump back near brute force solution
*/

class Solution
{
public:
	bool matchReplacement(string s, string sub, vector<vector<char>> &mappings)
	{
		int M = s.size(), N = sub.size();
		vector<unordered_set<char>> replace(256);
		for (auto &v : mappings)
			replace[v[0]].insert(v[1]);

		vector<int> next(N);
		for (int i = 1, j = 0; i < N; ++i)
		{
			while (j > 0 && sub[i] != sub[j])
				j = next[j - 1];
			if (sub[i] == sub[j])
				++j;
			next[i] = j;
		}

		int i = 0, j = 0;
		while (i < M && j < N)
		{
			if (s[i] == sub[j] || replace[sub[j]].count(s[i]) != 0)
			{
				++j;
				++i;
			}
			else
			{
				j > 0 ? (i = i - (j - next[j - 1]) + 1) : ++i;
				j = 0;
			}
		}
		return j == N;
	}
};