#include <cctype>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries)
	{
		unordered_set<string> words(wordlist.begin(), wordlist.end());
		unordered_map<string, string> cap, vowel;
		for (auto &w : wordlist)
		{
			string lower = strToLower(w), devowel = devowelPattern(w);
			cap.insert({lower, w});
			vowel.insert({devowel, w});
		}

		for (auto &query : queries)
		{
			if (words.find(query) != words.end())
				continue;
			string lower = strToLower(query), devowel = devowelPattern(query);
			if (cap.find(lower) != cap.end())
				query = cap[lower];
			else if (vowel.find(devowel) != vowel.end())
				query = vowel[devowel];
			else
				query = "";
		}
		return queries;
	}

	string strToLower(string word)
	{
		for (auto &c : word)
			c = tolower(c);
		return word;
	}

	string devowelPattern(string word)
	{
		for (auto &c : word)
		{
			c = tolower(c);
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
				c = '#';
		}
		return word;
	}
};