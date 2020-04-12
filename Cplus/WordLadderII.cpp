#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
	{
		unordered_map<string, unordered_set<string>> graph;
		unordered_set<string> seen;
		unordered_set<string> words(wordList.begin(), wordList.end());
		//BSF
		queue<string> q;
		int depth = 0;
		q.push(beginWord);
		seen.insert(beginWord);
		bool flag = true;
		while (!q.empty() && flag)
		{
			for (auto &str : seen)
				words.erase(str);
			seen.clear();
			int size = q.size();
			++depth;
			while (--size >= 0)
			{
				string tmp = q.front();
				for (int i = 0; i < (int)tmp.length(); i++)
				{
					for (char c = 'a'; c <= 'z'; c++)
					{
						tmp[i] = c;
						if (words.find(tmp) != words.end())
						{
							graph[q.front()].insert(tmp);
							q.push(tmp);
							seen.insert(tmp);
							if (tmp == endWord)
							{
								flag = false;
								break;
							}
						}
					}
					tmp = q.front();
				}
				q.pop();
			}
		}
		if (flag)
			return {};

		//DFS
		vector<vector<string>> res;
		vector<string> onepath = {beginWord};
		dfs(graph, res, onepath, endWord);
		return res;
	}

	void dfs(unordered_map<string, unordered_set<string>> &graph, vector<vector<string>> &res, vector<string> &tmp, const string &dst)
	{
		if (tmp.back() == dst)
		{
			res.push_back(tmp);
			return;
		}
		for (auto &str : graph[tmp.back()])
		{
			tmp.push_back(str);
			dfs(graph, res, tmp, dst);
			tmp.pop_back();
		}
	}
};