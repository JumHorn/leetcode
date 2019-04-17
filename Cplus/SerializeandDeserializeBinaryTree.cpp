#include<string>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
 		if(root==NULL)
	 		return "n";
		return to_string(root->val)+"|"+serialize(root->left)+"|"+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
		int tmp=0;
        return deserialize(data,tmp);
    }

	TreeNode* deserialize(const string& data,int& index)
	{
		if(data[index]=='n')
        {
            index+=2;
			return NULL;
        }
		int tmp=0;
		while(data[++tmp+index]!='|');
		TreeNode* root=new TreeNode(stoi(data.substr(index,tmp)));
		index=index+tmp+1;
		root->left=deserialize(data,index);
		root->right=deserialize(data,index);
		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
