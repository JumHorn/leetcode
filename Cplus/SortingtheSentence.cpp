#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string sortSentence(string s)
	{
		stringstream ss(s);
		string word, res;
		vector<string> v(10);
		while (ss >> word)
			v[word.back() - '0'] = word.substr(0, word.size() - 1);
		for (int i = 1; i < 10; ++i)
		{
			if (!v[i].empty())
				res += v[i] + ' ';
		}
		res.pop_back();
		return res;
	}
};