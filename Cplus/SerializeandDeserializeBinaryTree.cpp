#include <string>
#include <deque>
#include <queue>
using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
leetcode json format tree serialize/deserialize
*/

class Codec
{
public:
	// Encodes a tree to a single string.
	string serialize(TreeNode *root)
	{
		deque<TreeNode *> q;
		q.push_back(root);
		string res;
		bool flag = true;
		while (!q.empty() && flag)
		{
			flag = false;
			int size = q.size();
			while (--size >= 0)
			{
				TreeNode *node = q.front();
				q.pop_front();
				if (node == NULL)
				{
					res += ",n";
					continue;
				}
				res += "," + to_string(node->val);
				q.push_back(node->left);
				q.push_back(node->right);
				if (node->left || node->right)
					flag = true;
			}
		}
		return res.substr(1);
	}

	// Decodes your encoded data to tree.
	TreeNode *deserialize(string data)
	{
		if (data[0] == 'n')
			return NULL;
		int n = data.length(), index = 0, tmp = 0;
		while (tmp < n && data[tmp] != ',')
			tmp++;
		TreeNode *root = new TreeNode(stoi(data.substr(index, tmp - index)));
		queue<TreeNode *> q;
		q.push(root);
		index = tmp + 1;
		while (index < n)
		{
			TreeNode *node = q.front();
			q.pop();
			tmp = index;
			while (tmp < n && data[tmp] != ',')
				tmp++;
			if (index < n && data[index] != 'n')
			{
				node->left = new TreeNode(stoi(data.substr(index, tmp - index)));
				q.push(node->left);
			}
			index = tmp + 1;

			tmp = index;
			while (tmp < n && data[tmp] != ',')
				tmp++;
			if (index < n && data[index] != 'n')
			{
				node->right = new TreeNode(stoi(data.substr(index, tmp - index)));
				q.push(node->right);
			}
			index = tmp + 1;
		}
		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));