#include <climits>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec
{
public:
	// Encodes a tree to a single string.
	string serialize(TreeNode *root)
	{
		if (root == nullptr)
			return "";
		return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
	}

	// Decodes your encoded data to tree.
	TreeNode *deserialize(string data)
	{
		stringstream ss(data);
		vector<int> arr;
		int val = 0;
		char delimiter;
		while (ss >> val)
		{
			ss >> delimiter; //ignore .
			arr.push_back(val);
		}
		val = 0;
		return deserialize(arr, val, INT_MIN, INT_MAX);
	}

	TreeNode *deserialize(vector<int> &data, int &index, int lower, int upper)
	{
		if (index >= (int)data.size() || data[index] < lower || data[index] > upper)
			return nullptr;
		int val = data[index++];
		TreeNode *root = new TreeNode(val);
		root->left = deserialize(data, index, lower, val);
		root->right = deserialize(data, index, val, upper);
		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));