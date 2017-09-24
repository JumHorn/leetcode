#include<iostream>
#include<stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
		if(t==NULL)
		{
			return true;
		}
		if(s==NULL)
		{
			return false;
		}
		stack<TreeNode*> treestack;
		TreeNode* node = s;
		while(node||!treestack.empty())
		{
			if(EqualTree(node,t))
			{
				return true;
			}
			treestack.push(node);
			node=node->left;
			while(!node&&!treestack.empty())
			{
				node=treestack.top();
				node=node->right;
				treestack.pop();
			}
		}
		return false;
    }
	bool EqualTree(TreeNode* s,TreeNode* t)
	{
		if(s==NULL&&t==NULL)
		{
			return true;
		}
		else if(s==NULL||t==NULL)
		{
			return false;
		}
		else if(s->val==t->val)
		{
			return EqualTree(s->left,t->left)&&EqualTree(s->right,t->right);
		}
		else
		{
			return false;
		}
	}
};
