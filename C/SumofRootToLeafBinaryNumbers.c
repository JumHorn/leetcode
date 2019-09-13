
//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfs(struct TreeNode* root,int val,int* res)
{
	if(!root->left&&!root->right)
		*res+=(val<<1)|root->val;
	if(root->left)
		dfs(root->left,(val<<1)|root->val,res);
	if(root->right)
		dfs(root->right,(val<<1)|root->val,res);
}

int sumRootToLeaf(struct TreeNode* root){
	if(!root)
		return 0;
	int res=0;
	dfs(root,0,&res);
	return res;
}
