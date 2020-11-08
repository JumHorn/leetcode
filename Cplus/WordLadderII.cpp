#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
	{
		unordered_map<string, unordered_set<string>> graph;
		unordered_set<string> seen, words(wordList.begin(), wordList.end());
		//BSF
		queue<string> q;
		q.push(beginWord);
		seen.insert(beginWord);
		bool flag = true;
		while (!q.empty() && flag)
		{
			for (auto &str : seen)
				words.erase(str);
			seen.clear();
			int size = q.size();
			while (--size >= 0)
			{
				string w = q.front();
				for (int i = 0; i < (int)w.length(); ++i)
				{
					char old = w[i];
					for (char c = 'a'; c <= 'z'; ++c)
					{
						w[i] = c;
						if (words.find(w) != words.end())
						{
							graph[q.front()].insert(w);
							q.push(w);
							seen.insert(w);
							if (w == endWord)
							{
								flag = false;
								break;
							}
						}
					}
					w[i] = old;
				}
				q.pop();
			}
		}
		if (flag)
			return {};

		//DFS
		vector<vector<string>> res;
		vector<string> onepath = {beginWord};
		dfs(graph, endWord, onepath, res);
		return res;
	}

	void dfs(unordered_map<string, unordered_set<string>> &graph, const string &dst, vector<string> &instance, vector<vector<string>> &res)
	{
		if (instance.back() == dst)
		{
			res.push_back(instance);
			return;
		}
		for (auto &str : graph[instance.back()])
		{
			instance.push_back(str);
			dfs(graph, dst, instance, res);
			instance.pop_back();
		}
	}
};