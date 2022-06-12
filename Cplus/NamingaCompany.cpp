#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	long long distinctNames(vector<string> &ideas)
	{
		long long res = 0;
		unordered_set<string> s(ideas.begin(), ideas.end());
		vector<vector<long long>> count(26, vector<long long>(26));
		for (auto c = 'a'; c <= 'z'; ++c)
		{
			for (auto &str : ideas)
			{
				char old = str[0];
				str[0] = c;
				if (s.count(str) == 0)
					++count[old - 'a'][c - 'a'];
				str[0] = old;
			}
		}

		for (int i = 0; i < 26; ++i)
		{
			for (int j = 0; j < 26; ++j)
				res += count[i][j] * count[j][i];
		}
		return res;
	}
};