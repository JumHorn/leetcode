#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

//definiton of trie
struct Trie
{
	bool isfolder;
	unordered_map<char, Trie*> node;
	Trie(bool val = false) : isfolder(val) {}
};

class Solution
{
public:
	vector<string> removeSubfolders(vector<string>& folder)
	{
		root = new Trie();
		for (auto& n : folder)
			insertFolder(n);
		//removeFolder(root);
		vector<string> res;
		string tmp;
		generateFolder(res, tmp, root);
		return res;
	}

	void generateFolder(vector<string>& res, string& tmp, Trie* root)
	{
		if (root == NULL)
			return;
		if (root->isfolder)
		{
			res.push_back(tmp);
			root->node.erase('/');
		}
		for (auto& iter : root->node)
		{
			tmp.push_back(iter.first);
			generateFolder(res, tmp, iter.second);
			tmp.pop_back();
		}
	}

	void removeFolder(Trie* root)
	{
		if (root == NULL)
			return;
		if (root->isfolder)
			root->node.erase('/');
		for (auto& iter : root->node)
			removeFolder(iter.second);
	}

	void insertFolder(const string& folder)
	{
		Trie* tmp = root;
		for (auto n : folder)
		{
			if (tmp->node.find(n) == tmp->node.end())
				tmp->node[n] = new Trie();
			tmp = tmp->node[n];
		}
		tmp->isfolder = true;
	}

private:
	Trie* root;
};
