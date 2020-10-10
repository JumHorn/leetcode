#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int numMatchingSubseq(string S, vector<string> &words)
	{
		vector<vector<pair<int, int>>> hash(128); //{words index,word next letter index}
		for (int i = 0; i < (int)words.size(); ++i)
			hash[words[i][0]].push_back({i, 0});
		for (int i = 0; i < (int)S.size(); ++i)
		{
			auto v = hash[S[i]];
			hash[S[i]].clear();
			for (int j = 0; j < (int)v.size(); ++j)
				hash[words[v[j].first][v[j].second + 1]].push_back({v[j].first, v[j].second + 1});
		}
		return hash[0].size(); //count number of char '\0'
	}
};