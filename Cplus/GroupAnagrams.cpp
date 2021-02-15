#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<string>> groupAnagrams(vector<string> &strs)
	{
		vector<vector<string>> res;
		unordered_map<string, vector<string>> m;
		for (auto &str : strs)
		{
			string s = str;
			sort(s.begin(), s.end());
			m[s].push_back(str);
		}
		for (auto &n : m)
			res.push_back(n.second);
		return res;
	}
};