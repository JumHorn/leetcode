#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<bool> camelMatch(vector<string> &queries, string pattern)
	{
		vector<bool> res;
		for (auto &query : queries)
			res.push_back(isMath(query, pattern));
		return res;
	}

	bool isMath(string &query, string &pattern)
	{
		int N = pattern.size(), i = 0;
		for (auto c : query)
		{
			if (i < N && c == pattern[i])
				++i;
			else if (c < 'a' || c > 'z')
				return false;
		}
		return i == N;
	}
};