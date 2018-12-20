#include<vector>
#include<list>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
		list<TreeNode*> nodes;
		getAllNodes(nodes,root);
		for(list<TreeNode*>::iterator iter=nodes.begin();iter!=nodes.end();iter++)
		{
			list<TreeNode*>::iterator it=iter,tmp=nodes.end();
			for(it++;it!=nodes.end();)
            {
				if(isSame(*it,*iter))
				{
				    tmp=iter;
					it=nodes.erase(it);
				}
                else
                    it++;
			}
            if(tmp!=nodes.end())
                res.push_back(*tmp);
		}
		return res;
    }

	bool isSame(TreeNode* n1,TreeNode* n2)
	{
		if(n1==NULL&&n2==NULL)
			return true;
		if(n1!=NULL&&n2!=NULL)
		{
			if(n1->val==n2->val)
				return isSame(n1->left,n2->left)&&isSame(n1->right,n2->right);
		}
		return false;
	}

	//dfs get all nodes
	void getAllNodes(list<TreeNode*>& nodes,TreeNode* root)
	{
		if(root==NULL)
			return;
		nodes.push_back(root);
		getAllNodes(nodes,root->left);
		getAllNodes(nodes,root->right);
	}
};
