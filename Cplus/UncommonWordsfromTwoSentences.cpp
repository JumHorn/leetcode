#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> uncommonFromSentences(string A, string B)
	{
		unordered_map<string, int> m; //{str,count}
		split(A, m);
		split(B, m);
		vector<string> res;
		for (auto &n : m)
		{
			if (n.second == 1)
				res.push_back(n.first);
		}
		return res;
	}

	void split(string &str, unordered_map<string, int> &m)
	{
		string word;
		stringstream ss(str);
		while (ss >> word)
			++m[word];
	}
};