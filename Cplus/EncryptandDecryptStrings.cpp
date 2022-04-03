#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct TrieNode
{
	int count; //number of words ends with this node
	vector<TrieNode *> nodes;

	TrieNode() : count(0), nodes(26, nullptr) {}
};

//Trie
class Trie
{

public:
	Trie()
	{
		root = new TrieNode();
	}

	/** Inserts a word into the trie. */
	void insert(const string &word)
	{
		TrieNode *node = root;
		for (auto c : word)
		{
			int index = c - 'a';
			if (node->nodes[index] == nullptr)
				node->nodes[index] = new TrieNode();
			node = node->nodes[index];
		}
		++node->count;
	}

	/** Returns if the word is in the trie. */
	bool search(const string &word) const
	{
		TrieNode *node = searchNode(word);
		return node != nullptr && node->count > 0;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(const string &prefix)
	{
		TrieNode *node = searchNode(prefix);
		return node != nullptr;
	}

	TrieNode *searchNode(const string &str) const
	{
		TrieNode *node = root;
		for (auto c : str)
		{
			int index = c - 'a';
			if (node->nodes[index] == nullptr)
				return nullptr;
			node = node->nodes[index];
		}
		return node;
	}

	TrieNode *searchNode(TrieNode *node, char c)
	{
		if (node == nullptr)
			return nullptr;
		return node->nodes[c - 'a'];
	}

	TrieNode *getRoot()
	{
		return root;
	}

private:
	TrieNode *root;
};
/********end of Trie********/

class Encrypter
{
public:
	Encrypter(vector<char> &keys, vector<string> &values, vector<string> &dictionary)
	{
		enc = vector<string>(26);
		for (int i = 0; i < 26; ++i)
			enc[i] = string(1, 'a' + i);
		int N = keys.size();
		for (int i = 0; i < N; ++i)
		{
			enc[keys[i] - 'a'] = values[i];
			dec[values[i]].push_back(keys[i]);
		}
		for (auto &str : dictionary)
			trie.insert(str);
	}

	string encrypt(string word1)
	{
		string res;
		for (auto c : word1)
			res += enc[c - 'a'];
		return res;
	}

	int decrypt(string word2)
	{
		string d;
		return dfs(word2, 0, d, trie.getRoot());
	}

	int dfs(string &word2, int index, string &d, TrieNode *node)
	{
		int N = word2.length();
		if (index >= N)
		{
			if (node != nullptr && node->count > 0)
				return 1;
			return 0;
		}

		auto it = dec.find(word2.substr(index, 2));
		if (it == dec.end())
			return 0;

		int res = 0;
		for (auto c : it->second)
		{
			d.push_back(c);
			//early prune
			TrieNode *nextnode = node->nodes[c - 'a'];
			if (nextnode != nullptr)
				res += dfs(word2, index + 2, d, nextnode);
			d.pop_back();
		}
		return res;
	}

private:
	// set<string> dict;
	Trie trie;
	vector<string> enc;
	unordered_map<string, string> dec;
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */