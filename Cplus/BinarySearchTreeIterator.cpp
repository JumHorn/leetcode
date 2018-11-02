#include<stack>
using namespace std;
//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
		node=end=root;
		s.push(node);
        while(node!=NULL&&node->left!=NULL)
		{
			node=node->left;
			s.push(node);
		} 
		while(end!=NULL)end=end->right;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return node!=end; 
    }

    /** @return the next smallest number */
    int next() {
        int res=node->val;
		s.pop();
		node=node->right;
		while(node!=NULL)
		{
			s.push(node);
			node=node->left;
		}
		if(s.empty())
			node=NULL;
		else
			node=s.top();
	   return res;	
    }
private:
	stack<TreeNode*> s;
	TreeNode* node;
	TreeNode* end;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
