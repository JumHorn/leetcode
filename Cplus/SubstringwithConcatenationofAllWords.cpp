#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> findSubstring(string s, vector<string> &words)
	{
		vector<int> res;
		int wordsSize = words.size();
		int N = s.length(), w = words[0].length(), len = w * wordsSize;
		unordered_multiset<string> umset(words.begin(), words.end()); //{word}
		for (int i = 0; i <= N - len; ++i)
		{
			auto wordSetCopy = umset;
			for (int j = i; j < i + len; j += w)
			{
				string sub = s.substr(j, w);
				auto iter = wordSetCopy.find(sub);
				if (iter == wordSetCopy.end())
					break;
				wordSetCopy.erase(iter);
			}
			if (wordSetCopy.empty())
				res.push_back(i);
		}
		return res;
	}
};