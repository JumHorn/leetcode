#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string clearStars(string s)
	{
		vector<vector<int>> pos(26);
		int N = s.size();
		for (int i = 0; i < N; ++i)
		{
			char c = s[i];
			if (c == '*')
			{
				for (int j = 0; j < 26; ++j)
				{
					if (!pos[j].empty())
					{
						s[pos[j].back()] = '*';
						pos[j].pop_back();
						break;
					}
				}
			}
			else
				pos[c - 'a'].push_back(i);
		}
		string res;
		for (auto c : s)
		{
			if (c != '*')
				res.push_back(c);
		}
		return res;
	}
};