#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int minStickers(vector<string>& stickers, string target)
	{
		int n = stickers.size(), res = 0;
		map<char, int> targetmap;
		vector<map<char, int>> words(n);
		for (auto c : target)
			++targetmap[c];
		for (int i = 0; i < n; i++)
		{
			for (auto c : stickers[i])
				if (targetmap.find(c) != targetmap.end())
					++words[i][c];
		}
		queue<map<char, int>> q;
		set<map<char, int>> seen;
		q.push(targetmap);
		seen.insert(targetmap);
		while (!q.empty())
		{
			++res;
			int size = q.size();
			while (--size >= 0)
			{
				for (int i = 0; i < n; i++)
				{
					targetmap = q.front();
					for (auto c : words[i])
					{
						if (targetmap.find(c.first) != targetmap.end())
						{
							targetmap[c.first] -= c.second;
							if (targetmap[c.first] <= 0)
								targetmap.erase(c.first);
						}
					}
					if (targetmap.empty())
						return res;
					if (seen.find(targetmap) == seen.end())
					{
						seen.insert(targetmap);
						q.push(targetmap);
					}
				}
				q.pop();
			}
		}
		return -1;
	}
};
