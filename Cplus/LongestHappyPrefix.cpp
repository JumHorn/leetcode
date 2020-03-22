#include <string>
using namespace std;

class Trie
{
	struct TreeNode
	{
		TreeNode* node[26];
		TreeNode()
		{
			for (int i = 0; i < 26; i++)
				node[i] = NULL;
		}
	};
};

class Solution
{
public:
	string longestPrefix(string s)
	{
	}
};
