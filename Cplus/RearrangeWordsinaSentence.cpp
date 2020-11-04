#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string arrangeWords(string text)
	{
		vector<pair<string, int>> word;
		stringstream ss(text);
		string token;
		for (int i = 0; ss >> token; ++i)
			word.push_back({token, i});
		word[0].first[0] = tolower(word[0].first[0]);
		sort(word.begin(), word.end(), *this);
		string res = word[0].first;
		for (int i = 1; i < (int)word.size(); ++i)
			res += " " + word[i].first;
		res[0] = toupper(res[0]);
		return res;
	}

	bool operator()(const pair<string, int> &lhs, const pair<string, int> &rhs)
	{
		if (lhs.first.length() != rhs.first.length())
			return lhs.first.length() < rhs.first.length();
		return lhs.second < rhs.second;
	}
};