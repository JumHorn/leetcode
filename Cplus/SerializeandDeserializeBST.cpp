#include <sstream>
#include <stack>
#include <string>
using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
	// Encodes a tree to a single string.
	string serialize(TreeNode *root)
	{
		if (root == NULL)
			return "N";
		return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
	}

	// Decodes your encoded data to tree.
	TreeNode *deserialize(string data)
	{
		stringstream ss(data);
		return deserialize(ss);
	}

	TreeNode *deserialize(stringstream &data)
	{
		int val;
		char dot;
		if (data.peek() == 'N')
		{
			data >> dot >> dot;
			return nullptr;
		}
		data >> val;
		data >> dot; //ignore .
		TreeNode *root = new TreeNode(val);
		root->left = deserialize(data);
		root->right = deserialize(data);
		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));