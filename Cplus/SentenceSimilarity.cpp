#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	bool areSentencesSimilar(vector<string> &words1, vector<string> &words2, vector<pair<string, string>> pairs)
	{
		unordered_map<string, string> m;
		for (auto &p : pairs)
		{
			m[p.first] = p.second;
			m[p.second] = p.first;
		}
		if (words1.size() != words2.size())
			return false;
		for (int i = 0; i < (int)words1.size(); ++i)
		{
			if (words1[i] == words2[i])
				continue;
			if (m.find(words1[i]) == m.end() || m[words1[i]] != words2[i])
				return false;
		}
		return true;
	}
};