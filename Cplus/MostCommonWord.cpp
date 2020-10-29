#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	string mostCommonWord(string paragraph, vector<string> &banned)
	{
		int N = paragraph.length();
		unordered_map<string, int> m;
		for (auto &c : paragraph) //make punctuation to ' '
		{
			if (c >= 'A' && c <= 'Z')
				c = c - 'A' + 'a';
			if (c < 'a' || c > 'z')
				c = ' ';
		}
		string word;
		stringstream ss(paragraph);
		while (ss >> word)
			++m[word];

		for (auto &ban : banned)
			m.erase(ban);
		int freq = 0;
		string res;
		for (auto &n : m)
		{
			if (n.second > freq)
			{
				res = n.first;
				freq = n.second;
			}
		}
		return res;
	}
};