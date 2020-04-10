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
		int n = wordList.size();
		vector<vector<int>> graph(n + 1);
		vector<int> seen(n + 1);
		unordered_map<string, int> words; //{str,index}
		for (int i = 0; i < n; i++)
			words[wordList[i]] = i;
		wordList.push_back(beginWord);
		words[beginWord] = n;

		//BFS
		queue<string> q;
		seen[words[beginWord]] = 1;
		int depth = 1;
		q.push(beginWord);
		bool flag = true;
		unordered_set<int> seennew;
		while (!q.empty() && flag)
		{
			++depth;
			int size = q.size();
			for (auto n : seennew)
				seen[n] = 1;
			seennew.clear();
			while (--size >= 0)
			{
				string tmp = q.front();
				for (int i = 0; i < (int)tmp.length(); i++)
				{
					for (char c = 'a'; c <= 'z'; c++)
					{
						tmp[i] = c;
						if (words.find(tmp) != words.end() && seen[words[tmp]] == 0)
						{
							seennew.insert(words[tmp]);
							graph[words[q.front()]].push_back(words[tmp]);
							q.push(tmp);
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
		vector<int> onepath = {words[beginWord]};
		vector<vector<string>> res;
		dfs(graph, wordList, res, onepath, words[endWord], depth);
		return res;
	}

	//DFS
	void dfs(vector<vector<int>> &graph, vector<string> &wordlist, vector<vector<string>> &res, vector<int> &onepath, int dst, int depth)
	{
		if (depth <= 1)
		{
			if (onepath.back() == dst)
			{
				res.push_back({});
				for (auto n : onepath)
					res.back().push_back(wordlist[n]);
			}
			return;
		}
		int n = graph.size();
		for (auto to : graph[onepath.back()])
		{
			onepath.push_back(to);
			dfs(graph, wordlist, res, onepath, dst, depth - 1);
			onepath.pop_back();
		}
	}
};