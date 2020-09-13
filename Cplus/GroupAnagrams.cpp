#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<string>> groupAnagrams(vector<string> &strs)
	{
		vector<vector<string>> res;
		map<vector<int>, vector<string>> m;
		for (auto &str : strs)
		{
			vector<int> hash(26);
			for (auto c : str)
				++hash[c - 'a'];
			m[hash].push_back(str);
		}
		for (auto &n : m)
			res.push_back(n.second);
		return res;
	}
};