#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	string evaluate(string s, vector<vector<string>> &knowledge)
	{
		unordered_map<string, string> m;
		for (auto &v : knowledge)
			m[v[0]] = v[1];
		string res;
		int N = s.length();
		for (int i = 0; i < N; ++i)
		{
			if (s[i] != '(')
				res.push_back(s[i]);
			else
			{
				int j = i + 1;
				while (j < N && s[j] != ')')
					++j;
				string key = s.substr(i + 1, j - i - 1);
				if (m.find(key) == m.end())
					res.push_back('?');
				else
					res += m[key];
				i = j;
			}
		}
		return res;
	}
};