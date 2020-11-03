#include <string>
#include <vector>
using namespace std;

class StreamChecker
{
private:
	struct TreeNode
	{
		int count;
		TreeNode *node[26];
		TreeNode() : count(0)
		{
			for (int i = 0; i < 26; ++i)
				node[i] = NULL;
		}
	};

	TreeNode *root;
	vector<char> letters;

	void insert(const string &str)
	{
		TreeNode *tmp = root;
		for (int i = str.length() - 1; i >= 0; i--)
		{
			if (tmp->node[str[i] - 'a'] == NULL)
				tmp->node[str[i] - 'a'] = new TreeNode();
			tmp = tmp->node[str[i] - 'a'];
		}
		++tmp->count;
	}

	bool search()
	{
		TreeNode *tmp = root;
		for (int i = letters.size() - 1; i >= 0; i--)
		{
			tmp = tmp->node[letters[i] - 'a'];
			if (tmp == NULL)
				return false;
			if (tmp->count > 0)
				return true;
		}
		return false;
	}

public:
	StreamChecker(vector<string> &words)
	{
		root = new TreeNode();
		for (int i = 0; i < (int)words.size(); ++i)
			insert(words[i]);
	}

	bool query(char letter)
	{
		letters.push_back(letter);
		return search();
	}
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */