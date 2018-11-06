#include<iostream>
#include<string>
#include<sstream>
#include<stack>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
		1
	2		3
	  4
E1E2NE4NNE3NN
*/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
		if(root==NULL)
			return "N";
		return "E"+to_string(root->val)+serialize(root->left)+serialize(root->right);	
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       	stringstream ss(data); 
		int value;
		char exist;
		ss>>exist;
		if(exist=='N')
			return NULL;
		ss>>value;
		TreeNode* node=new TreeNode(value);
		stack<TreeNode*> s;
		s.push(node);
		TreeNode* tmp;
		bool lr=true;
		ss>>exist;
		while(!ss.eof())
		{
			tmp=s.top();
			if(exist=='E')
			{
				ss>>value;
				if(lr)
				{
					tmp->left=new TreeNode(value);
					s.push(tmp->left);
				}
				else
				{
					tmp->right=new TreeNode(value);
					s.pop();
					s.push(tmp->right);
				}
				lr=true;
			}
			else
			{
				if(lr)
					lr=false;
				else
					s.pop();
			}
			ss>>exist;
		}
		return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
