#include <algorithm>
#include <queue>
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
	int ladderLength(string beginWord, string endWord, vector<string> &wordList)
	{
		unordered_set<string> words(wordList.begin(), wordList.end());
		unordered_set<string> beginset, endset;
		if (words.find(endWord) == words.end())
			return 0;
		beginset.insert(beginWord);
		endset.insert(endWord);
		int res = 1;
		while (!beginset.empty())
		{
			if (beginset.size() > endset.size())
				beginset.swap(endset);
			++res;
			unordered_set<string> newset;
			for (auto str : beginset)
			{
				for (int i = 0; i < (int)str.length(); i++)
				{
					char oldchar = str[i];
					for (char c = 'a'; c <= 'z'; c++)
					{
						str[i] = c;
						if (endset.find(str) != endset.end())
							return res;
						if (words.find(str) != words.end())
						{
							words.erase(str);
							newset.insert(str);
						}
					}
					str[i] = oldchar;
				}
			}
			beginset.swap(newset);
		}
		return 0;
	}
};