#include <string>
#include <vector>
using namespace std;

//Trie
class Trie
{
	struct TreeNode
	{
		int count; //number of words ends with this node
		vector<TreeNode *> nodes;

		TreeNode() : count(0), nodes(26, nullptr) {}
	};

public:
	Trie()
	{
		root = new TreeNode();
	}

	/** Inserts a word into the trie. */
	void insert(const string &word)
	{
		TreeNode *node = root;
		for (int i = (int)word.length() - 1; i >= 0; --i)
		{
			int index = word[i] - 'a';
			if (node->nodes[index] == nullptr)
				node->nodes[index] = new TreeNode();
			node = node->nodes[index];
		}
		++node->count;
	}

	/** Returns if the word is in the trie. */
	bool search(const string &word) const
	{
		TreeNode *node = root;
		for (int i = (int)word.length() - 1; i >= 0; --i)
		{
			node = node->nodes[word[i] - 'a'];
			if (node == nullptr)
				return false;
			if (node->count > 0)
				return true;
		}
		return false;
	}

private:
	TreeNode *root;
};
/********end of Trie********/

class StreamChecker
{
public:
	StreamChecker(vector<string> &words)
	{
		for (auto &word : words)
			trie.insert(word);
	}

	bool query(char letter)
	{
		letters.push_back(letter);
		return trie.search(letters);
	}

private:
	Trie trie;
	string letters;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */