#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> findSubstring(string s, vector<string> &words)
	{
		int wordsSize = words.size();
		int N = s.length(), w = words[0].length(), len = w * wordsSize;
		unordered_map<string, int> m; //{word,index}
		vector<int> res, count(wordsSize);
		for (int i = 0; i < wordsSize; ++i)
		{
			m.insert({words[i], i});
			++count[m[words[i]]];
		}
		for (int i = 0, j = 0; i <= N - len; ++i)
		{
			auto wordCountCopy = count;
			for (j = i; j < i + len; j += w)
			{
				string sub = s.substr(j, w);
				if (m.find(sub) == m.end())
					break;
				if (--wordCountCopy[m[sub]] < 0)
					break;
			}
			if (j == i + len)
				res.push_back(i);
		}
		return res;
	}
};