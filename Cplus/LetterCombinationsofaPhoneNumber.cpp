#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> letterCombinations(string digits)
	{
		if (digits.empty())
			return {};
		unordered_map<char, string> m;
		m['2'] = "abc";
		m['3'] = "def";
		m['4'] = "ghi";
		m['5'] = "jkl";
		m['6'] = "mno";
		m['7'] = "pqrs";
		m['8'] = "tuv";
		m['9'] = "wxyz";
		vector<string> res = {""};
		for (auto d : digits)
		{
			vector<string> next_res;
			for (auto c : m[d])
			{
				for (auto &str : res)
					next_res.push_back(str + c);
			}
			res.swap(next_res);
		}
		return res;
	}
};