#include <cctype>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Trie
{
private:
	struct TreeNode
	{
		TreeNode(int val = -1) : index(val) {}
		int index;
		unordered_map<char, TreeNode *> node;
	};

public:
	Trie()
	{
		root = new TreeNode();
		m_vowel = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
	}

	void insert(const string &str, int index)
	{
		TreeNode *tmp = root;
		for (auto c : str)
		{
			if (tmp->node.find(c) == tmp->node.end())
				tmp->node[c] = new TreeNode();
			tmp = tmp->node[c];
		}
		if (tmp->index == -1)
			tmp->index = index;
	}

	int search(const string &str)
	{
		TreeNode *tmp = root;
		for (auto c : str)
		{
			if (tmp->node.find(c) == tmp->node.end())
				return -1;
			tmp = tmp->node[c];
		}
		return tmp->index;
	}

	int caseInsensitiveSearch(const string &str)
	{
		int res = INT_MAX;
		caseInsensitiveSearch(str, 0, root, res);
		if (res == INT_MAX)
			return -1;
		return res;
	}

	int vowelSearch(const string &str)
	{
		int res = INT_MAX;
		vowelSearch(str, 0, root, res);
		if (res == INT_MAX)
			return -1;
		return res;
	}

private:
	void caseInsensitiveSearch(const string &str, int index, TreeNode *root, int &res)
	{
		if (index >= (int)str.length())
		{
			if (root->index != -1)
				res = min(res, root->index);
			return;
		}
		char c = tolower(str[index]);
		if (root->node.find(c) != root->node.end())
			caseInsensitiveSearch(str, index + 1, root->node[c], res);
		c = toupper(c);
		if (root->node.find(c) != root->node.end())
			caseInsensitiveSearch(str, index + 1, root->node[c], res);
	}

	void vowelSearch(const string &str, int index, TreeNode *root, int &res)
	{
		if (index >= (int)str.length())
		{
			if (root->index != -1)
				res = min(res, root->index);
			return;
		}
		char c = str[index];
		if (m_vowel.find(c) == m_vowel.end())
		{
			c = tolower(c);
			if (root->node.find(c) != root->node.end())
				vowelSearch(str, index + 1, root->node[c], res);
			c = toupper(c);
			if (root->node.find(c) != root->node.end())
				vowelSearch(str, index + 1, root->node[c], res);
			return;
		}
		for (auto c : m_vowel)
		{
			if (root->node.find(c) != root->node.end())
				vowelSearch(str, index + 1, root->node[c], res);
		}
	}

	TreeNode *root;
	unordered_set<char> m_vowel;
};

class Solution
{
public:
	vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries)
	{
		vector<string> res;
		Trie trie;
		for (int i = 0; i < (int)wordlist.size(); i++)
			trie.insert(wordlist[i], i);
		for (auto &query : queries)
		{
			int index = trie.search(query);
			if (index != -1)
			{
				res.push_back(wordlist[index]);
				continue;
			}
			index = trie.caseInsensitiveSearch(query);
			if (index != -1)
			{
				res.push_back(wordlist[index]);
				continue;
			}
			index = trie.vowelSearch(query);
			if (index != -1)
				res.push_back(wordlist[index]);
			else
				res.push_back("");
		}
		return res;
	}
};