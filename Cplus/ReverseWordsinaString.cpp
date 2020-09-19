#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string reverseWords(string s)
	{
		stringstream ss(s);
		vector<string> words;
		string word;
		while (getline(ss, word, ' '))
		{
			if (word.empty())
				continue;
			words.push_back(word);
		}
		reverse(words.begin(), words.end());
		if (words.empty())
			return "";
		string res = words[0];
		for (int i = 1; i < (int)words.size(); ++i)
			res += " " + words[i];
		return res;
	}
};