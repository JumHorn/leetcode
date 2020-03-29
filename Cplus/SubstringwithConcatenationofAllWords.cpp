#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> findSubstring(string s, vector<string> &words)
	{
		vector<int> res;
		unordered_map<string, int> m; //{word,index}
		int size = words.size(), oldsize = size;
		vector<int> seen(size);
		if (words.empty())
			return {};
		int n = s.length(), w = words[0].length(), len = w * words.size();
		//initialize map and seen array
		for (int i = 0; i < size; i++)
		{
			if (m.find(words[i]) == m.end())
				m[words[i]] = i;
			++seen[m[words[i]]];
		}
		for (int i = 0; i <= n - len; i++)
		{
			vector<int> tmp(seen);
			int j = i;
			size = oldsize;
			while (j <= n - w)
			{
				string sub = s.substr(j, w);
				if (m.find(sub) == m.end())
					break;
				if (--tmp[m[sub]] < 0)
					break;
				if (--size == 0)
				{
					res.push_back(i);
					break;
				}
				j += w;
			}
		}
		return res;
	}
};