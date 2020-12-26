#include <queue>
#include <sstream>
#include <string>
using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
		queue<TreeNode *> q;
		q.push(root);
		string res;
		bool has_node = true;
		while (!q.empty() && has_node)
		{
			has_node = false;
			int size = q.size();
			while (--size >= 0)
			{
				TreeNode *node = q.front();
				q.pop();
				if (node == nullptr)
					res += "n,";
				else //node != nullptr
				{
					res += to_string(node->val) + ",";
					q.push(node->left);
					q.push(node->right);
					has_node = (has_node || root->left || root->right);
				}
			}
		}
		if (res.empty())
			res.pop_back();
		return res;
	}

	// Decodes your encoded data to tree.
	TreeNode *deserialize(string data)
	{
		stringstream ss(data);
		string token;
		getline(ss, token, ',');
		if (token == "n")
			return nullptr;
		TreeNode *root = new TreeNode(stoi(token));
		queue<TreeNode *> q;
		q.push(root);
		while (getline(ss, token, ','))
		{
			TreeNode *node = q.front();
			q.pop();
			if (token != "n")
			{
				node->left = new TreeNode(stoi(token));
				q.push(node->left);
			}
			getline(ss, token, ',');
			if (token != "n")
			{
				node->right = new TreeNode(stoi(token));
				q.push(node->right);
			}
		}
		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));