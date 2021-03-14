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
		for (auto c : S)
		{
			auto v = hash[c];
			hash[c].clear();
			for (auto [w, index] : v)
				hash[words[w][index + 1]].push_back({w, index + 1});
		}
		return hash[0].size(); //count number of char '\0'
	}
};